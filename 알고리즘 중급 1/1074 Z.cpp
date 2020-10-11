#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int ans;
int row, col;
void find_key(int n, int r, int c)
{
	if (r == row && c == col) {
		cout << ans; // 1�� z �������� ������ ����� ����Ѵ�.
		return;
	}
	if (!n) // 2�� 0������ �� ��쿡 1�� ���Ѵ�.
	{
		ans++;
		return;
	}
	int stand = pow(2, n - 1);
	find_key(n - 1, r, c);

	find_key(n - 1, r, c + stand);

	find_key(n - 1, r + stand, c);

	find_key(n - 1, r + stand, c + stand);



}

int main()
{
	int n;
	cin >> n >> row >> col;
	find_key(n, 0, 0);

	return 0;
}