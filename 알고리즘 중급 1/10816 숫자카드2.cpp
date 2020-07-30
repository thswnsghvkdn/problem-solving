#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int m;
	cin >> m;
	vector<int> v2(m);
	int temp;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		auto it1 = lower_bound(v.begin(), v.end(), temp);
		auto it2 = upper_bound(v.begin(), v.end(), temp);
		v2[i] = (it2 - it1);

	}
	for (int i = 0; i < m; i++)
		cout << v2[i] << ' ';
}