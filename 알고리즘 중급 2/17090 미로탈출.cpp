#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int n, m;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };
string ar[501];
int visit[501][501];
int memo[501][501];
void init_visit()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
}
int CtoI(char ch)
{
	switch (ch)
	{
	case 'U':
		return 0;
	case 'R':
		return 1;
	case 'D':
		return 2;
	case 'L':
		return 3;
	}
}



int dfs(int x, int y, int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return 1;
	if (visit[x][y] != 0) return visit[x][y];

	visit[x][y] = -1; // 방문처리

	// if (cnt > 251001) return -1; stackoverflow 에러
	int dir = CtoI(ar[x][y]);
	visit[x][y] = dfs(x + dx[dir], y + dy[dir], cnt + 1);
	return visit[x][y];
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (dfs(i, j, 0) == 1) {
				cnt++;
			}
		}
	cout << cnt;
}