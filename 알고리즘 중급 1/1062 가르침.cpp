#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(vector<int> v, int mask)
{
	int cnt = 0;
	// int 벡터의 경우 비트 마스킹 방법으로 한번에 비교가 가능하다 
	for (int word : v)
	{
		// 배우지 않은 단어와 & 연산을 하여 0이 나온다면 겹치는 부분이 없다는 의미
		if ((word & ((1 << 26) - 1 - mask)) == 0) // word & (1 << 26) - 1 - mask 는 원하는 값이 나오지 않는다.
			// ~mask와 비교하는 것보다 안전한 방법
		{
			cnt++;
		}
	}
	return cnt;
}
int go(vector<int> v, int index, int k , int mask)
{
	if (k < 0) return 0;
	if (index == 26)
		// k개수 만큼 알파벳을 배웠을 때에는 해당 알파벳으로 단어를 검사
	{
		return count(v, mask);
	}

	// 알파벳을 배우는 경우의 수
	int t1 = go(v, index + 1, k - 1, mask | (1 << index));
	int ans = 0;
	if (t1 > ans)
		ans = t1;
	

	// 알파벳을 배우지 않는 경우의 수
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
	{
		t1 = go(v, index + 1, k, mask);
		if (ans < t1)
			ans = t1;
	}
	return ans;
}

int main()
{
	int n, k;
	string s;
	cin >> n >> k;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		// int 벡터의 경우 string을 입력받아 한개의 단어씩 마스킹해주면서 입력
		for (char ch : s)
		{
			v[i] |= (1 <<  (ch - 'a'));
		}
	}
	cout << go(v, 0, k, 0);
}