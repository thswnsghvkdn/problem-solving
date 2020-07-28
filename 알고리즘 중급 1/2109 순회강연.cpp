#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](pair<int, int >a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second < b.second;
		});
	queue<pair<int, int>> q;
	int day = -1;
	q.push(v[0]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (day != v[i].second)
		{
			ans += v[i].first;
			day = v[i].second;
		}
	}
	cout << ans;
}