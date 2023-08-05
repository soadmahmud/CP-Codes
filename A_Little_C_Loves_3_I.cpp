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

        ll mx = 0;

        while(n--)
        {
            ll a;

            cin >> a;

            mx = max(a, mx);
        }
        

        cout << mx << "\n";
    }

    return 0;
}