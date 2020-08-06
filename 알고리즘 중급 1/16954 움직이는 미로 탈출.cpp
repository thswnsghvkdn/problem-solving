#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1, -1 ,-1, 1, 1, 0};
int dy[] = { 1,-1,0,0, -1 , 1,-1, 1, 0};
int map[10][8][8];

struct Point {
	int time;
	int row;
	int col;
};

int main()
{
	string s;
	queue<Point> q;
	for (int i = 0; i < 8; i++)
	{
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			if (s[j] == '.')
				map[0][i][j] = 0;
			else {
				map[0][i][j] = 1;
			}
		}
	}

	q.push({ 0 , 7 , 0 });

	// 각 시간에 따른(1초부터 8초까지) 벽의 정보를 저장한다.
	for(int t = 0 ;t < 8 ; t++)
		for(int i = 0 ; i < 8 ; i++ )
			for (int j = 0; j < 8; j++)
			{
				// 다음 시간대의 벽 정보를 저장
				if (map[t][i][j] == 1)
					map[t + 1][i + 1][j] = 1;
			}

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		if (p.time > 8)
		{
			cout << 1;
			return 0;
		}
		for (int i = 0; i < 9; i++)
		{
			int nx = p.row + dx[i];
			int ny = p.col + dy[i];
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{
				if (map[p.time][nx][ny] == 0 && map[p.time + 1][nx][ny] == 0) {
					if (nx == 0)
					{
						cout << 1;
						return 0;
					}
					q.push({ p.time + 1 , nx, ny });
				}
			}
		}
	}

	cout << 0;
	return 0;

}