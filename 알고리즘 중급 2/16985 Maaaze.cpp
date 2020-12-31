#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 5
using namespace std;
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

int t_mp[5][5][5]; // 임시 맵
int mp[5][5][5]; // 맵
bool visit[5][5][5]; // 
int ans = -1;

struct Nav
{
	int z, x, y;
	int cnt;
}; // 3차원 좌표와 움직인 거리

Nav temp[3] = { {1, 0 ,0 ,0}, {0, 1 ,0 ,0} ,{0, 0 ,1 ,0} };


void init_visit() // 방문배열 초기화
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				visit[i][j][k] = false;
}

int BFS() 
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	if (mp[0][0][0] == 0 || mp[4][4][4] == 0) return -1;
	visit[0][0][0] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int h = Q.front().second.first;
		int Cnt = Q.front().second.second;
		Q.pop();

		if (x == MAX - 1 && y == MAX - 1 && h == MAX - 1)
		{
			return Cnt;
		}

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = h + dh[i];

			if (nx >= 0 && ny >= 0 && nh >= 0 && nx < MAX && ny < MAX && nh < MAX)
			{
				if (mp[nh][nx][ny] == 1 && visit[nh][nx][ny] == false)
				{
					visit[nh][nx][ny] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(nh, Cnt + 1)));
				}
			}
		}
	}
	return -1;
}




int mindir() // 2차원 미로를 빠져나가는 최소거리
{
	queue<Nav> q;
	if (mp[0][0][0] == 0 || mp[4][4][4] == 0) return -1;

	q.push({ 0, 0, 0, 0 });
	while (!q.empty())
	{
		Nav t = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) // 세 방향만 추가 앞 옆 아래
		{
			int nz = t.z + temp[i].z;
			int nx = t.x + temp[i].x;
			int ny = t.y + temp[i].y;
			int cnt = t.cnt + 1;

			if (nx >= 5 || nz >= 5 || ny >= 5 || mp[nz][nx][ny] == 0 || visit[nz][nx][ny] == true) continue;
			if (nx == 4 && ny == 4 && nz == 4) 
				return cnt;
			visit[nz][nx][ny] = true;
			q.push({ nz, nx, ny, cnt });
		}
	}
	return -1;
}

void mapcpy(int ori[5][5], int back[5][5])
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			back[i][j] = ori[i][j];
}


void rotate1(int layer) // 인수 layer를 시계방향으로 회전
{
	int temp[5][5];
	mapcpy(mp[layer], temp);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			mp[layer][i][j] = temp[4 - j][i];
}

void dfs(int layer)
{
	if (layer == 5)
	{
		int t = BFS();
		init_visit();
		if (t == -1)
			return;
		if (ans == -1 ||ans > t)
			ans = t;
		return;
	}
	for (int j = 0; j < 4; j++)
		{
			rotate1(layer);
			dfs(layer + 1);
		}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> t_mp[i][j][k];
	
	vector<int> v = { 0 ,1 , 2 ,3 ,4 };

	do {
		for (int i = 0; i < 5; i++) 
			mapcpy(t_mp[v[i]], mp[i]);
		dfs(0);
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans;
}
