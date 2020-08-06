#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1, -1 ,-1, 1, 1, 0};
int dy[] = { 1,-1,0,0, -1 , 1,-1, 1, 0};
int map[8][8];
vector<pair<int, int>>v;
queue <pair<int, int>>q;

void move_wall()
{
	for (int i = 0; i < v.size(); i++)
	{
		auto p = v[i];
		v[i] = make_pair(p.first + 1, p.second);
	}
}
bool check_wall(int r, int c)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == make_pair(r, c) || make_pair(v[i].first + 1, v[i].second) == make_pair(r, c))
			return false;
	}
	return true;
}

int main()
{
	char temp;
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			if (s[j] == '#')
				v.push_back(make_pair(i, j));
		}
	}
	q.push(make_pair(7, 0));

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		
		for (int i = 0; i < 9; i++)
		{
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{
				if (check_wall(nx, ny)) {
					if (nx == 0)
					{
						cout << 1;
						return 0;
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
		move_wall();
	}
	cout << 0;
	return 0;

}