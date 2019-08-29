#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
        struct gif_hdr
        {
                char signature[3];
                char version[3];
                int width;
                int height;
                char colormap;
                char bgcolor;
                char ratio;
        };
        struct gif_hdr v1;
        struct gif_hdr *dsptr;
        printf("Size of structure data = %ld\n", sizeof(struct gif_hdr));
        dsptr = (struct gif_hdr*)malloc(sizeof(struct gif_hdr));
        printf("Offset of signature = %ld\n", &(dsptr->signature[0]) - &(dsptr->signature[0]) );
        printf("Offset of version = %ld\n", &(dsptr->version[0]) - &(dsptr->signature[0]) );
        printf("Offset of width = %ld\n", (char*)&(dsptr->width) - &(dsptr->signature[0]));
        printf("Offset of height = %ld\n", (char*)&(dsptr->height) - &(dsptr->signature[0]));
        printf("Offset of colormap = %ld\n", &(dsptr->colormap) - &(dsptr->signature[0]));
        printf("Offset of bgcolor = %ld\n",&(dsptr->bgcolor) - &(dsptr->signature[0]));
        printf("Offset of ratio = %ld\n", &(dsptr->ratio) - &(dsptr->signature[0]));
        return 0;
}
