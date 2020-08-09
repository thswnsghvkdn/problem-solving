#include <iostream>
#include <deque>

using namespace std;

struct Point {
	int row;
	int col;
	int type;
};
int dx[] = { 1,-1,0,0 }; 
int dy[] = { 0,0,1,-1 }; 
char map[51][51];
deque<Point> d;

int cnt = 0;
int col, row;
int ar[] = { 0 , 0 };
int Dx, Dy;
int Sx, Sy;
bool ans = false;

void bfs()
{
	while (!d.empty())
	{

		auto p = d.front();
		d.pop_front();

		if (ar[0] == 0)
		{
			ar[0] = ar[1];
			ar[1] = 0;
			cnt++;
		}

		if (p.type == 2)
		{
			if (p.row == Dx && p.col == Dy)
			{
				ans = true;
				return;
			}
			ar[0] -= 1;
			for (int i = 0; i < 4; i++) {
				int nx = p.row + dx[i];
				int ny = p.col + dy[i];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && (map[nx][ny] == 'D' || map[nx][ny] == '.'))
				{
					if (map[nx][ny] == 'D')
						map[nx][ny] = 'D';
					else
						map[nx][ny] = 'S';
					ar[1]++;
					d.push_back({ nx,ny,2 });
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = p.row + dx[i];
				int ny = p.col + dy[i];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && map[nx][ny] != '*' && map[nx][ny] != 'X' && map[nx][ny] != 'D')
				{
					map[nx][ny] = '*';
					d.push_back({ nx,ny,1 });
				}
			}
		}
	}

	return;
}
int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
			{
				d.push_front({ i,j,1 });
			}
			if (map[i][j] == 'S')
			{
				ar[0]++;
				d.push_back({ i, j, 2 });
			}
			if (map[i][j] == 'D')
			{
				Dx = i;
				Dy = j;
			}
		}
	}

	bfs();
	if (ans)
		cout << cnt;
	else
		cout << "KAKTUS";
}