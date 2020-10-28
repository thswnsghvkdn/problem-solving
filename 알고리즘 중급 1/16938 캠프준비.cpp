#include <iostream>
#include <vector>
using namespace std;
int ans;
int n, l, r, x;
vector<int> v(15);

void check_level(int index, long long sum, int min, int max)
{
	for (int i = index; i < n; i++) // n까지 반복
	{
		int n_min = min;
		int n_max = max;
		if (v[i] + sum > r) continue;
		if (v[i] + sum >= l)
		{
			if (v[i] < min) n_min = v[i];
			if (v[i] > max) n_max = v[i];
			if (n_max - n_min >= x) ans++;
			check_level(i + 1, sum + v[i], n_min, n_max);
		
		}
		else {
			if (v[i] < min) n_min = v[i];
			if (v[i] > max) n_max = v[i];
			check_level(i + 1, sum + v[i], n_min, n_max);
		}
	}
}
int main()
{
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		if (v[i] > r) continue;
		check_level(i + 1, v[i], v[i], v[i]);
	}
	cout << ans;
}