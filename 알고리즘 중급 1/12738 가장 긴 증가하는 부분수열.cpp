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
		// lower_bound() (크거나 같은 원소중 가장 작은 원소의 위치)를 호출하여 temp가 들어갈 위치를 정한다.
		auto it = lower_bound(v.begin(), v.end(), temp);
		if (it == v.end()) // temp가 가장 큰 원소라면 마지막에 삽입
			v.push_back(temp);
		else
		{
			*it = temp; // temp보다 크거나 같은 원소를 temp로 대체한다.
		}
	}
	cout << v.size();

}