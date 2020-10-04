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
		// �ش� mid������ ������ ���� �� �ִ� ��ŭ �ִ��� ������.
		for (int i = 0; i < n; i++)
		{
			if (ar[i] < min)
				min = ar[i];
			if (ar[i] > max)
				max = ar[i];
			if ((max - min) > mid) // �ش� mid���� ���� �� ���� ���Ұ� �������� �� ���ο� ������ ������ �����Ѵ�.
			{
				cnt++;
				min = max = ar[i];
			}
		}
		if (cnt <= m) // ������ �����ȿ� ������ �ִٸ�
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