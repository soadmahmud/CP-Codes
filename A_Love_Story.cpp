#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        string s1, s2 = "codeforces";

        cin >> s1;

        int count = 0;

        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i])
                count++;
        }

        cout << count << endl;
    }
}