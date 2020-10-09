#include <iostream>
#include <vector>
using namespace std;

long long n, m;

long long find_key(long long mid, vector<long long >& v) // 탑승한 시간을 인수로 받아 몇번째 아이까지 탑승가능한지 반환
{
	long long sum = 0;
	for (int i = 0; i < m; i++) // 해당 시간을 소요시간으로 나누면 몇명이 이전에 탑승했는지 알 수 있다.
	{
		sum += mid / v[i];
		if (mid % v[i]) // 만일 나머지가 0이 아닐경우 몫보다 더 많은 사람이 타있다. 1을 더 한다.
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
	long long prev = find_key(ans - 1, v); // 이전 시간대에 마지막으로 탄 아이의 번호를 알아낸다.

	int i = 0;
	for (i; i < m; i++) // 마지막 아이가 탑승할 기구 알아내기
	{
		if (!((ans - 1) % v[i])) // 이전에 탑승시간이 끝난경우 아이를 탑승시킨다.
			prev++;
		if (prev == n) break; // 마지막 아이가 탑승한 경우
	}
	cout << i + 1;
}