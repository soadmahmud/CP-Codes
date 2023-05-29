#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        string s;

        cin >> s;

        int a = -1;

        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] != s[i-1])
            {
                a = s.length() - 1;

                break;
            }
        }

        cout << a << endl;
    }
}