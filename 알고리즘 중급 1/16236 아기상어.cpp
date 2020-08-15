#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { -1,0,1,0};
int dy[] = { 0,-1,0,1};

// 최소 거리와 위치, 시작 상어사이즈
int min_c;
int min_r;
int min_d;
int s_size = 2;

// 물고기위치
int map[21][21];
// 방문여부
int visit[21][21];
int shark_x; 
int shark_y;
int n; // 행, 열

struct Point {
	int time; 
	int x;
	int y;
};

// 답
int tot;
// 먹은 물고기
int feed = 0;

// 먹을 물고기 위치를 위한 bfs
Point bfs(int x, int y)
{
	queue<Point> q;
	q.push({ 0, x,y });
	Point ans = { -1, 0 , 0 };
	visit[x][y] = -1; // 처음시작위치 표시 그냥 별 이유 없이 -1로 해놈
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] <= s_size && temp.time+1 <= min_d && visit[nx][ny] == 0)
			{

				if (map[nx][ny] != 0 && map[nx][ny] < s_size && temp.time+1 < min_d) // 최소시간일경우 갱신
				{
					min_d = temp.time+1;
					min_c = ny;
					min_r = nx;
					ans = { temp.time + 1 ,nx , ny };
					visit[nx][ny] = temp.time + 1; // 사실 1로만 해놔도 된다.
					q.push({ temp.time + 1 ,nx , ny });
				}
				else if (map[nx][ny] != 0 && map[nx][ny] < s_size && temp.time+1 == min_d && nx <= min_r) // 최소시간이 여러 마리 일 때
				{
					// 위치비교
					if (nx == min_r)
					{
						if (ny < min_c) {
							min_c = ny;
							min_r = nx;
							ans = { min_d, nx, ny };
						}
					}	
					else {
						min_c = ny;
						min_r = nx;
						ans = { min_d, nx, ny };
					}
				}
				else {
					visit[nx][ny] = temp.time + 1;
					q.push({ temp.time + 1 , nx , ny});
				}

			}
		}
	}

	return ans;
}
// 초기화 최소거리 뿐만 아니라 위치도 초기화를 해주어야 한다. 위치비교가 잘못 될수도 있기 때문
void init_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = 0;
			
		}
	}
	min_r = 21;
	min_c = 21;
	min_d = 401;
}

int main()
{
	cin >> n;
	queue<Point> q;
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push({ 0, i, j });
				map[i][j] = 0;
				visit[i][j] = 1;
			}
		}

	while (1)
	{
		auto temp = q.front();
		q.pop();
		init_map();
		auto shark = bfs(temp.x, temp.y); // 상어가 다음으로 먹은 물고기 위치
		if (shark.time == -1) break; // 상어가 먹을 물고기가 없으면 bfs()에서 time은 -1을 반환한다.

		tot += shark.time;
		feed++;
		if (feed == s_size)
		{
			feed = 0;
			s_size++;
		}
		map[shark.x][shark.y] = 0;
		q.push({ 0 , shark.x , shark.y });
	}
	cout << tot;

}