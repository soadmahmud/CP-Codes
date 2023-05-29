#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;

    cin >> test;

    while(test--)
    {
        string s;

        map <char, int> mp;

        cin >> s;

        for(int i = 0; i < s.length(); i++)
            mp[s[i]]++;
        
        if(mp.size() == 1)
            cout << "NO\n";
        
        else if(mp.size() == 2)
        {
            bool check = false;

            for(auto i : mp)
            {
                if(i.second == 1)
                    check = true;
            }

            if(check)
                cout << "NO\n";
            
            else
                cout << "YES\n";
        }

        else
            cout << "YES\n";
    }

    return 0;
}