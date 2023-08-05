#include <bits/stdc++.h>
using namespace std;

bool is_lucky(int n)
{
    while(n > 0)
    {
        int l = n % 10;

        n /= 10;

        if(l != 4 && l != 7)
            return false; 
    }

    return true;
}

int main()
{
    int a, b;

    cin >> a >> b;

    bool check = true;

    for(int i = a; i <= b; i++)
    {
        if(is_lucky(i))
        {
            cout << i << " ";

            check = false;
        }
    }

    cout << endl;

    if(check)
        cout << "-1\n";


     return 0;
}