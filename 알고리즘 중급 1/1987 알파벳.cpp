#include <iostream>
using namespace std;
char board[20][20];
char alpha[30];
int max = -1;
int dx[] = { -1, 0 , 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int r, c;

void go(int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		char al = board[nx][ny];
		
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (!alpha[al - 'A'])
			{
				alpha[al - 'A'] = true;
				go(nx, ny, cnt + 1);
				alpha[al - 'A'] = false;
			}
			else if (max == -1 || max < cnt) {
				max = cnt;
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	alpha[board[0][0] - 'A'] = true;
	go(0, 0, 1);
	cout << max;
}