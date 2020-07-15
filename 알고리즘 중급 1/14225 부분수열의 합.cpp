#include <iostream>
#include <algorithm>

using namespace std;
int s[100000];
int sum[20 * 100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				sum[i] += s[j];
			}
		}
	}

	sort(sum, sum + (1 << n));
	unique(sum, sum + (1 << n));
	
	for (int i = 0; i <(1 << n); i++)
	{
		if (sum[i] != i)
		{
			cout << i;
			return 0;
		}
	}
	cout << (1 << n);
	return 0;
}