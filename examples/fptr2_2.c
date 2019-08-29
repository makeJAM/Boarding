#include <stdlib.h>
#include <stdio.h>

int add( int a, int b)
{
    int z = a + b;
    return z;
}

int main(int argc, char* argv[])
{
    int z = add(10,20);
    int (*funcptr)(int x, int y) = add;
    funcptr(10,20);
    
    printf("%d\n", z);

    return 0;
}