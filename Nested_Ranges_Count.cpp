#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll test;

    cin >> test;

    while(test--)
    {
        ll n, cube;

        cin >> n >> cube;

        vector<ll> v;

        ll b = 0, c = 0;

        for(ll i = 0; i < n; i++)
        {
            ll temp;

            cin >> temp;

            b += temp;

            c += (1LL * temp * temp );

            v.push_back(temp);
        }

        c -= cube;

        ll a = n;

        long double x1 = (-b + sqrt((1LL * b*b) - (4LL * a * c))) / 1.0 / (2 * a);

        long double x2 = (-b - sqrt((b*b) - (4 * a * c))) / 1.0 / (2 * a);

        ll w1 = 0, w2 = 0;

        if(x1 >= 0)
            cout << (ll) floor(x1/2) << "\n";
        
        else
            cout << (ll) floor(x2/2) << "\n";
    }

    return 0;

}