#include <iostream>
#include <deque>

using namespace std;

char map[101][101];
char map_rg[101][101];
bool visit[101][101];
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0, 1 , 0 , -1 };


bool visit2[101][101];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			map_rg[i][j] = map[i][j];
			if (map_rg[i][j] == 'R')
				map_rg[i][j] = 'G';

		}

	deque<pair<int, int>> q;
	char alpha = 'Z'; // 이전 알파벳
	int cnt = 0;
	q.push_front(make_pair(0, 0));
	visit[0][0] = true;
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop_front();
		if (map[temp.first][temp.second] != alpha)
			cnt++; // 다른 알파벳이 나오면 블록 1증가
		alpha = map[temp.first][temp.second];

		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == alpha) q.push_front(make_pair(nx, ny));
			if (map[nx][ny] != alpha) q.push_back(make_pair(nx, ny));
			visit[nx][ny] = true;
		}
	}

	cout << cnt << ' ';

	alpha = 'Z'; // 이전 알파벳
	cnt = 0;
	q.push_front(make_pair(0, 0));
	visit2[0][0] = true;

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop_front();
		if (map_rg[temp.first][temp.second] != alpha)
			cnt++; // 다른 알파벳이 나오면 블록 1증가
		alpha = map_rg[temp.first][temp.second];

		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visit2[nx][ny]) continue;
			if (map_rg[nx][ny] == alpha) q.push_front(make_pair(nx, ny));
			if (map_rg[nx][ny] != alpha) q.push_back(make_pair(nx, ny));
			visit2[nx][ny] = true;
		}
	}

	cout << cnt;
}