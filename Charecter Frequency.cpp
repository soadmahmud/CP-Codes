#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        string s;

        char c;

        cin.ignore(1);
        
        getline(cin, s);

        cin >> c;

        int count = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == c)
                count++;
        }

        cout << "Occurrence of '" << c <<"' in '" << s << "' = " << count << "\n";
    }

    return 0;
}