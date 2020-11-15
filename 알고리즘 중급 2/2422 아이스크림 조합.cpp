#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, int>>v;
int flavor[201][201];
bool visit[201];
bool hate[201];
int tot;
void dfs(int count, int index)
{
	if (count == 3)
	{
		tot++;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (flavor[index][i]) hate[i] = true;
	for (int i = index; i <= n; i++)
	{
		if (visit[i] || hate[i]) continue;
		visit[i] = true;
		dfs(count + 1, i);
		visit[i] = false;
	}
	for (int i = 1; i <= n; i++)
		if (flavor[index][i]) hate[i] = false;
}
int main()
{
	cin >> n >> m;
	int t1, t2;
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		flavor[t1][t2] = true;
	}
	for (int i = 1; i <= n; i++) {
		visit[i] = true;
		dfs(1, i);
		visit[i] = false;
	}
	cout << tot;
}