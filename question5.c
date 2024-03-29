#include <sys/types.h>
#include <md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

int main(int argc, char *argv[])
{
    char buff1[BUFSIZE], buff2[BUFSIZE];

    if (argc != 3)
    {
        printf("Format : %s <parameter1><parameter2>\n", argv[0]);
        exit(0);
    }

    /*On calcule le MD5 du fichier source avant la copie*/
    MD5File(argv[1], buff1);

    /* Début algorithme question 1*/
    FILE *f1, *f2;

    f1 = fopen(argv[1], "r");

    if (f1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }

    f2 = fopen(argv[2], "w");

    char buffer[BUFSIZE];
    while (fgets(buffer, BUFSIZE, f1) != NULL)
    {
        fputs(buffer, f2);
    }

    /* Fin algorithme question 1*/

    fclose(f1);
    fclose(f2);

    /*On calcule le md5 du fichier clone après la copie*/
    MD5File(argv[2], buff2);

    /*On compare les deux Md5, si les deux sont égaux, cela signifie
        *que les deux fichiers
    sont identiques*/
    if (strcmp(buff1, buff2) == 0)
        printf("La copie s'est bien passée. \n");
    else
        printf("Erreur lors de la copie. \n");

    return 0;
}
