#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dx[] = { 0,0,1,-1, 0 };
int dy[] = { 1,-1,0,0, 0 };

struct Point {
	int time;
	int row;
	int col;
};
int c, r;
char map[50][50];
vector<vector<Point>> wall;


bool check_wall(int row, int col, int time)
{
	if (time + 1 >= wall.size())
	{
		vector<Point> v = wall[time];
		int size = wall[time].size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int nx = wall[time][i].row + dx[j];
				int ny = wall[time][i].col + dy[j];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c)
				{
					if (map[nx][ny] != 'X' && map[nx][ny] != 'D' && map[nx][ny] != '*')
					{
						map[nx][ny] = '*';
						v.push_back({ wall[time][i].time + 1 , nx, ny });
					}
				}
			}
		}

		wall.push_back(v);
	}


	for (int i = 0; i < wall[time+1].size(); i++)
	{
		if ( wall[time+1][i].row == row && wall[time+1][i].col == col)
			return false;
	}
	return true;
}
int main()
{
	cin >> r >> c;
	string s;
	queue<Point> q;
	vector<Point> v;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'S')
				q.push({ 0, i, j });
			if (s[j] == '*')
				v.push_back({ 0, i , j });
		}
	}
	wall.push_back(v);

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 5; i++) {
			int nx = temp.row + dx[i];
			int ny = temp.col + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			{
				if (check_wall(nx, ny, temp.time))
				{
					if (map[nx][ny] == 'D')
					{
						cout << temp.time + 1;
						return 0;
					}
					q.push({ temp.time + 1, nx, ny });
				}
			}
		}
	}

	cout << "KAKTUS";
	return 0;





}