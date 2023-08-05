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

        n--;

        int count = 0;

        for(int i = 2; i <= n; i++)
        {
            if(n % i == 0)
            {
                cout << i;

                count++;

                if(count == 1)
                    cout << " ";

                if(n / i != i && count == 1)
                {
                    cout << n / i;

                    count++;
                }
            }

            if(count == 2)
            {
                cout << "\n";

                break;
            }
        }
    }

    return 0;
}