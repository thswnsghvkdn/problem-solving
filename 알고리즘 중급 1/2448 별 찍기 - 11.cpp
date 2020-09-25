#include <iostream>

using namespace std;

char ar[3100][6200];

void print_star(int row, int col)
{
	ar[row][col] = '*';
	ar[row + 1][col - 1] = '*';
	ar[row + 1][col + 1] = '*';
	for (int i = col - 2; i < col + 3; i++)
		ar[row + 2][i] = '*';
}

void rec_star(int high, int row, int col)
{
	if (high == 3)
	{
		print_star(row, col);
		return;
	}
	int n_high = high / 2;
	rec_star(n_high , row, col);
	rec_star(n_high, row + n_high, col - n_high);
	rec_star(n_high, row + n_high, col + n_high);

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n - 1; j++)
			ar[i][j] = ' ';
	rec_star(n, 0, n  - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++)
			cout << ar[i][j];
		cout << "\n";
	}
}