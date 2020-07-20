#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -2, -2, 0 , 0, 2 ,2 };
int dy[] = { -1, 1, -2,  2,-1,1 };
int n;
int board[205][205];
int dist[205][205];

int main()
{
	int x1, y1, x2, y2, nx , ny;
	cin >> n;
	cin >> x1 >> y1 >> x2 >> y2;
	board[x1][y1] = 1;
	board[x2][y2] = -1;
	queue<pair<int, int>> q;
	q.push(make_pair(x1, y1));
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			nx = temp.first + dx[i];
			ny = temp.second + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (board[nx][ny] == -1)
				{
					dist[nx][ny] = dist[temp.first][temp.second] + 1;
					cout << dist[nx][ny];
					return 0;
				}

				if (board[nx][ny] == 0)
				{
					board[nx][ny] = 1;
					dist[nx][ny] = dist[temp.first][temp.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	cout << -1;

	return 0;
}