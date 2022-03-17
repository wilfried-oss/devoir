#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <md5.h>
#include <ctype.h>

/* UN EXEMPLE DE THREAD  */

void *threadFunction(void *args)
{
    printf("Hello World from thread \n");
}
// char buffer[128];
// MD5File(file, buffer);

int main()
{
    pthread_t thread1;
    int ret;
    ret = pthread_create(&thread1, NULL, &threadFunction, NULL);
    if (ret == 0)
    {
        printf("Thread created successfully. \n");
    }
    else
    {
        printf("Thread not created. \n");
        return 0;
    }
    printf("Hello World from main function \n");
    return 0;
}
