#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), [](pair<int, int > a, pair<int, int > b) {
		return a.second > b.second;
		});

	priority_queue<int> q;
	int limit = 0; // 받은 오퍼의 제한
	int ans = 0; // 총합

	// day는 10000일 부터 하루씩 감소합니다. 
	for (int day = 10000; day > 0; day--)
	{
		// day가 감소하다가 받은 오퍼에 날짜와 같은 경우
		while (n > limit && v[limit].second == day) // 같은 오퍼에 day를  pay 기준으로 우선순위 큐에 삽입하면서 pay를 정렬합니다.
		{
			q.push(v[limit].first);
			limit++;
		}
		// 해당 day에 받을 수 있는 최고 금액을 합산합니다.
		if (!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}
	cout << ans;
}