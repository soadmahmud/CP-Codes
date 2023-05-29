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

        int array[n];

        for(int i = 0; i < n; i++)
            cin >> array[i];

        int count = 0, max = 0;

        for(int i = 0; i < n; i++)
        {
            if(array[i] == 0)
                count++;
            
            else
                count = 0;

            if(count >= max)
                max = count;
            
        }

        cout << max << endl;
    }
}