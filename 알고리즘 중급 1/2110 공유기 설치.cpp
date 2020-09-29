#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int>& v, int cnt, int dis)
{
	int second = v[0];
	int ans = 1;
	for (int first : v) {
		if ((first - second) >= dis) {
			ans++;
			second = first;
		}
	}
	return (ans >= cnt);
}
int main()
{
	int n, cnt;
	cin >> n >> cnt;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	int ans = 1;
	int left = 1;
	int right =  v[n-1] - v[0];
	while (left <= right)
	{
		int mid =  ( left + right ) / 2 ;
		if (possible(v, cnt, mid))
		{
			if(ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}
	cout << ans;
}