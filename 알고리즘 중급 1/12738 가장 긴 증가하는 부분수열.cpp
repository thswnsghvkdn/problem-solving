#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, temp;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		// lower_bound() (ũ�ų� ���� ������ ���� ���� ������ ��ġ)�� ȣ���Ͽ� temp�� �� ��ġ�� ���Ѵ�.
		auto it = lower_bound(v.begin(), v.end(), temp);
		if (it == v.end()) // temp�� ���� ū ���Ҷ�� �������� ����
			v.push_back(temp);
		else
		{
			*it = temp; // temp���� ũ�ų� ���� ���Ҹ� temp�� ��ü�Ѵ�.
		}
	}
	cout << v.size();

}