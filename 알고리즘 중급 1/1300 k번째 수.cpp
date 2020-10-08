#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long k;

long long find_key(long long key)
{
	long long sum = 0;
	for (long long i = 1; i <= n; i++)
	{
		sum += min(n, key / i);
	}
	return sum;
}

int main()
{
	cin >> n >> k;

	long long start = 1;
	long long end = n * n;
	long long ans = 1;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		if (find_key(mid) >= k)
		{
			end = mid - 1;
			ans = mid;
		}
		else
			start = mid + 1;
	}

	cout << ans << '\n';

}