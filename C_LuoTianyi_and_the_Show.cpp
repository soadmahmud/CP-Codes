#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;

    cin >> test;

    while(test--)
    {
        int n, m;

        cin >> n >> m;

        bool check[m+1];

        for(int i = 0; i <= m; i++)
            check[i] = false;

        int first = 0, second = 0;

        bool getpoint = false;

        for(int i = 0; i < n; i++)
        {
            int a;

            cin >> a;

            if(a == -1)
                first++;

            else if(a == -2)
                second++;

            else
            {
                check[a] = true;

                getpoint = true;
            }


        }

        int maxpoint = 0, minpoint = 0;

        for(int i = 2; i < m; i++)
        {
            if(check[i])
            {
                if(minpoint == 0)
                    minpoint = i;

                maxpoint = i;

            }
        }


        int f1 = first, f2 = second;

        if(maxpoint == 0 && minpoint == 0)
        {
            if(first > second)
            {
                for(int i = m; i >= 1; i--)
                {
                    if(first == 0)
                        break;
                    
                    if(check[i])
                        continue;


                    check[i] = true;

                    first--;
                }
            }

            else if(second > first)
            {
                for(int i = 1; i <= m; i++)
                {
                    if(second == 0)
                        break;
                    
                    if(check[i])
                        continue;

                    check[i] = true;

                    second--;
                }
            }

            else if(first == second && check[1] && check[m])
            {
                for(int i = 1; i <= m; i++)
                {
                    if(second == 0)
                        break;

                    check[i] = true;

                    second--;
                }
            }

            else if(first == second && check[1])
            {
                for(int i = m; i >= 1; i--)
                {
                    if(first == 0)
                        break;
                    
                    check[i] = true;

                    first--;
                }
            }

            else
            {
                for(int i = 1; i <= m; i++)
                {
                    if(second == 0)
                        break;

                    check[i] = true;

                    second--;
                }
            }
        }

        else if(first > second)
        {
            for(int i = maxpoint; i >= 1; i--)
            {
                if(first == 0)
                    break;

                if(check[i])
                    continue;

                check[i] = true;

                first--;
            }

            if(first > second)
            {
                for(int i = maxpoint; i <= m; i++)
                {
                    if(first == 0)
                        break;

                    if(check[i])
                        continue;

                    check[i] = true;

                    first--;
                }
            }

            else
            {
                for(int i = 2; i <= m; i++)
                {
                    if(second == 0)
                        break;

                    if(check[i])
                        continue;

                    check[i] = true;

                    second--;
                }
            }


        }

        else
        {
            for(int i = minpoint; i <= m; i++)
            {
                if(second == 0)
                    break;

                if(check[i])
                    continue;

                check[i] = true;

                second--;
            }

            if(second > first)
            {
                for(int i = 1; i <= m; i++)
                {
                    if(second == 0)
                        break;

                    if(check[i])
                        continue;

                    check[i] = true;

                    second--;
                }
            }

            else
            {
                for(int i = m - 1; i >= 1; i--)
                {
                    if(first == 0)
                        break;

                    if(check[i])
                        continue;

                    check[i] = true;

                    first--;
                }
            }
        }


        int count = 0;

        for(int i = 1; i <= m; i++)
        {
            if(check[i])
                count++;
        }

        cout << count << "\n";
    }
}