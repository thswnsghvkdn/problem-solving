#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> v[4];
map<long long, long long> mp;

int main()
{
	
	int n , t;
	cin >> n;
	for(int i =0 ;  i < n ; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> t;
			v[j].push_back(t);
		}

	long long sum;
	for (int i = 0; i < n; i++) {
		sum = v[0][i];
		for (int j = 0; j < n; j++)
		{
			mp[ sum + v[1][j] ]++;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		sum = v[2][i];
		for (int j = 0; j < n; j++)
		{
			ans += mp[ -(sum + v[3][j])];
		}
	}

	cout << ans;
}