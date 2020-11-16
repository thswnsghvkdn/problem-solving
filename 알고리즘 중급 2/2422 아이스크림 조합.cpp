#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int firstFlavor;
int flavor[201][201];
int n, m;
int ans;
void dfs(int* visit, int index, int count)
{
	for (int i = index + 1; i <= n; i++)
	{
		if (visit[i] == false && flavor[firstFlavor][i] == false) {
			if (count == 2) // 이미 두가지 맛이 선택되어있다면
				ans++;
			else
				dfs(flavor[i], i, count++);
		}
	}
}

int main()
{
	cin >> n >> m;
	int temp1, temp2;
	for (int i = 1; i <= m; i++)
	{
		cin >> temp1 >> temp2;
		flavor[temp1][temp2] = true;
		flavor[temp2][temp1] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		firstFlavor = i;
		dfs(flavor[i], i, 1);
	}
	cout << ans;
}