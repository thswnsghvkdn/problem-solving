#include <iostream>
#include <vector>
using namespace std;


int main()
{
	long long n, m;
	cin >> n >> m;
	long long max = 0, start = 1, cen, cnt = 0;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (max < v[i])
			max = v[i];
	}
	long long ans = 0;
	while (start <= max)
	{
		cnt = 0;
		cen = (start + max) / 2;
		for (int i = 0; i < n; i++)
			if (v[i] > cen)
				cnt += v[i] - cen;
		if (cnt >= m)
		{
			if (ans < cen)
				ans = cen;
			start = cen + 1;
		}
		else
			max = cen - 1;

	}
	cout << ans;
}