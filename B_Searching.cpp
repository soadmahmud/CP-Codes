#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

    cin >> n;

    vector <ll> v;

    ll a;

    while(n--)
    {
        cin >> a;

        v.push_back(a);
    }

    cin >> a;

    auto it = find(v.begin(), v.end(), a);

    if(it == v.end())
        cout << "-1\n";
    
    else
        cout << distance(v.begin(), it) << "\n";
        

	return 0;
}