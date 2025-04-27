#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

const int mx = 100005;

vector<int> graph[mx];

int dp[mx][2];

bool flag[mx];

void dfs(int n)
{
    dp[n][1] = 1;

    flag[n] = true;

    for(auto i : graph[n])
    {
        if(flag[i]) continue;

        dfs(i);

        dp[n][0] += max(dp[i][0], dp[i][1]);

        dp[n][1] += dp[i][0];
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[b].push_back(a);
        graph[a].push_back(b);
    }

    dfs(1);

    cout << n - max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
