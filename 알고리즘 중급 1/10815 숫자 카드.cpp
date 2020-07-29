#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int m, temp;
	cin >> m;
	vector<int> v2(m);

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (binary_search(v.begin(), v.end(), temp))
			v2[i] = 1;
		else
			v2[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cout << v2[i] << ' ';
	}
}