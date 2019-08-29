#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define BUFFER 5

int write_str2file()
{
    FILE* fp = NULL;
    int res;
    char* buffer;
    size_t bufsize = 32;
    size_t characters;
    size_t filename;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( fp == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    printf("Enter file name: ");
    filename = getline(&buffer, &bufsize, stdin);

    printf("Enter string to store: ");
    characters = getline(&buffer, &bufsize, stdin);

    filenamed = FILE* filename;
    fopen(filenamed, "a+");
    if(filenamed == NULL)
    {
        printf("File opening error\n");
        return 0;
    }
    else
    {
        printf("File opening success\n");
    }
    data = characters;
    fputs(data, filenamed);
    printf("File write success\n");
    res = fclose(filenamed);
    if(res == 0)
    {
        printf("File closed\n");
    }
    else
    {
        printf("Unable to close file\n");
    }
    return 0;
}