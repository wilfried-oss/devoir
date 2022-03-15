#include <sys/types.h>
#include <md5.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buf[128];
    if (argc != 2)
    {
        fprintf(stderr, "usage %s <filename>\n", argv[0]);
        exit(0);
    }
    MD5File(argv[1], buf);
    printf("Le MD5 du fichier %s : %s \n", argv[1], buf);
}
