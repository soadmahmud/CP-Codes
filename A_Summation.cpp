#include <bits/stdc++.h>
using namespace std;

#define int long long int


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test;

	cin >> test;

	while(test--)
	{
		int n, m, h, count = 1;

		cin >> n >> m >> h;

		
		//sort(p, p + m);

		int point = 0, penalty = 0, sum = 0;

		for(int i = 0; i < m; i++)
		{
			if(sum + 1 > h)
				break;
			
			sum += 1;

			point++;

			penalty +=  sum;
		}

		cout << "p " << point << " pt " << penalty << endl;

		// while(--n)
		// {

		// 	for(int i = 0; i < m; i++)
		// 		cin >> p[i];
			
		// 	sort(p, p + m);

		// 	int apoint = 0, apenalty = 0;

		// 	sum = 0;

		// 	for(int i = 0; i < m; i++)
		// 	{
		// 		if(sum + p[i] > h)
		// 			break;
				
		// 		sum += p[i];

		// 		apoint++;

		// 		apenalty += sum;
		// 	}

		// 	if(apoint > point)
		// 		count++;
			
		// 	else if(apoint == point)
		// 	{
		// 		if(apenalty < penalty)
		// 			count++;
		// 	}

		// 	cout << "ap " << apoint << " apt " << apenalty << endl;
		// }

		// cout << count << "\n";
	}
		
	return 0;
}