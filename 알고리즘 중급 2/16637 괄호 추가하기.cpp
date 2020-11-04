#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<long long> v;
vector<char> v2;
int length;
long long ans;

long long cal(long long n1, long long n2, char op)
{
	long long ans;
	switch (op)
	{
	case '+':
		ans = n1 + n2;
		break;
	case '-':
		ans = n1 - n2;
		break;
	case '*':
		ans = n1 * n2;
		break;
	case '/':
		ans = n1 / n2;
		break;
	}
	return ans;
}

void dfs(int index, long long tot)
{
	if (index == length)
	{
		ans = max(ans, tot);
		return;
	}
	if (index + 1 <= length) {
		int temp = cal(tot, v[index + 1], v2[index]);
		dfs(index + 1, temp);
	}
	if (index + 2 <= length)
	{
		int temp = cal(v[index + 1], v[index + 2], v2[index + 1]);
		dfs(index + 2, cal(tot, temp, v2[index]));
	}
}


int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int index1 = 0, index2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			v2.push_back(s[i]);
		else
			v.push_back(s[i] - '0');
	}
	length = n / 2;
	dfs(0, v[0]);

	cout << ans;
}