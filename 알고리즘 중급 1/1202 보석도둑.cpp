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
		// 해당 인덱스의 무게와 가장 비슷한 무게를 찾는다. (이진 탐색)
		auto it = ml.lower_bound(jw[i].m);

		// it => ml.end()는 보석의 무게를 담을 수 있는 가방을 찾지 못한경우
		if (it != ml.end())
		{
			// 적당한 인덱스를 찾은 경우 해당 보석은 담을 수 있으므로 총합에 더한다.
			ans += jw[i].v;
			ml.erase(it);
		}
	}

	printf("%lld", ans);

}