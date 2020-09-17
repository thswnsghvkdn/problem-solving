#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> v;
void hannoi(int from, int by, int to, int num)
{
	if (num == 1)
	{
		v.push_back(make_pair(from, to));
		return;
	}
	hannoi(from, to, by, num - 1);
	v.push_back(make_pair(from, to));
	hannoi(by, from, to, num - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	hannoi(1, 2, 3, n);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
}