#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<long long, long long> mp;
vector<long long> v;
vector<long long> v2;
long long tot, n, m;
int main()
{
	cin >> tot;
	cin >> n;
	long long t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		v2.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += v[j];
			mp[sum]++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += v2[j];
			ans += mp[tot - sum];
		}
	}

	cout << ans;
}