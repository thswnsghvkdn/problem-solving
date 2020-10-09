#include <iostream>
#include <vector>
using namespace std;

long long n, m;

long long find_key(long long mid, vector<long long >& v) // ž���� �ð��� �μ��� �޾� ���° ���̱��� ž�°������� ��ȯ
{
	long long sum = 0;
	for (int i = 0; i < m; i++) // �ش� �ð��� �ҿ�ð����� ������ ����� ������ ž���ߴ��� �� �� �ִ�.
	{
		sum += mid / v[i];
		if (mid % v[i]) // ���� �������� 0�� �ƴҰ�� �򺸴� �� ���� ����� Ÿ�ִ�. 1�� �� �Ѵ�.
			sum++;
	}
	return sum;
}
int main()
{
	cin >> n >> m;
	vector<long long> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	long long start = 1;
	long long end = 60000000000;
	long long ans;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		if (find_key(mid, v) >= n) {
			ans = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	long long prev = find_key(ans - 1, v); // ���� �ð��뿡 ���������� ź ������ ��ȣ�� �˾Ƴ���.

	int i = 0;
	for (i; i < m; i++) // ������ ���̰� ž���� �ⱸ �˾Ƴ���
	{
		if (!((ans - 1) % v[i])) // ������ ž�½ð��� ������� ���̸� ž�½�Ų��.
			prev++;
		if (prev == n) break; // ������ ���̰� ž���� ���
	}
	cout << i + 1;
}