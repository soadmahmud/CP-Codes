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
        ll n;

        cin >> n;

        string s;

        cin >> s;

        vector <ll> v;

        v.push_back(n+1);

        set <ll> u;

        u.insert(v.size() - 1);
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '>')
            {
                bool check = false;

                vector <ll> d = v;

                sort(d.begin(), d.end());

                for(int j = d.size() - 1; j > 0; j--)
                {
                    if(d[j] < v[v.size() - 1])
                    {
                        check = false;

                        v.push_back(d[j]);

                        u.insert(v.size() - 1);

                        break;
                    }

                    check = true;

                }

                if(check)
                {
                    v.push_back(v[i] - 1);
                    u.insert(v.size() - 1);
                }
            }

            else
            {
                bool check = false;

                vector <ll> d = v;

                sort(d.begin(), d.end());

                for(int j = d.size() - 1; j > 0; j--)
                {
                    if(d[j] > v[v.size() - 1])
                    {
                        check = false;

                        v.push_back(d[j]);
                        
                        u.insert(v.size() - 1);

                        break;
                    }

                    check = true;

                }

                if(check)
                {
                    v.push_back(v[i] + 1);
                    u.insert(v.size() - 1);
                }
            }

           // cout << r << " ";
        }

        //cout << endl;

        cout << u.size() << "\n";

        for(auto i : v)
            cout << i << " ";
        
        cout << endl;

    }

    return 0;
}