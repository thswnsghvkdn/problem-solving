#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100010

using namespace std;

int land1, land2;

struct map {
	int opposite;
	int weight;
};

bool find_weight(vector<vector<map>>& v, int w)
{
	queue<int> q;
	vector<bool> visit(10010); // 방문 check
	visit[land1] = true;
	q.push(land1);

	while (!q.empty()) // 해당 가중치보다 큰 값만을 큐에 삽입하는 bfs
	{
		auto temp = q.front();
		if (temp == land2) return true; // bfs도중 목적지에 도착한 경우 종료
		q.pop();

		for (int i = 0; i < v[temp].size(); i++) // 인수로 들어온 무게보다 큰 가중치만 큐에 삽입
			if (v[temp][i].weight >= w && !visit[v[temp][i].opposite])
			{
				visit[v[temp][i].opposite] = true;
				q.push(v[temp][i].opposite);
			}
	}
	return false;
}


int main()
{
	int col, row;
	cin >> row >> col;

	vector<vector<map>> v(col + 10);

	int c, r, w;
	int max_dis = 0;
	for (int i = 0; i < col; i++)
	{
		cin >> c >> r >> w;
		v[c].push_back({ r, w });
		v[r].push_back({ c, w });
		if (max_dis < w)
			max_dis = w;
	}
	cin >> land1 >> land2;
	int min_dis = 0;

	int ans = min_dis;
	while (min_dis <= max_dis)
	{
		int mid = (min_dis + max_dis) / 2;
		if (find_weight(v, mid))
		{
			min_dis = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else
			max_dis = mid - 1;
	}
	cout << ans;
}