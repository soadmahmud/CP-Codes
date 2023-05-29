#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    bool prime[1000001];

    int m = 1000000;

    for(int i = 1; i <= 1000000; i++)
        prime[i] = false;
    
    prime[2] = true;

    

    for(int i = 3; i <= 1000000; i+=2)
    {
        bool check = true;

        for(int j = 3; (j * j) <= i; j += 2)
        {
             if(i % j == 0 && i != j)
            {
                check = false;

                break;
            }

            else
                check = true;
        }

        if(check)
            prime[i] = true;
    
    }
        
    int test;

    cin >> test;

    while(test--)
    {
        int a, b, count = 0;

         cin >> a >> b;

        for(int i = a; i <= b; i++)
        {
            if(prime[i])
                cout << i << endl;
        }

        // cout << count << "\n";
    }


    return 0;
}