#include <iostream>
using namespace std;


int main()
{
	int change[15];
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> change[i];
	
	int cnt = 0;
	int share;
	while (k > 0 && n > 0)
	{
		if (change[n] < k)
		{
			share = k / change[n];
			k -= (change[n] * share);
			cnt += share;
		}
		else 
			n--;
	}
	cout << cnt;
}