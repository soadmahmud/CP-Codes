#include <stdio.h>

int array[100];

bool vis[100];

int fib(int n)
{

    if(n == 1)
        return 1;

    if(n == 0)
        return 0;
    
    if(vis[n])
        return array[n];

    vis[n] = true;

    array[n] = fib(n-1) + fib(n-2);

    return array[n];
}

int main()
{
    printf("%d", fib(50));
}