#include <bits/stdc++.h>
using namespace std;

int n;

int arr[6005];

vector<int> graph[6005];

#define ll long long

int dp[6005][2];
bool flag[6005];

bool lead[6005];

void dfs(int n)
{
    if(flag[n])
        return;

    flag[n] = true;

    dp[n][1] = arr[n];

    for(auto i : graph[n])
    {
        dfs(i);

        dp[n][0] += max(0, max(dp[i][0], dp[i][1]));

        dp[n][1] += max(0, dp[i][0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)  cin >> arr[i];

    while(1)
    {
        int a, b;
        cin >> a >> b;

        if(a == 0 && b == 0)    break;

        graph[b].push_back(a);

        lead[a] = true;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!lead[i])
        {
            dfs(i);

            ans += max(0, max(dp[i][0], dp[i][1]));
        }
    }

    cout << ans << "\n";

    return 0;
}
