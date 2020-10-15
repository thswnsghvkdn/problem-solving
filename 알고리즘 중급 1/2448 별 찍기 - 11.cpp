#include <iostream>
using namespace std;
char star[3100][6200]; // ���� ���� �迭

void draw_star(int row, int col, int size)// ���� �Ӹ� ��ǥ�� ����� �μ��� �޴´�.
{
	if (size == 3) // ����� 3�϶��� ���� ��´�.
	{
		star[row][col] = '*';
		star[row + 1][col - 1] = '*';
		star[row + 1][col + 1] = '*';
		for (int i = col - 2; i <= col + 2; i++) star[row + 2][i] = '*';
		return;
	}
	draw_star(row, col, size / 2);
	draw_star(row + (size / 2), col - (size / 2), size / 2);
	draw_star(row + (size / 2), col + (size / 2), size / 2);
}
int main()
{
	int size;
	cin >> size;
	draw_star(0, size-1, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size * 2- 1; j++)
		{
			if (star[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}
