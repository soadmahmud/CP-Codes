#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test;

    cin >> test;

    for(int t = 1; t <= test; t++)
    {

        string a;

        cin >> a;

        long long int b;

        cin >> b;

        b = abs(b);

        string c = "";

        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == '-')
                continue;

            c += a[i];

            long long int num = stoll(c);

            num %= b;

            c = to_string(num);
        }

        if(stoll(c))
            cout << "Case " << t << ": " << "not divisible\n";
        
        else
            cout << "Case " << t << ": " << "divisible\n";
    }
}