#include <iostream>
#include <deque>
#include <queue>
using namespace std;

char map[101][101];
char map_rg[101][101];
bool visit[101][101];
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0, 1 , 0 , -1 };


bool visit2[101][101];
int n;
int cnt;
queue<pair<int, int >> q;

void bfs()
{
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		visit[temp.first][temp.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == map[temp.first][temp.second]) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
		}
	}
}
void bfs2()
{
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		visit2[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visit2[nx][ny]) continue;
			if (map_rg[nx][ny] == map_rg[temp.first][temp.second]) {
				q.push(make_pair(nx, ny));
				visit2[nx][ny] = true;
			}
		}
	}
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			map_rg[i][j] = map[i][j];
			if (map_rg[i][j] == 'R')
				map_rg[i][j] = 'G';

		}

	cnt = 0;

	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				cnt++;
				q.push(make_pair(i, j));
				bfs();
			}
		}
	

	cout << cnt << ' ';

	cnt = 0;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!visit2[i][j]) {
				cnt++;
				q.push(make_pair(i, j));
				bfs2();
			}
		}

	

	cout << cnt;
}