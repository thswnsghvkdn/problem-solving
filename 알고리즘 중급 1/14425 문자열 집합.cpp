#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int  n, m;
	cin >> n >> m;
	string temp;
	vector<string> v1, v2;
	for (int i = 0; i < n + m; i++)
	{
		cin >> temp;
		if (i >= n) v2.push_back(temp);
		else v1.push_back(temp);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i] == v2[j]) cnt++;
		}
	}
	cout << cnt;
}