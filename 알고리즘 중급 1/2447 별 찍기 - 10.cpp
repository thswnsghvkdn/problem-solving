#include <cstdio>

char ar[2200][2200];

void fill_star(int size, int row, int col)
{
	if (size == 1)
	{
		ar[row][col] = '*';
		return;
	}
	int div = size / 3;
	int cnt = 0;
	for(int i = 0 ; i < 3 ; i++)
		for (int j = 0; j < 3; j++)
		{
			cnt++;
			if(cnt != 5)
			fill_star(div, row + (i * div), col + (j * div ));
		}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ar[i][j] = ' ';

	fill_star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", ar[i][j]);
		printf("\n");
	}
}