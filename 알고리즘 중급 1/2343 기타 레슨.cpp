#include <iostream>
#include <vector>
using namespace std;

int ar[100000];

bool find_key(int size, int key, int cnt)
{
	int t_cnt = 0;
	int sum = 0;
	for (int i = 0; i <= size; i++)
	{
		if (sum > key)
		{
			t_cnt++;
			i--;
			sum = 0;
			if (t_cnt >= cnt) return false;
		}
		sum += ar[i];
	}
	return true;
}

int main()
{
	int m, n;
	cin >> m >> n;
	int max = m * 10000;
	for (int i = 0; i < m; i++)
		cin >> ar[i];
	int min = 1;
	int ans = max;
	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (find_key(m, mid, n))
		{
			max = mid - 1;
			if (mid < ans)
				ans = mid;
		}
		else {
			min = mid + 1;
		}
	}
	cout << ans;
}