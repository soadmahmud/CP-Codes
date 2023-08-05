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

            int count = 1;

            bool f = true, s = true;

            while(f || s)
            {
                if(l && (array[l-1] >= array[i]) && f)
                {
                    l--;

                    count++;
                }
                
                else
                    f = false;
                
                if(r != n - 1 && (array[r+1] >= array[i]) && s)
                {
                    r++;

                    count++;
                }
                
                else
                    s = false;
            }

            result = max(result, (count * array[i]));

            //cout << result << " " << l << " " << r << '\n';
        }

        cout << result << "\n";

    }

    return 0;
}