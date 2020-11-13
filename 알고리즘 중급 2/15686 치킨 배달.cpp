#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
vector<Point> chicken;
vector<Point> chicken2;
vector<Point> home;
int num;
int m;
int tot = -1;
int dist(Point x, vector<Point> v)
{
	int temp;
	int n_min = -1;
	for (int i = 0; i < v.size(); i++)
	{
		temp = abs(x.x - v[i].x) + abs(x.y - v[i].y);
		if (n_min == -1 || n_min > temp) n_min = temp;
	}
	return n_min;
}

void dfs(int cnt, int index)
{
	if (cnt == m)
	{
		int sum = 0;
		for (int i = 0; i < home.size(); i++)
			sum += dist(home[i], chicken2);
		if (tot == -1 || tot > sum) tot = sum;
		return;
	}
	if (index == chicken.size()) return;


	chicken2.push_back(chicken[index]);
	dfs(cnt + 1, index + 1);
	chicken2.pop_back();
	dfs(cnt, index + 1);
}

int main()
{
	int temp;
	cin >> num >> m;
	for(int i = 0 ; i < num ; i++)
		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			if (temp == 1) home.push_back({ i , j });
			if (temp == 2) chicken.push_back({ i , j });
		}

	dfs(0, 0);
	cout << tot;
}
