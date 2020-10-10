#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int ans;
int row, col;
void find_key(int n, int r, int c)
{
	if (r == row && c == col) {
		cout << ans;
		return;
	}
	if (!n) return;
	int stand = pow(2, n - 1);
	find_key(n - 1, r, c);
	ans += pow(2, n);
	find_key(n - 1, r, c + stand);
	ans += pow(2, n);
	find_key(n - 1, r + stand, c);
	ans += pow(2, n);
	find_key(n - 1, r + stand, c + stand);
	ans += pow(2, n);



}

int main()
{
	int n;
	cin >> n >> row >> col;
	//find_key(n, 0, 0);

	return 0;
}