#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

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

        ll a, b;

        bool first = true, check = true, check2 = true;

        ll x;

        cin >> x;

        cout << 1;

        a = x;


        while(--n)
        {
            cin >> x;

            if(first)
            {
                if(x == a)
                    cout << 1;
                
                else
                {
                    first = false;

                    cout << 1;

                    if(x > a)
                        b = x;
                    
                    else
                    {
                        check = false;

                        b = x;
                    }
                }
            }

            else if(check)
            {
                if(x >= b)
                {
                    cout << 1;

                    x = b;
                }

                else if(x <= a)
                {
                    check = false;

                    cout << 1;

                    x = b;
                }

                else
                    cout << 0;
            }

            else if(check2)
            {
                if(x >= b && x <= a)
                {
                    b = x;

                    cout << 1;
                }

                else if(x == a)
                {
                    check2 = false;

                    cout << 1;
                }

                else
                    cout << 0;
            }

            else
                cout << 0;
        }

        cout << "\n";
    }
    
    return 0;
}