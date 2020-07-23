#include <iostream>
#include <stdio.h>
using namespace std;

int board_a[50][50];
int board_b[50][50];
int n, m;

void reverse(int r, int c)
{
	for(int i = r ; i < r + 3 ; i++)
		for (int j = c; j < c + 3; j++)
		{
			if (board_a[i][j]) board_a[i][j] = 0;
			else board_a[i][j] = 1;
		}

}


int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &board_a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &board_b[i][j]);

	int cnt = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
		{
			if (board_a[i][j] != board_b[i][j]) {
				reverse(i, j);
				cnt++;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board_a[i][j] != board_b[i][j])
			{
				cout << -1;
				return 0;
			}

	cout << cnt;

	return 0;
}