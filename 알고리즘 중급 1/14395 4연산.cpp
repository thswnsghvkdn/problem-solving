#include <iostream>
#include <queue>

#include <map>
using namespace std;

string s;


map<long long, bool> visit;
pair<long long, char> bfs(int i, long long num)
{
	if (i == 0)
	{
		num = num * num;
		return make_pair(num, '*');
	}
	if (i == 1)
	{
		num = num + num;
		return make_pair(num, '+');
	}
	if (i == 2)
	{
		num = num - num;
		return make_pair(num, '-');
	}	
	if (i == 3)
	{
		num = num / num;
		return make_pair(num, '/');
	}
}

int main()
{
	long long start , end;
	cin >> start >> end;
	if (start == end)
	{
		cout << 0;
		return 0;
	}

	queue<pair<long long , string> > q;
	q.push(make_pair(start , ""));
	
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		if (temp.first == end)
		{
			cout << temp.second;
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (i == 3 && temp.first == 0) continue;
			auto n_str = bfs(i, temp.first);
			if (n_str.first <= end && visit[n_str.first] == false) {
				q.push(make_pair(n_str.first, temp.second + n_str.second));
				visit[n_str.first] = true;
			}

		}
	}

	cout << -1;
	return 0;

}