#include <iostream>
#include <queue>
using namespace std;

int board[10][10];
int visit[10][10];
int n, m;
int dx[] = { -1, 0,1,0 };
int dy[] = { 0, 1, 0, -1 };


int bfs()
{
	memset(visit, 0, sizeof(visit));
	int n_board[10][10];
	memcpy(n_board, board, sizeof(board));
	queue<pair<int, int>> q;
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 2)
				q.push(make_pair(i, j));
		
	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int nx, ny;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (n_board[nx][ny] == 0)
				{
					n_board[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (n_board[i][j] == 0)
				cnt++;
	return cnt;
}

int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int ans = 0;

	int x1, x2, x3;
	int y1, y2, y3;
	for (x1 = 0; x1 < n; x1++) {
		for (y1 = 0; y1 < m; y1++) {
			if (board[x1][y1] != 0) continue;
			for (x2 = 0; x2 < n; x2++) {
				for (y2 = 0; y2 < m; y2++) {					
					if (board[x2][y2] != 0) continue;
					if (x1 == x2 && y1 == y2) continue;
					for (x3 = 0; x3 < n; x3++) {
						for (y3 = 0; y3 < m; y3++)
						{
							if (board[x3][y3] != 0) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;


							board[x1][y1] = 1;
							board[x2][y2] = 1;
							board[x3][y3] = 1;
							
							int t = bfs();
							if (ans < t) ans = t;


							board[x1][y1] = 0;
							board[x2][y2] = 0;
							board[x3][y3] = 0;

						}
					}
				}
			}
		}
	}

	cout << ans;
}