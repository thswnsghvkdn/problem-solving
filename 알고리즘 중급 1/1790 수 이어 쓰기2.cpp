#include <iostream>
#include <string>
using namespace std;
long long digit(int k)
{
	long long ans = 0;
	for (int start = 1, len = 1; start <= k; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > k) {
			end = k;
		}
		ans += (long long)(end - start + 1) * len;
	}
	return ans;
}

int main() {
	int n, k;
	
	cin >> n >> k;

	if (digit(n) < k) {
		cout << -1;
		return 0;
	}
	int cen, start, end;
	start = 1; 
	end = k;
	int ans = 0;

	// k범위 내에 들어오는 digit(cen)값을 구한다. 
	while (start <= end)
	{
		cen = (end + start) / 2;
		long long temp = digit(cen);

		if (temp <  k)
		{
			start = cen + 1;
		}
		else
		{
			ans = cen;
			end = cen - 1;
		}
	}
	// k범위 내에 들어온 l 값을 k값과 비교하여 정확한 숫자를 찾는다.
	string s = to_string(ans);
	long long l = digit(ans);
	cout << s[s.length() - (l - k) - 1];

}