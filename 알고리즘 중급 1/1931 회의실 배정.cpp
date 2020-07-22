#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> v, pair<int, int> v2)
{
	if (v.second == v2.second)
	{
		return v.first < v2.first;
	}
	return v.second < v2.second;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);

	vector<pair<int, int>> ans;
	ans.push_back(v[0]);
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first >= ans.back().second)
			ans.push_back(v[i]);
	}
	cout << ans.size();

}