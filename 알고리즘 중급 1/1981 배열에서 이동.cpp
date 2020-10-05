#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int max_value;
int min_value;
int dx[] = { 0,0,1,-1};
int dy[] = { 1,-1,0,0};
int ar[105][105];
bool visit[105][105];
int n;
void init()
{
	min_value = 210;
	max_value = -1;
	for (int i = 1; i < 105; i++)
		for (int j = 1; j < 105; j++) {
			if (ar[i][j] > max_value)
				max_value = ar[i][j];
			if (ar[i][j] < min_value)
				min_value = ar[i][j];
		}

}
struct Point{
	int i, j;
};
bool bfs(int mid)
{
	init();
	for (int i = min_value; i <= max_value; i++) {
		for (int i = 1; i < 105; i++)
			for (int j = 1; j < 105; j++)
				visit[i][j] = true;


		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (i <= ar[j][k] && ar[j][k] <= i + mid) visit[j][k] = false;


		queue<Point> q;
		q.push({ 1, 1 });

		while (!q.empty())
		{
			auto temp = q.front();
			q.pop();
			visit[temp.i][temp.j] = true;

			for (int i = 0; i < 4; i++)
			{
				int nx = temp.i + dx[i];
				int ny = temp.j + dy[i];
				int max, min;
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visit[nx][ny])
				{
					if (nx == n && ny == n)
						return true;
					q.push({ nx, ny});
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> ar[i][j];
	
	int start = 0;
	int end = 200;
	int ans = 200;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (bfs(mid))
		{
			if (ans > mid)
				ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	cout << ans;
}