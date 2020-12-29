#include <iostream>
#include <queue>
using namespace std;

int mp[5][5][5];
bool visit[5][5][5];
int ans = -1;
struct Nav
{
	int z, x, y;
	int cnt;
}; // 3���� ��ǥ�� ������ �Ÿ�

Nav temp[3] = { {1, 0 ,0 ,0}, {0, 1 ,0 ,0} ,{0, 0 ,1 ,0} };

void init_visit() // �湮�迭 �ʱ�ȭ
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				visit[i][j][k] = false;
}

int mindir() // 2���� �̷θ� ���������� �ּҰŸ�
{
	queue<Nav> q;
	q.push({ 0, 0, 0, 0 });
	while (!q.empty())
	{
		Nav t = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nz = t.z + temp[i].z;
			int nx = t.x + temp[i].x;
			int ny = t.y + temp[i].y;
			int cnt = temp[i].cnt + 1;
			if (nx >= 5 || nz >= 5 || ny >= 5 || mp[nz][nx][ny] == 0 || visit[nz][nx][ny] == true) continue;
			if (nx == 4 && ny == 4 && nz == 4) return cnt;
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

void rotate1(int layer) // �μ� layer�� �ð�������� ȸ��
{
	int temp[5][5];
	mapcpy(mp[layer], temp);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			mp[layer][i][j] = temp[4 - j][i];
}

void rotate2(int layer) // �μ� layer�� �ð�ݴ�������� ȸ��
{
	int temp[5][5];
	mapcpy(mp[layer], temp);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			mp[layer][i][j] = temp[j][4 - i];
}

void dfs(int layer)
{
	if (layer == 5)
	{
		int t = mindir();
		init_visit();
		if (ans == -1 || ans > t)
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
				cin >> mp[i][j][k];
	dfs(0);
	cout << ans;
}
