#include <stdio.h>
#include <stdlib.h>
#define TAILLE_BUFFER 100

int main(int argc, char *argv[])
{
    /**
     *  le programme copie le contenue d'un fichier donné
     *  en paramètre vers un autre fichier passé en paramètre
     */

    /**
     *  le programme ne prend que 2 arguments en paramètre.
     *  tout autre nombre d'arguments différent de 2(+1 pour le nom
     *  de l'exécutable) génère l'erreur "Format : %s <parameter1><parameter2>\n"
     *  et le programme arrete de s'exécuter.
     */
    if (argc != 3)
    {
        printf("Format : %s <parameter1><parameter2>\n", argv[0]);
        exit(0);
    }

    /**
     * on crée deux indicateurs de fichiers de type FILE
     */

    FILE *f1, *f2;

    /**
     *  fopen renvoie un pointeur sur FILE ! C'est un pointeur sur
     *  une structure de type FILE. Cette structure est définie dans stdio.h.
     *  Cette fonction attend deux paramètres : le nom du fichier à ouvrir et
     *  le mode d'ouverture du fichier,
     */

    f1 = fopen(argv[1], "r"); // ouverture du premier fichier (argv[1]) en mode lecture

    // Si l'ouverture ne marche pas
    if (f1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }

    /**
     *  l'ouverture en mode ecriture "w" du second fichier
     *  ceci crée le fichier s'il n'existe pas, et vide également
     *  son contenu.
     *  A la fin du programme, les deux fichiers seront identiques
     */

    f2 = fopen(argv[2], "w");

    /**
     * on crée une boucle pour caractère par caractère
     * le contenu de argv[1] dans argv[2]
     */

    int characters = 0;
    while (1)
    {
        characters = fgetc(f1);
        fputc(characters, f2);
        if (characters == EOF)
            break;
    }

    printf("La copie est bien terminée.\n");

    // on ferme les deux fichiers
    fclose(f1);
    fclose(f2);

    return 0;
}