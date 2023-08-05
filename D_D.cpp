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

    for(int cases = 1; cases <= test; cases++)
    {
        cout << "Case " << cases << ": ";

        ll n;

        cin >> n;

        ll array[n];

        for(int i = 0; i < n; i++)
            cin >> array[i];
        
        ll result = 0;
        
        for(int i = 0; i < n; i++)
        {
            int l = i, r = i;

            bool f = true, s = true;

            while(f && s)
            {
                if(array[l] < array[i] || l == 0)
                    f = false;
                
                else
                    l--;
                
                if(array[r] < array[i] || r == n - 1)
                    s = false;
                
                else
                    r++;
            }

            result = max(result, (r - l + 1) * array[i]);
        }

        cout << result;

    }

    return 0;
}