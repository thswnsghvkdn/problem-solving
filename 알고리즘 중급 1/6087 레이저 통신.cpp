#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visit[101][101];
char map[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int row, col;

struct Point {
	int x, y, dir, cnt;
};
int main()
{
	cin >> col >> row;
	queue < Point> q;
	
	pair<int, int> start, end;
	int n= 0;
	for(int i = 0 ; i < row ; i++)
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C' && n == 0)
			{
				start.first = i;
				start.second = j;
				n++;
			}
			if (map[i][j] == 'C' && n != 0)
			{
				end.first = i;
				end.second = j;
			}
			visit[i][j] = 10000;
		}

	for (int i = 0; i < 4; i++)
		q.push({ start.first , start.second,i , 0 });

	while (!q.empty()) // 모든 좌표에대해 방향과 비교하여 거울의 개수를 갱신한다. 
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir; // 방향
		int cnt = q.front().cnt; // 거울 개수
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mirror = cnt; // 좌표에 해당하는 거울개수
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

			if (map[nx][ny] != '*')
			{
				if (i != dir) // 방향이 다르면 거울을 추가한다
					mirror++;			
				if (visit[nx][ny] >= mirror) // 해당 죄표에 대해 거울의 최소개수 갱신
				{
					visit[nx][ny] = mirror;
					q.push({ nx, ny, i, mirror });
				}
			}
		}
	}

	cout << visit[end.first][end.second];
}