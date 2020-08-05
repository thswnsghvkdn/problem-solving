#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](int a, int b)
		{
			return a < b;
		});
	long long start = 1;
	long long end = v[n-1];
	long long cen;
	long long cnt;
	long long ans = 0;
	while (start <= end)
	{
		cnt = 0;
		cen = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			cnt += v[i] / cen;
		}
		if (cnt >= k)
		{
			if (ans < cen)
				ans = cen;
			start = cen + 1;
		}
		else
			end = cen - 1;
	}

	cout << ans;
}