#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int dx[] = { -1, 0 , 1, 0 }; // 위 오 아 왼 
int dy[] = { 0 , 1 , 0 ,-1 };
char map[31][31];
int ans = -1;
struct Point
{
	int x, y;
};

void copyMap(char map[31][31], char map2[31][31])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map2[i][j] = map[i][j];
}
void moveMap(Point p , int dir)
{
	while (1)
	{
		int nx = p.x + dx[dir];
		int ny = p.y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		if (map[nx][ny] == '*' || map[nx][ny] == '1') return;
		map[nx][ny] = '1';
	}
}
bool checkMap()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == '.') return false;
	return true;
}
bool check(Point p)
{
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m)
		return false;
	if (map[p.x][p.y] == '*' || map[p.x][p.y] == '1')
		return false;
	return true;
}
int checkWay(Point p) // 4방향의 상대적위치를 반환
{
	int x0 = p.x + dx[0], y0 = p.y + dy[0];
	int x1 = p.x + dx[1], y1 = p.y + dy[1];
	int x2 = p.x + dx[2], y2 = p.y + dy[2];
	int x3 = p.x + dx[3], y3 = p.y + dy[3];
	bool flag0 = check({ x0 , y0 });
	bool flag1 = check({ x1 , y1 });
	bool flag2 = check({ x2 , y2 });
	bool flag3 = check({ x3 , y3 });

	// 두 방향다 갈 수 있다면 0을 반환
	if (flag0 && flag2) return 0;
	if (flag1 && flag3) return 0;
	if (!flag0 && !flag2 && !flag1 && !flag3) return -1; // 4방향다 갈 수 없다면 -1반환

	if (flag0) return 1;
	if (flag1) return 2;
	if (flag2) return 3;
	if (flag3) return 4;

}
void dfs(Point p , int dir, int count)
{
	char backup[31][31];
	copyMap(map, backup);
	int x0 = p.x + dx[0], y0 = p.y + dy[0];
	int x1 = p.x + dx[1], y1 = p.y + dy[1];
	int x2 = p.x + dx[2], y2 = p.y + dy[2];
	int x3 = p.x + dx[3], y3 = p.y + dy[3];
	bool flag0 = check({ x0 , y0 });
	bool flag1 = check({ x1 , y1 });
	bool flag2 = check({ x2 , y2 });
	bool flag3 = check({ x3 , y3 });
	int n_dir = checkWay(p);
	if (n_dir == -1)
	{
		checkMap();
		if (ans != -1 || ans > count)
			ans = count;
		return;
	}
	if (n_dir == 0)
		return;
	if (dir == 4)
	{
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == '*' || map[nx][ny] == '1') continue;
			dfs({ nx, ny }, i, 1);
		}
	}
	else if (dir == 0 || dir == 2)
	{
		if (flag1) dfs({ x1 , y1 }, 1, count + 1);
		if (flag3) dfs({ x3 , y3 }, 3, count + 1);
	}
	else
	{
		if (flag0) dfs({ x0 , y0 }, 0, count + 1);
		if (flag2) dfs({ x2 , y2 }, 2, count + 1);
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}