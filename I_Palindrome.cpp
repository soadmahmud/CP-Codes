#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    vector <int> v;

    for(in i = 1; i <= n; i++)
    {
        if(n % i == 0)
            v.push_back(i);
        
        if(n/i != i)
            v.push_back(n/i);
    }

    sort(v.begin(), v.end());

    for(auto i : v)
        cout << i << endl;

     return 0;
}