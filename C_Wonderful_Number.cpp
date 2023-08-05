#include <bits/stdc++.h>
using namespace std;

#define ll long long

int min, max;

void eq(int a[])
{
    int n = sizeof(a) / sizeof(int);

    min = INT_MAX;
    
    max = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(a[i] < min)
            min = a[i];
        
        if(a[i] > max)
            max = a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << min << " " << max << "\n";

}