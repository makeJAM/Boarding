# Pointer Arithmetic

Pointer arithmetic, that is, the ability to modify a pointer's target address with
arithmetic operations (as well as magnitude comparisons), is restricted by the
language standard to remain within the bounds of a single array object (or just after
it), and will otherwise invoke undefined behavior. Adding or subtracting from a
pointer moves it by a multiple of the size of its datatype. For example, adding 1 to
a pointer to 4-byte integer values will increment the pointer's pointed-to
byte-address by 4. This has the effect of incrementing the pointer to point at the
next element in a contiguous array of integers—which is often the intended result.
Pointer arithmetic cannot be performed on void pointers because the void type has no
size, and thus the pointed address can not be added to, although gcc and other
compilers will perform byte arithmetic on void* as a non-standard extension, treating
it as if it were char *.

Pointer arithmetic provides the programmer with a single way of dealing with
different types: adding and subtracting the number of elements required instead of
the actual offset in bytes. (Pointer arithmetic with char * pointers uses byte
offsets, because sizeof(char) is 1 by definition.) In particular, the C definition
explicitly declares that the syntax a[n], which is the n-th element of the array a,
is equivalent to *(a + n), which is the content of the element pointed by a + n. This
implies that n[a] is equivalent to a[n], and one can write, e.g., a[3] or 3[a]
equally well to access the fourth element of an array a.

While powerful, pointer arithmetic can be a source of computer bugs. It tends to
confuse novice programmers, forcing them into different contexts: an expression can
be an ordinary arithmetic one or a pointer arithmetic one, and sometimes it is easy
to mistake one for the other. In response to this, many modern high-level computer
languages (for example Java) do not permit direct access to memory using addresses.
Also, the safe C dialect Cyclone addresses many of the issues with pointers. See C
programming language for more discussion.

## Operators

```txt
+ +
- -
-
+
```

no division or multiplication

## Incrementing a Pointer with (++)

Just like any variable the ++ operation increases the value of that variable. In our
case here the variable is a pointer hence when we increase its value we are
increasing the address in the memory that pointer points to. Let's combine this
operation with an array in our example:

```c
#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    return 0;
}
```

## Decreasing a Pointer with (--)

Just like in our previous example we increased the pointer's pointed-to address by
one using the ++ operator, we can decrease the address pointed-to by one using the
decrement operator (--).

```c
#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    return 0;
}
```

## Adding Pointers with (+)

We previously increased a pointer's pointed-to address by one. We can also increase
it by an integer value such:

```c
#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the addres of the 4th element

    return 0;
}
```

Note how in the output the address shifted by 8 steps in the memory. You might be
wondering why? The answer is simple: Because our pointer is an int-pointer and the
size of an int variable is 4 bytes the memory is shift-able by 4 blocks. In our code
we shifted by 2 (added +2) to the initial address so that makes them 2 x 4 byte = 8.

## Subtracting Pointers with (-)

Similarly we can subtract:

```c
#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3rd element

    return 0;
}
```

again the address is shifted by blocks of 4bytes (in case of int).

## Other Operations

There are more operations such as comparison >, <, ==. The idea is very similar of
comparing variables, but in this case we are comparing memory address.
