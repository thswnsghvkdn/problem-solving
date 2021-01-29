#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <int, int> m;
int n, s;
int A[41];
int mid;
int ans;
void firstPart(int index , int sum)
{
	if (index == mid)
	{
		m[sum]++;
		return;
	}
	firstPart(index + 1, sum);
	firstPart(index + 1, sum + A[index]);
}
void secondPart(int index, int sum)
{
	if (index == n)
	{
		ans += m[s - sum];
		return;
	}
	secondPart(index + 1, sum);
	secondPart(index + 1, sum + A[index]);
}
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	mid = n / 2;
	firstPart(0, 0);
	secondPart(mid, 0);
	if (s == 0) ans--;
	cout << ans;
}