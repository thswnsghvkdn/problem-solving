#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int n, s;
int mid;
int main()
{
	int tot = 0;
	cin >> n >> s;
	mid = n / 2;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> first(1 << mid);
	vector<int> second(1 << (n - mid));

	for (int i = 0; i < (1 << mid); i++) {// 2 ^ mid ��ŭ �ݺ� (�κ������� ����)
		for (int j = 0; j < mid; j++) // �� i�� 1�� � �ִ� �� Ȯ��
		{
			if (i & (1 << j)) // 1�� ��ĭ�� �� ������ ������ŭ �о �ش� ������ 1�� ���ԵǾ� �ִ��� Ȯ��
				first[i] += v[j];
		}
		if (first[i] == s && i != 0)
			tot++;
	}

	for (int i = 0; i < (1 << (n - mid)); i++) {
		for (int j = 0; j < (n - mid); j++)
		{
			if (i & (1 << j))
				second[i] += v[mid + j];
		}
		if (second[i] == s && i != 0)
			tot++;
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<int>());

	int f_index = 0, s_index = 0;
	int sum = first[f_index] + second[s_index];
	while (f_index + 1 < first.size() && s_index + 1 < second.size())
	{
		if (sum > s)
			while(s_index + 1 < second.size() && sum > s)
				sum = first[f_index] + second[++s_index];
		
		if(sum < s)
			while (f_index + 1 < first.size() && sum < s)
				sum = first[++f_index] + second[s_index];

		if (sum == s)
		{
			tot++;
			int t1 = first[f_index], t2 = second[s_index];
			while (s_index + 1< second.size() && t2 == second[++s_index])
				tot++;
			while (f_index + 1< first.size() && t1 == first[++f_index])
				tot++;

		}
	}

	cout << tot;
}