#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int ans;
int r, c;
void find_key(int n, int row, int col)
{
	if (r == row && c == col) {
		cout << ans; // z �������� ������ ����� ����Ѵ�.
		return;
	}

	int stand = pow(2, n - 1); // ��� ���� ������ ���� ������ �ݸ�ŭ ������ų ��

	// 1���� ���ǽ�
	if (row <= r && r < (row + stand) && col <= c && c < (col + stand)) 
		find_key(n - 1, row, col);
	ans += ( pow(2, n - 1) * pow(2, n - 1) ); // 1������ �ƴ� ��� 1������ ���� ���信 ���Ѵ�. 

	if (row <= r && r < (row + stand) && (col + stand) <= c  && c < (col + 2 * stand))
		find_key(n - 1, row, col + stand);
	ans += (pow(2, n - 1) * pow(2, n - 1)); // 2������ �ƴ� ��� 2������ ���� ���信 ���Ѵ�. 

	if ( (row + stand) <= r && r < (row + 2 * stand) && col <= c && c < (col + stand))
		find_key(n - 1, row + stand, col);

	ans += (pow(2, n - 1) * pow(2, n - 1)); // 3������ �ƴ� ��� 3������ ���� ���信 ���Ѵ�. 
	if ((row + stand) <= r && r < (row + 2 * stand) && (col + stand) <= c && c < (col + 2 * stand))
		find_key(n - 1, row + stand, col + stand);

}

int main()
{
	int n;
	cin >> n >> r >> c;
	find_key(n, 0, 0);

	return 0;
}