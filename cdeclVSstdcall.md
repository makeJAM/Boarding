# CDECL VS STDCALL

## CDECL

The cdecl (which stands for C declaration) is a calling convention that originates
from the C programming language and is used by many C compilers for the x86
architecture. In cdecl, subroutine arguments are passed on the stack. Integer values
and memory addresses are returned in the EAX register, floating point values in the
ST0 x87 register. Registers EAX, ECX, and EDX are caller-saved, and the rest are
callee-saved. The x87 floating point registers ST0 to ST7 must be empty (popped or
freed) when calling a new function, and ST1 to ST7 must be empty on exiting a
function. ST0 must also be empty when not used for returning a value.

In the context of the C programming language, function arguments are pushed on the
stack in the right-to-left order, i.e. the last argument is pushed first. In Linux,
GCC sets the de facto standard for calling conventions. Since GCC version 4.5, the
stack must be aligned to a 16-byte boundary when calling a function previous
versions only required a 4-byte alignment.

```c
int callee(int, int, int);

int caller(void)
{
    return callee(1, 2, 3) + 5;
}
```

```asm
caller:
                    ; make new call frame
                    ; (some compilers may produce an 'enter' instruction instead)

push    ebp         ; save old call frame
mov     ebp, esp    ; initialize new call frame

                    ; push call arguments, in reverse
                    ; (some compilers may subtract the required space from the stack pointer,
                    ; then write each argument directly, see below.
                    ; The 'enter' instruction can also do something similar)
                    ; sub esp, 12      : 'enter' instruction could do this for us
                    ; mov [ebp-4], 3   : or mov [esp+8], 3
                    ; mov [ebp-8], 2   : or mov [esp+4], 2
                    ; mov [ebp-12], 1  : or mov [esp], 1

push    3
push    2
push    1
call    callee      ; call subroutine 'callee'
add     eax, 5      ; modify subroutine result

                    ; (eax is the return value of our callee,
                    ; so we don't have to move it into a local variable)

                    ; restore old call frame
                    ; (some compilers may produce a 'leave' instruction instead)
add   esp, 12       ; remove arguments from frame, ebp - esp = 12.

                    ; compilers will usually produce the following instead,
                    ; which is just as fast, and, unlike the add instruction,
                    ; also works for variable length arguments
                    ; and variable length arrays allocated on the stack.

mov     esp, ebp    ; most calling conventions dictate ebp be callee-saved,

                    ; i.e. its preserved after calling the callee.
                    ; it therefore still points to the start of our stack frame.
                    ; we do need to make sure
                    ; callee doesn't modify (or restores) ebp, though,
                    ; so we need to make sure
                    ; it uses a calling convention which does this

pop     ebp         ; restore old call frame
ret                 ; return
```

## STDCALL

The stdcall calling convention is a variation on the Pascal calling convention in
which the callee is responsible for cleaning up the stack, but the parameters are
pushed onto the stack in right-to-left order, as in the _cdecl calling convention.
Registers EAX, ECX, and EDX are designated for use within the function. Return
values are stored in the EAX register. Stdcall is the standard calling convention
for the Microsoft Win32 API and for Open Watcom C++.
