#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> friends[4001];
bool friendship[4001][4001];
int n, m;
int ans = -1;
int first;
void dfs(int cnt, int index, int size)
{
	if (cnt == 3 && friendship[first][index])
	{
		if (ans == -1 || ans > size)
			ans = size;
		return;
	}
	for (int i = 0; i < friends[index].size() ; i++)
	{
		int temp_num = friends[index][i];
		int temp_size = size;
		if (temp_num <= index || friends[temp_num].size() < 2) continue;
		temp_size += friends[temp_num].size() - 2;
		dfs(cnt + 1, temp_num, temp_size);
	}

}

int main()
{
	cin >> n >> m;
	int t1, t2;
	for (int i = 1; i <= m; i++)
	{
		cin >> t1 >> t2;
		friends[t1].push_back(t2);
		friends[t2].push_back(t1);
		friendship[t1][t2] = friendship[t2][t1] = true;
	}
	for (int i = 1; i <= m; i++)
		sort(friends[i].begin(), friends[i].end());
	for (int i = 1; i <= m; i++) {
		first = i;
		if (friends[i].size() < 2) continue;
		dfs(1, i, friends[i].size() - 2);
	}
	cout << ans;
}