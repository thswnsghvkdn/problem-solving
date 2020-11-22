#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int unmarked, marked;
int dx[] = { -1, 0 , 1, 0 }; // 위 오 아 왼 
int dy[] = { 0 , 1 , 0 ,-1 };
char map[31][31];
bool visit[31][31];
int ans = -1;
struct Point
{
	int x, y;
};
vector<Point> v;

void dfs(Point p , int dir, int cnt, int tot)
{
	if (cnt == unmarked)
	{
		if (ans == -1 || ans > tot)
			ans = tot;
		return;
	}
	int nx = p.x + dx[dir];
	int ny = p.y + dy[dir];
	if (!visit[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.') // 더 움직일수 있다면
	{
		visit[nx][ny] = true;
		dfs({ nx , ny }, dir, cnt + 1, tot);
		visit[nx][ny] = false;
	}

	else {
		for (int i = 0; i < 4; i++)
		{
			if (i == dir) continue;
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (!visit[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.')
			{
				visit[nx][ny] = true;
				dfs({ nx , ny }, i, cnt + 1, tot + 1);
				visit[nx][ny] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int index = 1;
	while (1)
	{
		cin >> n >> m;
		ans = -1;
		unmarked = 0;
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		v.clear();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) 
			{
				cin >> map[i][j];
				if (map[i][j] == '.') {
					v.push_back({ i,j });
					unmarked++;
				}
			}
		int v_size = v.size();
		if (unmarked != 1) {
			for (int i = 0; i < v_size; i++) {
				for (int k = 0; k < 4; k++) {
					visit[v[i].x][v[i].y] = true;
					dfs({ v[i].x , v[i].y }, k, 1, 1);
					visit[v[i].x][v[i].y] = false;
				}
			}
		}
		else
			ans = 0;
		cout << "Case "<< index << ": " << ans <<"\n";
		index++;
	}


}