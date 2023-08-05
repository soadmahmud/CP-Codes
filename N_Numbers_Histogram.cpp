#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll get(ll n)
{
    ll sum = 0;

    while(n)
    {
        sum += n % 10;

        n /= 10;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   string s;

   cin >> s;

   ll count = 0;

   while(s.size() > 1)
   {
        ll a = 0;

        count++;

        for(int i = 0; i < s.size(); i++)
            a += s[i] - '0';

        s = to_string(a);

   }

   cout << count << endl;

    return 0;
}