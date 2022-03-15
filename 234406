#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*
     *  Ici, le père envoie un nombre secret au
     *  processus fils.
     */

    /*
     *  Declaration de tableau des éléments du pipe, une entree fd[0] et une sortie fd[1]
        ret est le nom du tuyau
     *
     */

    int fd[2], ret;

    ret = pipe(fd);

    if (ret < 0)
    {
        /* Une erreur s'est produite lors de la création du tuyau*/
        printf("Erreur de création du pipe. \n");
        return 1;
    }

    /*On crée le processus fils*/
    int pid = fork();
    if (pid < 0)
    {
        printf("Erreur dans la création du processus fils .\n");
        return 1;
    }
    if (pid == 0)
    {
        /*Nous sommes dans le fils, c'est le processus de lecture*/

        char buffer[BUFSIZ + 1]; // buffer d'où on fait la lecture

        close(fd[1]); // on ferme l'extrémité d'écriture

        /*Tant que la lecture est possible read() != 0 , on lit dans le buffer*/
        while (read(fd[0], buffer, BUFSIZ) != 0)
            printf("J'ai reçu %s que mon père a envoyé.\n", buffer);
        printf("Je suis le processus fils (%d), le pid de mon père est : (%d)\n", getpid(), getppid());
        close(fd[0]);
        exit(1);
    }
    else
    {
        /*Nous sommes dans le pere, c'est le processus d'écriture */

        char buffer[BUFSIZ + 1]; // buffer o
        // on
        printf("Je suis le processus père (%d), le pid de mon fils est: (%d)\n", getpid(), pid);
        printf("Code secret : ");
        scanf("%s", buffer);
        close(fd[0]);                             // on ferme l'extrémité de lecture
        write(fd[1], buffer, strlen(buffer) + 1); // on envoie le buffer dans le tuyau
        close(fd[1]);
    }
}
