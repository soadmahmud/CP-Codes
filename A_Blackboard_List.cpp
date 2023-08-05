#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 7;

bool prime[mx];

int main()
{
    int test;

    cin >> test;

    memset(prime, -1, sizeof(prime));
    
    prime[1] = false;

    //prime[3] = true;

    for(int i = 2; i < mx; i++)
    {
        if(prime[i] == false)
            continue;

        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
                prime[i] = false;
        }

        for(int j = 2; j * i < mx; j++)
        {
                prime[i*j] = false;
        }
    }

    int n, sum = 0;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int count = 0;

        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                if(prime[j])
                    count++;
                
                if(i/j != j)
                {
                    if(prime[i/j])
                        count++;
                }
            }
        }

        if(count == 2)
            sum++;
    }

    cout << sum << endl;
    
     return 0;
}