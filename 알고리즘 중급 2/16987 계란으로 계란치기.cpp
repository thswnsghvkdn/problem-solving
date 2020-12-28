#include <iostream>
#include <algorithm>
using namespace std;

int duration[10];
int weight[10];
int n;
int brokenEgg;

void dfs(int idx, int egg)
{
	if (idx >= n)
	{
		brokenEgg = max(brokenEgg, egg);
		return;
	}

	if (duration[idx] <= 0) {
		dfs(idx + 1, egg);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int t_egg = 0; // 한번 충돌에 깨진 계란 수 복구를 하기위한 변수이다.
		if (i == idx) continue;
		if (duration[i] <= 0)
		{
			dfs(idx + 1, egg);
			continue;
		}
		duration[idx] -= weight[i];
		duration[i] -= weight[idx];
		if (duration[idx] <= 0) {
			egg++;
			t_egg++;
		}
		if (duration[i] <= 0) {
			egg++;
			t_egg++;
		}
		dfs(idx + 1, egg);
		duration[idx] += weight[i];
		duration[i] += weight[idx];
		egg -= t_egg;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> duration[i] >> weight[i];
	dfs(0, 0);
	cout << brokenEgg;
}