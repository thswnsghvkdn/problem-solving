#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num; // ������ ����
vector<int> v; // �������� 
int ans = -1;
bool check() // �������� �˻�
{
	int d = v[0] - v[1]; // ����
	for (int i = 1; i < v.size() - 1; i++)
		if (d != (v[i] - v[i + 1])) return false; // ���� �˻�
	return true;
}
void dfs(int cnt, int index) // 
{
	if (index == v.size()) return;
	if (check()) {
		if (ans == -1 || ans > cnt)
			ans = cnt;
		return;
	}
	dfs(cnt, index + 1);
	v[index] -= 1;
	dfs(cnt + 1, index + 1);
	v[index] += 2;
	dfs(cnt + 1, index + 1);
	v[index] -= 1;
}
int main()
{
	int temp;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	dfs(0, 0);
	cout << ans;
}