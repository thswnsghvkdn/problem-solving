#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, l_index = 0 , r_index = 0;
	cin >> n >> m;

	vector<int> v1(n);
	vector<int> v2(m);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	for (int i = 0; i < m; i++)
		cin >> v2[i];
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());


	while (1) {
		if (l_index == v1.size() || r_index == v2.size())
			break;
		v1[l_index] < v2[r_index] ? (cout << v1[l_index++] << ' ') : (cout << v2[r_index++] << ' ');
	}
	if (l_index == v1.size())
		for (; r_index < v2.size(); r_index++)
			cout << v2[r_index] << ' ';
	else 
		for (; l_index < v1.size(); l_index++)
			cout << v1[l_index] << ' ';

	return 0;
}