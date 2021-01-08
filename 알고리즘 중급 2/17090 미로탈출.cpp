#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int n, m;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };
string ar[501];
bool visit[501][501];

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
	case 'U' :
		return 0;
	case 'R':
		return 1;
	case 'D':
		return 2;
	case 'L':
		return 3;
	}
}

int exit(int x, int y)
{
	int nr = x;
	int nc = y;
	visit[nr][nc] = true;
	do
	{
		int dir = CtoI(ar[nr][nc]);
	    nr = nr + dx[dir];
		nc = nc + dy[dir];
		if (visit[nr][nc]) return 0;
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) return 1;
		visit[nr][nc] = true;
	} while (1);

	return 0;
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
			cin >> ar[i];

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (exit(i, j) == 1) {
				cnt++;
				init_visit();
			}
		}
	cout << cnt;
}