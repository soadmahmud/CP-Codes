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
        vector <pair<ll, ll>> p, check;

        ll n;

        cin >> n;

        vector<ll> v, chk;

        for(int i = 1; i <= n; i++)
        {
            ll a;

            cin >> a;

            v.push_back(a);

            chk.push_back(a);

            check.push_back({a, i});
        }

        sort(chk.begin(), chk.end());

        sort(check.begin(), check.end());

        if(v == chk)
            cout << 0 << "\n";
        
        else
        {
            for(int i = 1; i < v.size(); i++)
            {
                if(v[i] < v[i-1])
                {
                    while(v[i] < v[i-1])
                    {
                        bool op = true;
                        for(auto j : check)
                        {
                            if(j.first + v[i] >= v[i-1])
                            {
                                v[i] += j.first;

                                p.push_back({i+1, j.second});

                                op = false;

                                break;
                            }
                        }

                        if(op)
                        {
                            v[i] += check[n-1].first;

                            p.push_back({i+1, check[n-1].second});
                        }
                    }
                }
            }

            cout << p.size() << "\n";

            // for(auto i : p)
            //     cout << i.first << " " << i.second << "\n";

            for(auto i : v)
                cout << i << " ";

            cout << endl;
        }
    }
    return 0;
}