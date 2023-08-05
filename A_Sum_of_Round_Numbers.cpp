#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;

ll value;

const int m = 1e5 + 5;

ll mx = 0;

string s[m];

int vis[m][19];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    vis[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int a = dx[i] + x, b = dy[i] + y;

        if(a >= 0 && b >= 0 && a < n && b < value)
        {
            if(vis[a][b] == 0 && s[a][b] == s[0][0])
            {
                dfs(a, b);
            }
            
        }
    }
}

int main()
{

    memset(vis, 0, sizeof(vis));
    cin >> n;

    vector <ll> v;

    for(int i = 0; i < n; i++)
    {
        ll a;

        cin >> a;

        mx = max(a, mx);

        v.push_back(a);
    }

    value = (int) log2(mx) + 1;

    for(int i = 0; i < n; i++)
    {
        s[i] = bitset <62> (v[i]).to_string().substr(62 - value);
    }

    dfs(0, 0);

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < value; j++)
    //         cout << vis[i][j] << " ";
        
    //     cout << endl;
    // }

    
    if(vis[n-1][value-1])
        cout << "Yeeee! ice-cream.\n";

    else
        cout <<  "Let's make ice-cream.\n";

    return 0;
}
