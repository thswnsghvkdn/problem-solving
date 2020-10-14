#include <iostream>

char star[6570][6570];

using namespace std;

void draw_star(int row, int col, int num)
{
	if (num == 3) {
		for(int i = 0 ; i < 3 ; i++)
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) continue;
				star[row + i][col + j] = '*';
			}

		return;
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int nx = i * ( num / 3 );
			int ny = j * ( num / 3 );
			if (i == 1 && j == 1) continue;
			draw_star(row + nx, col + ny, num / 3);
		}
}

int main()
{
	int num;
	cin >> num;
	draw_star(0, 0, num );

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (star[i][j] == '*')
				cout << star[i][j];
			else
				cout << ' ';
		}
		cout << "\n";
	}
}