/*
functions for file manipulation pass by address
*/
#include <stdio.h>
#include <malloc.h>
#define BUFFER 5

/*
int file_open(char* file2open)
{
    FILE* fp = NULL;
    fp = fopen(file2open, 'w');
    if(fp == NULL)
    {
        printf("File opening error\n");
    }
    else
    {
        printf("File opening success\n");
    }
    return 0;
}

int read_file(char* file2read)
{
   FILE* fp = NULL;
   int rel;
   int data;
   fp = fopen(file2read, 'w');
   if(fp == NULL)
   {
      printf("File opening error\n");
   }
   else
   {
      printf("File opening success\n");
   }
   while((data = fgetc(fp)) != EOF)
   {
      if ( data != 10) //checking for new line
         printf("%d %c ,", data, (char)data);
      else
      {
         printf('\n');
      }
   }
   rel = fclose(fp);
   if(rel == 0)
   {
      printf("File closed\n");
   }
   else
   {
      printf("Unable to close file\n");
   }
   return 0;
}

int release_file(char* file2close)
{
    FILE* fp = NULL;
    int rel;
    rel = fclose(file2close);
    if(rel == 0)
    {
        printf("File closed\n");
    }
    else
    {
        printf("Unable to close file\n");
    }
    return 0;
}

int read_block(char* file2open)
{
    FILE* fp;
    int rel;
    char*str = NULL;
    fp = fopen(file2open,"r");
    if(fp == NULL)
    {
       printf("File opening error\n");
    }
    else
    {
       printf("File opening success\n");
    }
    str = (char*)malloc(sizeof(char)*BUFFER);
    rel = fread(str, sizeof(char), BUFFER-1, fp);
    str[4] = '\0';
    if(rel)
    {
       printf("%s \n",str);
    }
    else
    {
       printf("Line reading failure\n");
    }
    rel = fclose(fp);
    if(rel == 0)
    {
       printf("File closed\n");
    }
    else
    {
       printf("Unable to close file\n");
    }
    return 0;
}

int readString(char* file2open)
{
   FILE* fp;
   int rel;
   char*str = NULL;
   unsigned char chr;
   int fpos;
   fp = fopen(file2open,"r");
   if(fp == NULL)
   {
      printf("File opening error\n");
   }
   else
   {
      printf("File opening success\n");
   }
   str = (char*)malloc(sizeof(char)*BUFFER);
   fpos = ftell(fp);
   printf("File pointer position before reading = %d\n", fpos);
   if(fgets(str, BUFFER, fp))
   {
      printf("%s \n",str);
   }
   else
   {
      printf("Line reading failure\n");
   }
   fpos = ftell(fp);
   printf("File pointer position after reading = %d\n", fpos);
   rel = fclose(fp);
   if(rel == 0)
   {
      printf("File closed\n");
   }
   else
   {
      printf("Unable to close file\n");
   }
   return 0;
}
*/

int write_str2file(FILE** file, char* fileName, char* content)
{
   //FILE* file; not required
   int res;
   //int index;
   *file = fopen(fileName, "a+");
   if(*file == NULL)
   {
      printf("File opening error\n");
      return 0;
   }
   else
   {
      printf("File opening success\n");
   }
   fputs(content, *file);
   printf("File write success\n");
   res = fclose(*file);
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