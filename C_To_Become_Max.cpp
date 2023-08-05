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
        ll n, k;

        cin >> n >> k;

        ll array[n];

        ll max = 0, pos;

        ll result = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> array[i];

            if(array[i] >= max)
            {
                max = array[i];

                pos = i;
            }
        }
        
        for(int i = pos - 1; i >= 0; i--)
        {
            if(array[i] + k > array[i+1])
            {
                k -= (array[i+1] - array[i] + 1);

                array[i] = array[i+1] + 1;
            }

            if(k == 0)
                break;
        }
        
        if(pos == 0)
        {

            ll k2 = k;

            for(int i = 1; i < n - 1; i++)
            {

                if(array[i] <= array[i+1])
                {
                    k -= array[i-1] - array[i];

                    break;
                }

                if(array[i] + 1 == array[0] && i > 1)
                    break;

                k -= array[i-1] - array[i];
            }

            if(k > 0)
                result = array[0] + 1;
            
            else
            {
                for(int i = 1; i < n - 2; i++)
                {
                    if(array[i] + 1 == array[0] && array[i] == array[i+1] && array[i] == array[i + 2] && k2 >= 3)
                    {
                        result = array[0] + 1;

                        break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(result < array[i])
                result = array[i];
        }

        cout << result << "\n";
        
    }

    return 0;
}