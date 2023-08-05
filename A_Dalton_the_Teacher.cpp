#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


   int test;

   cin >> test;

   while(test--)
   {
        ll n;

        cin >> n;

        if(n % 2)
            cout << 1 << "\n";
        
        else
        {
            ll a = n;

            ll count = 0, result = 0;

            bool 

            for(ll i = 1; i <= a; i++;)
            {
                if(n % i == 0)
                {
                    a /= i;

                    if((i - 1) % n == 0)
                        count++;

                    else
                        count = 0; 
                }

                if(count > result)
                    result = count;
            }

            cout << result << "\n";
        }
   }

    return 0;
}