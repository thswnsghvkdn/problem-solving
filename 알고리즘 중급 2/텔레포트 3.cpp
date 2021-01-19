#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

long long dist(long long x1, long long x2, long long y1, long long y2)
{
	return abs((x1)-(x2)) + abs((y1)-(y2));
}
struct Point {
	long long start, end;
};
vector<pair<Point, Point>> v(7);
vector<int> pri(7);

int main()
{
	long long xs, ys;
	long long xe, ye;
	cin >> xs >> ys >> xe >> ye;
	long long ans = INT_MAX;

	for (int i = 0; i < 6; i += 2) {
		cin >> v[i].first.start >> v[i].first.end >> v[i].second.start >> v[i].second.end;
		v[i + 1].first = v[i].second;
		v[i + 1].second = v[i].first;
	}
	v[6].first.start = xe;
	v[6].first.end = ye;
	v[6].second.start = xe;
	v[6].second.end = ye;

	for (int i = 0; i < 7; i++)
		pri[i] = i;

	do
	{
		int nx = xs, ny = ys;
		long long t = 0;
		for (int i = 0; i < 7; i++)
		{
			t += dist(nx, v[pri[i]].first.start, ny, v[pri[i]].first.end);
			if (v[pri[i]].second.start == xe && v[pri[i]].second.end == ye) break;
			t += 10;
			nx = v[pri[i]].second.start;
			ny = v[pri[i]].second.end;
		}
		if (t < ans)
			ans = t;
	} while (next_permutation(pri.begin(), pri.end()));

	cout << ans;
}