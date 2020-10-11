#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int ans;
int r, c;
void find_key(int n, int row, int col)
{
	if (r == row && c == col) {
		cout << ans; // z 방향으로 증가한 결과를 출력한다.
		return;
	}

	int stand = pow(2, n - 1); // 행과 열이 증가할 기준 지수의 반만큼 증가시킬 것

	// 1구역 조건식
	if (row <= r && r < (row + stand) && col <= c && c < (col + stand)) 
		find_key(n - 1, row, col);
	ans += ( pow(2, n - 1) * pow(2, n - 1) ); // 1구역이 아닐 경우 1구역의 합을 정답에 더한다. 

	if (row <= r && r < (row + stand) && (col + stand) <= c  && c < (col + 2 * stand))
		find_key(n - 1, row, col + stand);
	ans += (pow(2, n - 1) * pow(2, n - 1)); // 2구역이 아닐 경우 2구역의 합을 정답에 더한다. 

	if ( (row + stand) <= r && r < (row + 2 * stand) && col <= c && c < (col + stand))
		find_key(n - 1, row + stand, col);

	ans += (pow(2, n - 1) * pow(2, n - 1)); // 3구역이 아닐 경우 3구역의 합을 정답에 더한다. 
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