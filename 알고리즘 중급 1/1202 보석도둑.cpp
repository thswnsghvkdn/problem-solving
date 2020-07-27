#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

struct jewel {
	long long m;
	long long v;
};

int main()
{
	int n, k;
	cin >> n >> k;
	vector<jewel> jw(n);
	for (int i = 0; i < n; i++)
	{
		cin >> jw[i].m >> jw[i].v;
	}
	sort(jw.begin(), jw.end(), [](jewel a, jewel b) {
		return a.v > b.v;
		});
	multiset<int> ml;
	long long temp;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		ml.insert(temp);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		// �ش� �ε����� ���Կ� ���� ����� ���Ը� ã�´�. (���� Ž��)
		auto it = ml.lower_bound(jw[i].m);

		// it => ml.end()�� ������ ���Ը� ���� �� �ִ� ������ ã�� ���Ѱ��
		if (it != ml.end())
		{
			// ������ �ε����� ã�� ��� �ش� ������ ���� �� �����Ƿ� ���տ� ���Ѵ�.
			ans += jw[i].v;
			ml.erase(it);
		}
	}

	printf("%lld", ans);

}