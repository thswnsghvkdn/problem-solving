#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(vector<int> v, int mask)
{
	int cnt = 0;
	// int ������ ��� ��Ʈ ����ŷ ������� �ѹ��� �񱳰� �����ϴ� 
	for (int word : v)
	{
		// ����� ���� �ܾ�� & ������ �Ͽ� 0�� ���´ٸ� ��ġ�� �κ��� ���ٴ� �ǹ�
		if ((word & ((1 << 26) - 1 - mask)) == 0) // word & (1 << 26) - 1 - mask �� ���ϴ� ���� ������ �ʴ´�.
			// ~mask�� ���ϴ� �ͺ��� ������ ���
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
		// k���� ��ŭ ���ĺ��� ����� ������ �ش� ���ĺ����� �ܾ �˻�
	{
		return count(v, mask);
	}

	// ���ĺ��� ���� ����� ��
	int t1 = go(v, index + 1, k - 1, mask | (1 << index));
	int ans = 0;
	if (t1 > ans)
		ans = t1;
	

	// ���ĺ��� ����� �ʴ� ����� ��
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
		// int ������ ��� string�� �Է¹޾� �Ѱ��� �ܾ ����ŷ���ָ鼭 �Է�
		for (char ch : s)
		{
			v[i] |= (1 <<  (ch - 'a'));
		}
	}
	cout << go(v, 0, k, 0);
}