#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), [](pair<int, int > a, pair<int, int > b) {
		return a.second > b.second;
		});

	priority_queue<int> q;
	int limit = 0; // ���� ������ ����
	int ans = 0; // ����

	// day�� 10000�� ���� �Ϸ羿 �����մϴ�. 
	for (int day = 10000; day > 0; day--)
	{
		// day�� �����ϴٰ� ���� ���ۿ� ��¥�� ���� ���
		while (n > limit && v[limit].second == day) // ���� ���ۿ� day��  pay �������� �켱���� ť�� �����ϸ鼭 pay�� �����մϴ�.
		{
			q.push(v[limit].first);
			limit++;
		}
		// �ش� day�� ���� �� �ִ� �ְ� �ݾ��� �ջ��մϴ�.
		if (!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}
	cout << ans;
}