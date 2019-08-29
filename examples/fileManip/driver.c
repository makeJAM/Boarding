/*
driver to test file manipulation pass by address
*/

#include "lib_mylib.h"
#define BUF 20

//prototype

int write_str2file(FILE** file, char* filename, char* content);

int main(int argc, char* argv[])
{
    FILE* fp;
    char* str2write;
    char* test = "random string\n";
    char* filename = "/mnt/d/OneDrive/BasicJQR/MantechBoard/examples/fileManip/test.txt";
    
    printf("File to write to: %s\n", filename);

    getline("String to write to file: %s\n", stdin, BUF);
    
    write_str2file(&fp, filename, str2write);
    return 0;
}
