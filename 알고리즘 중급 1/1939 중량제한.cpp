#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int land1, land2;

struct map {
	int opposite;
	int weight;
};

bool find_weight(vector<vector<map>>& v, int w)
{
	queue<int> q;
	vector<bool> visit(100000); // �湮 check
	visit[land1] = true;
	q.push(land1);

	while (!q.empty()) // �ش� ����ġ���� ū ������ ť�� �����ϴ� bfs
	{
		auto temp = q.front();
		if (temp == land2) return true; // bfs���� �������� ������ ��� ����
		q.pop();
		
		for (int i = 0; i < v[temp].size(); i++) // �μ��� ���� ���Ժ��� ū ����ġ�� ť�� ����
			if (v[temp][i].weight >= w && !visit[v[temp][i].opposite]) {
				visit[v[temp][i].opposite] = true;
				q.push(v[temp][i].opposite);
			}
	}
	return false; 
}


int main()
{
	int col, row;
	std::cin >> row >> col;
	
	vector<vector<map>> v(col + 1);

	int c, r, w;
	int max_dis = 0;
	for(int i = 0 ; i < col ; i++)
	{
		std::cin >> c >> r >> w;
		v[c].push_back({ r, w });
		v[r].push_back({ c, w });
		if (max_dis < w)
			max_dis = w;
	}
	std::cin >> land1 >> land2;
	int min_dis;


	for (int i = 0; i < v[land1].size(); i++) // �� ���� ����ġ�� �ּ� ������ ����
		if (v[land1][i].opposite == land2)
			min_dis = v[land1][i].weight;
	
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