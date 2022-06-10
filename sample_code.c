#include <sys/syscall.h>
#include <linux/kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n, x;

void *handler()
{
    syscall(335, &x);
    return 0;
}
int main()
{
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the number of threads: ");
    scanf("%d", &n);
    printf("Initial value of x: %d\n", x);
    pthread_t threads[n];
    for (int i = 0; i < n; i++)
    {
        pthread_create(&threads[i], NULL, handler, NULL);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Final value of x: %d\n", x);
    return 0;
}