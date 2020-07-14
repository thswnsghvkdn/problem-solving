#include <iostream>
#include <algorithm>
using namespace std;

int t[15];
int p[15];
int n;
int tot[15];
int go(int day)
{
	if (day == n)
		return 0;
	
	if (day > n)
		return -10000;

	if (tot[day] != -1)
		return tot[day];
	
	int t1 = go(day + 1);
	int t2 = p[day] + go(day + t[day]);
	tot[day] = max(t1, t2);
	return tot[day];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> p[i];
		tot[i] = -1;
	}
	cout << go(0);
	
}