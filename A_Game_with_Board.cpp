#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        int n;

        cin >> n;

        if(n % 2)
            n--;
        
        int count = 0;
        
        while(n  > 1)
        {
            n /= 2;

            count++;
        }

        if(count % 2)
            cout << "Bob\n";
        
        else
            cout << "Alice\n";


        
    }
    
    return 0;
}