#include <iostream>

using namespace std;

int ar[5000];
int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int cnt = 1;

	int first = 0;
	int end = 10000;
	int ans = 10000;
	while (first <= end)
	{
		int mid = (first + end) / 2;
		int min = 10000;
		int max = 0;
		cnt = 1;
		// 해당 mid값으로 구역을 나눌 수 있는 만큼 최대한 나눈다.
		for (int i = 0; i < n; i++)
		{
			if (ar[i] < min)
				min = ar[i];
			if (ar[i] > max)
				max = ar[i];
			if ((max - min) > mid) // 해당 mid값을 맞출 수 없는 원소가 등장했을 때 새로운 구역을 나누기 시작한다.
			{
				cnt++;
				min = max = ar[i];
			}
		}
		if (cnt <= m) // 정해진 구역안에 나눌수 있다면
		{
			end = mid - 1;
			if (mid < ans)
				ans = mid;
		}
		else
			first = mid + 1;
	}
	
	cout << ans;
}