#include <iostream>

using namespace std;


int main()
{
	int x, y, z, n, m;
	cin >> x >> y >> z >> n >> m;

	z *= 2; 
	long long ans = 0;
	if (z <= (x + y))
	{
		if (n <= m) {
			ans = z * n;
			m = m - n;
			z <= y ? ans += z * m : ans += y * m;
		}
		else {
			ans = z * m;
			n = n - m;
			z <= x ? ans += z * n : ans += x * n;
		}
	}
	else 
		ans = (x * n) + (y * m);
	
	cout << ans;
}