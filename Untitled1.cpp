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

        int max = 0;

        while(n--)
        {
            int a;

            cin >> a;

            max = max(a, max);
        }


        cout << max << "\n";
    }

    return 0;
}
