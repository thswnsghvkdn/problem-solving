#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ar[1000];
	int sum[1000];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	int tot = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		tot += ar[i];
		sum[i] = tot;
		ans += sum[i];
	}
	cout << ans;
}