# CASTING

2 types implicit and explicit

## IMPLICIT TYPE CONVERSION

Also known as ‘automatic type conversion’.

Done by the compiler on its own, without any external trigger from the user.
Generally takes place when in an expression more than one data type is present. In
such condition type conversion (type promotion) takes place to avoid lose of data.
All the data types of the variables are upgraded to the data type of the variable
with largest data type.

## EXPLICIT TYPE CONVERSION

AKA type casting

is user defined

```c
(type) expression
```

type indicated the data type to which the final result is converted.

```c
// C program to demonstrate explicit type casting
#include<stdio.h>

int main()
{
    double x = 1.2;
    // Explicit conversion from double to int
    int sum = (int)x + 1;
    printf("sum = %d", sum);
    return 0;
    }

```
