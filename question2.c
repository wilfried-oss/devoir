#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /**
     *  le programme crée un processus fils. Le fils affiche
     *  le pid de son père. Le père affiche le pid de son fils.
     *
     */

    pid_t pid = fork();

    if (pid < 0)
    {
        /* En cas d'erreur il faut mettre fin au programme*/
        printf("Erreur de création du processus fils \n");
        exit(1);
    }
    if (pid == 0)
    {
        /* Nous sommes dans le processus fils*/
        printf("Je suis le processus fils (%d), le pid de mon père est : (%d)\n", getpid(), getppid());
    }
    else
    {
        /* Nous sommes dans le père*/
        printf("Je suis le processus père (%d), le pid de mon fils est: (%d)\n", getpid(), pid);
    }
    return 0;
}
