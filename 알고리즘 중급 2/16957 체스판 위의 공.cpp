#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int ar[502][502];
int tot[502][502];
int dx[] = { -1, -1, -1, 0 ,1 , 1, 1, 0 };
int dy[] = { -1, 0, 1, 1,1, 1, 0, -1,-1 };

struct point
{
	int x, y;
};
point visit[502][502];

point check(int x, int y)
{
	point m_point = { 0 , 0 };
	int m_int = 300001;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
		if (ar[x][y] > ar[nx][ny])
		{
			if (m_int > ar[nx][ny])
			{
				m_point = { nx , ny };
				m_int = ar[nx][ny];
			}
		}
	}
	return m_point;
}

point dfs(int x, int y)
{
	if (visit[x][y].x != 0) return visit[x][y];
	point t = check(x, y);
	if (t.x == 0) {
		visit[x][y].x = x;
		visit[x][y].y = y;
		return visit[x][y];
	}
	visit[x][y] = dfs(t.x, t.y);
	return visit[x][y];
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> ar[i][j];
	
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			visit[i][j] = dfs(i, j);

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			tot[visit[i][j].x][visit[i][j].y]++;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			cout << tot[i][j] << ' ';
		cout << endl;
	}
}