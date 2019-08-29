# Double Pointers

```c
int** ptr;      //declaring double pointers
```

```c
int a = 10;
int *ptr = &a;
```

```c
int a = 10;
// variable a is data type int equals 10
int* ptr = &a;
// variable ptr is a pointer that equals the data stored at the address of variable a
int** ptr1 = &ptr;
// variable ptr1 is a pointer to a pointer that is type int. ptr1 stores the address of ptr.
```

|Varname/Addr|Value|Varname/addr|Value|
|---------|---------|---------|---------|
|||val/0x0001|10|
|ptrvar/0x0005|0x0001|||

## pointers

__________

```graphviz
digraph doubleptr{
    rank=LR;
    node [shape = rectangle];mem_addr;
    node [shape = rectangle];_0x123456;
    node [shape = rectangle];_0x111122;
    node [shape = rectangle];_0x111123;
}
