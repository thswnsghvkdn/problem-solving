#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	bool answer;
	do {
		answer = true;
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v[i] % 3 == 0)
			{
				if (v[i] / 3 == v[i + 1])
					continue;
			}
			if (v[i] * 2 == v[i + 1]) continue;
			answer = false;
		}
		if (answer)
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			return 0;
		}
	} while (next_permutation(v.begin(), v.end()));


	return 0;
}