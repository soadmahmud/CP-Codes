#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int test;

    cin >> test;

    while(test--)
    {
        ll n, k;

        cin >> n >> k;

        if(n % k)
        {
            cout << "1\n";

            cout << n << "\n";
        }

        else
        {
            cout << "2\n";

            cout << n-1 << " " << 1 << "\n";
        }
    }

    return 0;
}