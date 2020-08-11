#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { -1,0,1,0};
int dy[] = { 0,-1,0,1};

int feed = 0;
int s_size = 2;
int time = 0;

struct Point{
	int time; 
	int x; 
	int y;
};

queue<Point> q;

void Clear()
{
	queue<Point> empty;
	swap(q, empty);
}

int n;
int map[20][20];
int visit[20][20];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push({ 0,i,j });
				map[i][j] = 0;
				visit[i][j] = true;
			}
		}
	}
	
	while (!q.empty())
	{
		bool flag = false;
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] <= s_size && visit[nx][ny] == false)
			{
				if (map[nx][ny] != 0 && map[nx][ny] < s_size)
				{
					feed++;
					if (feed == s_size) {
						s_size++;
						feed = 0;
						flag = true;
					}
					time += temp.time+1;
					Clear(); // 큐 초기화
					fill(visit[0], visit[n] + n, false); // 방문배열 초기화
					map[nx][ny] = 0;
					visit[nx][ny] = true;
					q.push({0 , nx, ny });
				}
				else {
					q.push({ temp.time + 1 , nx , ny });
					visit[nx][ny] = temp.time + 1;
				}
			}
			if (flag == true) break;
		}
	}
	cout << time;

}
