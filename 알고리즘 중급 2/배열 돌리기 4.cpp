#include <iostream>
#include <vector>
using namespace std;
int v[52][52];
int origin[52][52];
int v_copy[52][52];
int dx[] = { -1, 0 ,1 ,0 }; // 위 오 아 왼
int dy[] = { 0 , 1 ,0 , -1 };
int n, m, k;
bool visit[6];
struct Point {
	int r, c, s;
};
vector<Point> p;
int ans = -1;

void mCopy(int ori[52][52], int b[52][52]) // a를 b에 저장
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = ori[i][j];
}
void move(int r , int c, int s)
{
	if (s == 0) return;
	int nc = c - s, nr = r - s;
	int range = 2 * s; // 움직일 범위

	mCopy(v, v_copy);

	for (int i = 0, index = 0; i < range; i++)
	{
		nc += 1;
		v_copy[ nr ][ nc ] = v[ nr ][ nc - 1];
	}
	for (int i = 0, index = 0; i < range; i++)
	{
		nr += 1;
		v_copy[nr][nc] = v[nr-1][nc];
	}
	for (int i = 0, index = 0; i < range; i++)
	{
		nc -= 1;
		v_copy[nr][nc] = v[nr][nc + 1];
	}
	for (int i = 0, index = 0; i < range; i++)
	{
		nr -= 1;
		v_copy[nr][nc] = v[nr+1][nc];
	}
	mCopy(v_copy, v);
	move(r, c, s / 2);
}

void dfs(int size)
{
	if ( (size + 1) == k) {
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += v[i][j];
			if (ans == -1 || sum < ans)
				ans = sum;
		}
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (visit[i]) continue;
		visit[i] = true;
		move(p[i].r, p[i].c, p[i].s);
		dfs(size + 1);
		visit[i] = false;
	}

}

int main()
{
	cin >> n >> m >> k;
	int t1, t2, t3;
	for(int i = 1; i <= n ; i++)
		for (int j = 1; j <= m; j++)
			cin >> origin[i][j];
		
	for (int i = 0; i < k; i++) {
		cin >> t1 >> t2 >> t3;
		p.push_back({ t1, t2 ,t3 });
	}

	for (int i = 0; i < k; i++)
	{
		mCopy(origin, v);
		visit[i] = true;
		move(p[i].r, p[i].c, p[i].s);
		dfs(i);
		visit[i] = false;
	}

	cout << ans;
}