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

        vector <ll> v, r;

        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            ll a;

            cin >> a;

            v.push_back(a);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < (2*k); i = i + 2)
            r.push_back(v[i] + v[i+1]);
        
        for(int i = n - 1; i > (n-k); i--)
            r.push_back(v[i]);
        
        sort(r.begin(), r.end());

        ll sum = 0;

        for(auto i : v)
            sum += i;
        
        for(int i = 0; i < k; i++)
            sum -= r[i];

        //cout << sum << endl;

        for(auto i : v)
            cout << i << " ";
        
        cout << endl;
    
        for(auto i : r)
            cout << i << " ";
        
        cout << endl;

        cout << sum << endl;
    

    }

    return 0;
}