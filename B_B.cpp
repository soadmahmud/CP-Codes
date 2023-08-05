#include <stdio.h>
#include <iostream>
using namespace std;

int a, b, c, d, e, f;

const int mx = 1e5;

long long int dp[mx];

bool vis[mx];

long long int fn(int n)
{
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if(vis[n])
        return dp[n];
    
    vis[n] = true;
    
    dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % 10000007;

    //cout << dp[n] << " " << n << "\n";

    return dp[n];
}

int main()
{

    int n, cases;
    scanf("%d", &cases);

    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);

        for(int i = 0; i <= n; i++)
             vis[i] = false;
            
        for(int i = 0; i <= n; i++)
             fn(i);

        printf("Case %d: %lld\n", caseno, fn(n) % 10000007);
    }

    return 0;
}