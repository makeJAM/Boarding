# Pointer Fundamentals

- [Pointer Fundamentals](#pointer-fundamentals)
  - [Pointers in C & C ++](#pointers-in-c--c)
  - [Pointer declarations](#pointer-declarations)
  - [C pointers](#c-pointers)
  - [Basic Usage of Pointer](#basic-usage-of-pointer)
    - [Pass by address](#pass-by-address)
    - [C Arrays](#c-arrays)
    - [C Linked List](#c-linked-list)
    - [Dynamic memory allocation](#dynamic-memory-allocation)
    - [Typed pointers and casting](#typed-pointers-and-casting)

In computer science, a pointer is a programming language object that stores the
memory address of another value located in computer memory. A pointer references a
location in memory, and obtaining the value stored at that location is known as
dereferencing the pointer. As an analogy, a page number in a book's index could be
considered a pointer to the corresponding page; dereferencing such a pointer would be
done by flipping to the page with the given page number and reading the text found on
that page. The actual format and content of a pointer variable is dependent on the
underlying computer architecture.

Using pointers significantly improves performance for repetitive operations like
traversing iterable data structures, e.g. strings, lookup tables, control tables and
tree structures. In particular, it is often much cheaper in time and space to copy
and dereference pointers than it is to copy and access the data to which the pointers
point.

Pointers are also used to hold the addresses of entry points for called subroutines
in procedural programming and for run-time linking to dynamic link libraries (DLLs).
In object-oriented programming, pointers to functions are used for binding methods,
often using what are called virtual method tables.

A pointer is a simple, more concrete implementation of the more abstract reference
data type. Several languages, especially low-level languages support some type of
pointer, although some have more restrictions on their use than others. While
"pointer" has been used to refer to references in general, it more properly applies
to data structures whose interface explicitly allows the pointer to be manipulated
(arithmetically via pointer arithmetic) as a memory address, as opposed to a magic
cookie or capability which does not allow such.[citation needed] Because pointers
allow both protected and unprotected access to memory addresses, there are risks
associated with using them, particularly in the latter case. Primitive pointers are
often stored in a format similar to an integer; however, attempting to dereference or
"look up" such a pointer whose value is not a valid memory address will cause a
program to crash. To alleviate this potential problem, as a matter of type safety,
pointers are considered a separate type parameterized by the type of data they point
to, even if the underlying representation is an integer. Other measures may also be
taken (such as validation & bounds checking), to verify that the pointer variable
contains a value that is both a valid memory address and within the numerical range
that the processor is capable of addressing.

## Pointers in C & C ++

In C and C++ pointers are variables that store addresses and can be null. Each
pointer has a type it points to, but one can freely cast between pointer types (but
not between a function pointer and an object pointer). A special pointer type called
the “void pointer” allows pointing to any (non-function) object, but is limited by
the fact that it cannot be dereferenced directly (it shall be cast). The address
itself can often be directly manipulated by casting a pointer to and from an integral
type of sufficient size, though the results are implementation-defined and may indeed
cause undefined behavior; while earlier C standards did not have an integral type
that was guaranteed to be large enough, C99 specifies the uintptr_t typedef name
defined in <stdint.h>, but an implementation need not provide it.

C++ fully supports C pointers and C typecasting. It also supports a new group of
typecasting operators to help catch some unintended dangerous casts at compile-time.
Since C++11, the C++ standard library also provides smart pointers (unique_ptr,
shared_ptr and weak_ptr) which can be used in some situations as a safer alternative
to primitive C pointers. C++ also supports another form of reference, quite different
from a pointer, called simply a reference or reference type.

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

The void pointer, or void*, is supported in ANSI C and C++ as a generic pointer type.
A pointer to void can store the address of any object (not function), and, in C, is
implicitly converted to any other object pointer type on assignment, but it must be
explicitly cast if dereferenced. K&R C used char* for the “type-agnostic pointer”
purpose (before ANSI C).

## Pointer declarations

These pointer declarations cover most variants of pointer declarations. Of course it
is possible to have triple pointers, but the main principles behind a triple pointer
already exist in a double pointer.

```c
char cff [5][5];    /* array of arrays of chars */
char *cfp [5];      /* array of pointers to chars */
char **cpp;         /* pointer to pointer to char ("double pointer") */
char (*cpf) [5];    /* pointer to array(s) of chars */
char *cpF();        /* function which returns a pointer to char(s) */
char (*CFp)();      /* pointer to a function which returns a char */
char (*cfpF())[5];  /* function which returns pointer to an array of chars */
char (*cpFf[5])();  /* an array of pointers to functions which return a char */
```

The () and [] have a higher priority than *.

## C pointers

The basic syntax to define a pointer is:

```c
int *ptr;
```

This declares ptr as the identifier of an object of the following type:

- pointer that points to an object of type int

This is usually stated more succinctly as "ptr is a pointer to int."

Because the C language does not specify an implicit initialization for objects of automatic storage
duration,[5] care should often be taken to ensure that the address to which ptr points is valid; this is
why it is sometimes suggested that a pointer be explicitly initialized to the null pointer value, which
is traditionally specified in C with the standardized macro NULL:

```c
int *ptr = NULL;
```

Dereferencing a null pointer in C produces undefined behavior, which could be catastrophic. However,
most implementations[citation needed] simply halt execution of the program in question, usually with a
segmentation fault.

However, initializing pointers unnecessarily could hinder program analysis, thereby hiding bugs.

In any case, once a pointer has been declared, the next logical step is for it to point at something:

```c
int a = 5;
int *ptr = NULL;

ptr = &a;
```

This assigns the value of the address of a to ptr. For example, if a is stored at memory location of
0x8130 then the value of ptr will be 0x8130 after the assignment. To dereference the pointer, an
asterisk is used again:

```c
*ptr = 8;
```

This means take the contents of ptr (which is 0x8130), "locate" that address in memory and set its value
to 8. If a is later accessed again, its new value will be 8.

This example may be clearer if memory is examined directly. Assume that a is located at address 0x8130
in memory and ptr at 0x8134; also assume this is a 32-bit machine such that an int is 32-bits wide. The
following is what would be in memory after the following code snippet is executed:

```c
int a = 5;
int *ptr = NULL;
```

|ADDRESS  |CONTENTS |
|---------|---------|
|0x8130     |0x00000005|
|0x8134     |0x00000000|

(The NULL pointer shown here is 0x00000000.) By assigning the address of a to ptr:

```C
ptr = &a;
```

yields the following memory values:

|ADDRESS  |CONTENTS |
|---------|---------|
|0x8130     |0x00000005|
|0x8134     |0x00008130|

Then by dereferencing ptr by coding:

```C
*ptr = 8;
```

the computer will take the contents of ptr (which is 0x8130), 'locate' that address, and assign 8 to
that location yielding the following memory:

|ADDRESS  |CONTENTS |
|---------|---------|
|0x8130     |0x00000008|
|0x8134     |0x00008130|

Clearly, accessing a will yield the value of 8 because the previous instruction modified the contents of
a by way of the pointer ptr.

## Basic Usage of Pointer

### Pass by address

Pointers can be used to pass variables by their address, allowing their value to be
changed. For example, consider the following C code:

```c
/* a copy of the int n can be changed within the function without affecting the
calling code */
void passByValue(int n) {
    n = 12;
}

/* a pointer m is passed instead. No copy of the value pointed to by m is created */
void passByAddress(int *m) {
    *m = 14;
}

int main(void) {
    int x = 3;

    /* pass a copy of x's value as the argument */
    passByValue(x);
    // the value was changed inside the function, but x is still 3 from here on

    /* pass x's address as the argument */
    passByAddress(&x);
    // x was actually changed by the function and is now equal to 14 here

    return 0;
}
```

### C Arrays

In C, array indexing is formally defined in terms of pointer arithmetic; that is, the
language specification requires that array[i] be equivalent to *(array + i).[8] Thus
in C, arrays can be thought of as pointers to consecutive areas of memory (with no
gaps),[8] and the syntax for accessing arrays is identical for that which can be used
to dereference pointers. For example, an array array can be declared and used in the
following manner:

```c
int array[5];      /* Declares 5 contiguous integers */
int *ptr = array;  /* Arrays can be used as pointers */
ptr[0] = 1;        /* Pointers can be indexed with array syntax */
*(array + 1) = 2;  /* Arrays can be dereferenced with pointer syntax */
*(1 + array) = 2;  /* Pointer addition is commutative */
2[array] = 4;      /* Subscript operator is commutative */
```

This allocates a block of five integers and names the block array, which acts as a
pointer to the block. Another common use of pointers is to point to dynamically
allocated memory from malloc which returns a consecutive block of memory of no less
than the requested size that can be used as an array.

While most operators on arrays and pointers are equivalent, the result of the sizeof
operator differs. In this example, sizeof(array) will evaluate to 5*sizeof(int) (the
size of the array), while sizeof(ptr) will evaluate to sizeof(int*), the size of the
pointer itself.

Default values of an array can be declared like:

```c
int array[5] = {2, 4, 3, 1, 5};
```

If array is located in memory starting at address 0x1000 on a 32-bit little-endian
machine then memory will contain the following (values are in hexadecimal, like the
addresses):

|         |0  |1  |2  |3  |
|---------|---------|---------|---------|---------|
|1000     |     2    |    0     |      0   |     0    |
|1004     |     4    |     0    |     0    |     0    |
|1008     |     3    |     0    |      0   |      0   |
|100C     |     1    |   0      |    0     |      0   |
|1010     |    5     |    0     |     0    |    0     |

Represented here are five integers: 2, 4, 3, 1, and 5. These five integers occupy 32
bits (4 bytes) each with the least-significant byte stored first (this is a
little-endian CPU architecture) and are stored consecutively starting at address
0x1000.

The syntax for C with pointers is:

- array means 0x1000;
- array + 1 means 0x1004: the "+ 1" means to add the size of 1 int, which is 4 bytes;
- *array means to dereference the contents of array. Considering the contents as a
  memory address (0x1000), look up the value at that location (0x0002);
- array[i] means element number i, 0-based, of array which is translated into *(array + i).

The last example is how to access the contents of array. Breaking it down:

- array + i is the memory location of the (i)th element of array, starting at i=0;
- *(array + i) takes that memory address and dereferences it to access the value.

### C Linked List

Below is an example definition of a linked list in C.

```c
/* the empty linked list is represented by NULL
 * or some other sentinel value */
#define EMPTY_LIST  NULL

struct link {
    void        *data;  /* data of this link */
    struct link *next;  /* next link; EMPTY_LIST if there is none */
};
```

This pointer-recursive definition is essentially the same as the reference-recursive
definition from the Haskell programming language:

```c
 data Link a = Nil
             | Cons a (Link a)
```

Nil is the empty list, and Cons a (Link a) is a cons cell of type a with another link
also of type a.

The definition with references, however, is type-checked and does not use potentially
confusing signal values. For this reason, data structures in C are usually dealt with
via wrapper functions, which are carefully checked for correctness.

### Dynamic memory allocation

In some programs, the required memory depends on what the user may enter. In such
cases the programmer needs to allocate memory dynamically. This is done by allocating
memory at the heap rather than on the stack, where variables usually are stored.
(Variables can also be stored in the CPU registers, but that's another matter)
Dynamic memory allocation can only be made through pointers, and names (like with
common variables) can't be given.

Pointers are used to store and manage the addresses of dynamically allocated blocks
of memory. Such blocks are used to store data objects or arrays of objects. Most
structured and object-oriented languages provide an area of memory, called the heap
or free store, from which objects are dynamically allocated.

The example C code below illustrates how structure objects are dynamically allocated
and referenced. The standard C library provides the function malloc() for allocating
memory blocks from the heap. It takes the size of an object to allocate as a
parameter and returns a pointer to a newly allocated block of memory suitable for
storing the object, or it returns a null pointer if the allocation failed.

```c
/* Parts inventory item */
struct Item {
    int         id;     /* Part number */
    char *      name;   /* Part name   */
    float       cost;   /* Cost        */
};

/* Allocate and initialize a new Item object */
struct Item * make_item(const char *name) {
    struct Item * item;

    /* Allocate a block of memory for a new Item object */
    item = malloc(sizeof(struct Item));
    if (item == NULL)
        return NULL;

    /* Initialize the members of the new Item */
    memset(item, 0, sizeof(struct Item));
    item->id =   -1;
    item->name = NULL;
    item->cost = 0.0;

    /* Save a copy of the name in the new Item */
    item->name = malloc(strlen(name) + 1);
    if (item->name == NULL) {
        free(item);
        return NULL;
    }
    strcpy(item->name, name);

    /* Return the newly created Item object */
    return item;
}
```

The code below illustrates how memory objects are dynamically deallocated, i.e.,
returned to the heap or free store. The standard C library provides the function free
() for deallocating a previously allocated memory block and returning it back to the
heap.

```c
/* Deallocate an Item object */
void destroy_item(struct Item *item) {
    /* Check for a null object pointer */
    if (item == NULL)
        return;

    /* Deallocate the name string saved within the Item */
    if (item->name != NULL) {
        free(item->name);
        item->name = NULL;
    }

    /* Deallocate the Item object itself */
    free(item);
}
```

### Typed pointers and casting

In many languages, pointers have the additional restriction that the object they
point to has a specific type. For example, a pointer may be declared to point to an
integer; the language will then attempt to prevent the programmer from pointing it to
objects which are not integers, such as floating-point numbers, eliminating some
errors.

For example, in C

```c
int *money;
char *bags;
```

money would be an integer pointer and bags would be a char pointer. The following
would yield a compiler warning of "assignment from incompatible pointer type" under
GCC

```c
bags = money;
```

because money and bags were declared with different types. To suppress the compiler
warning, it must be made explicit that you do indeed wish to make the assignment by
typecasting it

```c
bags = (char *)money;
```

which says to cast the integer pointer of money to a char pointer and assign to bags.

A 2005 draft of the C standard requires that casting a pointer derived from one type
to one of another type should maintain the alignment correctness for both types
(6.3.2.3 Pointers, par. 7)

```c
char *external_buffer = "abcdef";
int *internal_data;

internal_data = (int *)external_buffer;  // UNDEFINED BEHAVIOUR if "the resulting pointer
                                         // is not correctly aligned"
```

In languages that allow pointer arithmetic, arithmetic on pointers takes into account
the size of the type. For example, adding an integer number to a pointer produces
another pointer that points to an address that is higher by that number times the
size of the type. This allows us to easily compute the address of elements of an
array of a given type, as was shown in the C arrays example above. When a pointer of
one type is cast to another type of a different size, the programmer should expect
that pointer arithmetic will be calculated differently. In C, for example, if the
money array starts at 0x2000 and sizeof(int) is 4 bytes whereas sizeof(char) is 1
byte, then money + 1 will point to 0x2004, but bags + '1' would point to 0x2001.
Other risks of casting include loss of data when "wide" data is written to "narrow"
locations (e.g. bags[0] = 65537;), unexpected results when bit-shifting values, and
comparison problems, especially with signed vs unsigned values.

Although it is impossible in general to determine at compile-time which casts are
safe, some languages store run-time type information which can be used to confirm
that these dangerous casts are valid at runtime. Other languages merely accept a
conservative approximation of safe casts, or none at all.
