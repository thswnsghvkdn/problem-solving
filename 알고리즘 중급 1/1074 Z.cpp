#include <iostream>
#include <cmath>
using namespace std;

int ans;
int row, col;
void rec(int size, int r, int c)
{
	int range = size / 2;
	if (size == 2)
	{
		if (row % 2)
		{
			ans += (2 + col % 2);
			return;
		}
		ans += (col % 2);
		return;
	}
	if (row >= r && row < r + range && col >= c && col < c + range) {
		rec(range, r, c);
		return;
	}
	ans += (range * range);

	if (row >= r && row < r + range && col >= c + range && col < c + size) {
		rec(range, r, c + range);
		return;
	}
	ans += (range * range);

	if (row >= r + range && row < r + size && col >= c && col < c + range) {
		rec(range, r + range, c);
		return;
	}
	ans += (range * range);
	
	if (row >= r + range && row < r + size && col >= c + range && col < c + size)
		rec(range, r + range, c + range);

}


int main()
{
	int size;
	cin >> size >> row >> col;

	rec(pow(2, size), 0, 0);
	cout << ans;
}