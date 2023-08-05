#include <bits/stdc++.h>
using namespace std;

int main()
{
    string h = "I hate ", l = "I love ", t = "that ", e = "it\n", r = "";

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if(i % 2)
            r += h;
        
        else
            r += l;
        
        if(i != n)
            r += t;
        
        else
            r += e;
    }

    cout << r;
}