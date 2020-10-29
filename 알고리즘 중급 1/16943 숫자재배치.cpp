#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int b;
int ans = -1;
vector<int> v;

void isBig()
{
	int temp = 0;
	for (int i = 0; i < v.size(); i++, temp *= 10)
	{
		if (temp == 0 && v[i] == 0) temp = 10;
		else temp += v[i];
	}
	temp /= 10;
	if (temp <= b) ans = max(ans, temp);
}

int main()
{
	int a;
	cin >> a >> b;
	while (a)
	{
		int temp = a % 10;
		v.push_back(temp);
		a /= 10;
	}
	sort(v.begin(), v.end());
	do {
		isBig();
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
}