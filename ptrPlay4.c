#include <stdlib.h>

int func2(char* b, char c, int d)
{
    int x;
    x = d;
    x = x * x;
    return x;
}

int main(int argc, char* argv)
{
    int x = 0;
    x = func2("Hello", 'a', 10);
}