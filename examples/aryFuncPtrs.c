/*
Defining an array of function pointers is a little bit cryptic in nature.
It takes a generic form, which is explained below. We can use an array of 
function pointers for functions that have the same return types and the number 
of input parameters is equal and of the same type.

<return type of function being pointed> (*functionpointervariable [])
(input parameters pointed by function being pointed to)
*/

/*
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);

int (* opfunctptr [ ] ) ( int x, int y) = { add, sub, mul, div };

opfunctptr[ 0 ] ( 10 , 20 ); // This invokes the function add
*/


/*
int add(int , int );  //function to be pointed  to by the function pointer
//function returning the result after adding the values of two parameters
int (*addfuncptr)(int, int);
 //function pointer, capable of pointing to the above function int add(int,int)
*/

/*
typedef int(* addfuncptr)(int p1, int p2);

addfuncptr funcptrret(void)
*/
#include <stdio.h>

int myadd( int a, int b)
{
    int z = a + b;
    return z;
}
int mysub(int a, int b)
{
    int z = a - b;
    return z;
}
int mymul(int a, int b)
{
    int z = a*b;
    return z;
}
int mydiv(int a, int b)
{
    int z = a/b;
    return z;
}
//array of function pointers,
int (* opfunctptr [ ] ) ( int x, int y) = { myadd, mysub, mymul, mydiv };
typedef int (*calc)(int x, int y );
//function returning the function pointer of type int (*calc)(int x, int y )
calc retmathfunc(int index)
{
    return opfunctptr[index];
}
int main(int argc, char* argv[])
{
    int choice, p1, p2, res;
    int (*calculator)(int x, int y);
    printf("Type -1 to quit\n");
    printf("Type:\n 0 - add\n, 1 - sub\n, 2 - mul\n, 3 - div\n");
    scanf("%d", &choice);
    while( choice != -1)
    {
      calculator = retmathfunc(choice); //returns function pointer
      printf("Param1\n");
      scanf("%d", &p1);
      printf("Param2\n");
      scanf("%d", &p2);
      res = calculator(p1, p2);         //calling function pointer
      printf("res = %d\n", res);
      printf("Type:\n 0 - add\n, 1 - sub\n, 2 - mul\n, 3 - div\n");
      scanf("%d", &choice);
    }
    return 0;
}

/*
Function: int add(int x, int y);
Function ptr: int (*addfptr)(int x, int y);

Function: int* add(int x, int y);
Function ptr: int* (*addfptr)(int x, int y);

Function: int add(int x, int y);
Function ptr: int (*addfptr)(int x, int y);
Function whose input parameter is a function pointer as above and return type is void:  void callfunc(int (*addfptr)(int x, int y));

Function: int add(int x, int y);
Function ptr: int (*addfptr)(int x, int y);
Pointer to a function pointer to a function returning int: int (*(*addfptr))(int x, int y);

Function: int add(int x, int y);
Function ptr: int (*addfptr)(int x, int y);
Function whose input parameter is void and return type is function pointer: int (*retfuncptr(void)(int x, int y );

Function: int* add(int x, int y);
function ptr: int* (*addfptr)(int x, int y);
function whose input parameter is void and return type is function pointer: int* (*retfuncptr(void)(int x, int y);
*/