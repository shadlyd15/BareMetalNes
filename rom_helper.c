
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>




int main(int argc, char *argv[])
{
    struct stat st;

    stat(argv[1], &st);
    size_t size = st.st_size;
    
static unsigned int rom[1048576];
    if (argc != 2)
    {
        fprintf(stderr, "ERROR : Please input a .nes file\n");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Open rom file failed.\n");
        return 0;
    }
    int nread = fread(rom, st.st_size, 1, fp);
    if (nread == 0 && ferror(fp)) {
        fprintf(stderr, "Read rom file failed.\n");
        return 0;
    }
	


    printf("static unsigned int rom[] = {\n");
    for (int i = 0; i < st.st_size + 1; ++i)
    {
    	// if(rom[i])
    	printf("%uU", rom[i]);
        if(i != st.st_size) printf(", ");
        if(!(i%10)) printf("\n");
    }
    printf("};");


    return 0;
}
