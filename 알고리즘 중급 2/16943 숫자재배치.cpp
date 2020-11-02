#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int A, B, C;
int tot = 0;
bool visit[10];
bool possible = false;


void dfs(int ans, int cnt)
{
	if (cnt == v.size())
	{
		if (ans <= B) {
			tot = max(tot, ans);
			possible = true;
		}
		return;
	}
	for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0 && ans == 0) continue;
			if (!visit[i]) {
				visit[i] = true;
				int tmp = ans;
				ans = ans * 10 + v[i];
				dfs(ans, cnt + 1);
				visit[i] = false;
				ans = tmp;
			}
		}
	
}
int main()
{
	cin >> A >> B;
	int n = A;
	while (n > 0)
	{
		int temp = n % 10;
		v.push_back(temp);
		n /= 10;
	}
	dfs(0, 0);
	if (possible) cout << tot;
	else cout << -1;
}