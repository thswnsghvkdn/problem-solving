#include <iostream>
using namespace std;
int n = 9;
int sdoku[10][10];
bool check_r[10][10];
bool check_c[10][10];
bool check_square[10][10];
int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

bool go(int z)
{
	if (z == 81)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << sdoku[i][j] << ' ';
			cout << "\n";
		}
		return true;
	}

	int i = z / n;
	int j = z % n;

	if (sdoku[i][j])
		return go(z + 1);

	else {
		for (int a = 1; a <= n; a++)
		{
			if (check_r[i][a] == false && check_c[j][a] == false && check_square[square(i, j)][a] == false)
			{
				check_r[i][a] == true;
				check_c[j][a] == true;
				check_square[square(i, j)][a] == true;
				sdoku[i][j] = a;
				if (go(z + 1))
				{
					return true; // 스도쿠가 하나라도 나왔다면 이 조건문을 타고가면서 다음 동작을 스킵한다.
				}
				sdoku[i][j] = 0;
				check_r[i][a] == false;
				check_c[j][a] == false;
				check_square[square(i, j)][a] == false;
			}
		}
	}
	return false;
}
int main()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> sdoku[i][j];
			if (sdoku[i][j])
			{
				check_r[i][sdoku[i][j]] = true;
				check_c[j][sdoku[i][j]] = true;
				check_square[square(i, j)][sdoku[i][j]] = true;
			}
		}
	go(0);
}
