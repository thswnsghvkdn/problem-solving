#include <iostream>
#include <vector>
using namespace std;

int n; // 행렬의 크기
int mat[17][17]; // 행렬
int way; // 갈 수 있는 방법 수
int dx[] = { 0, 1 , 1 }; // 회전 방향 가로 대각선 세로
int dy[] = { 1, 1, 0 }; // 회전 방향 가로 대각선 세로
struct Point
{
	int r ,c , dir;
}; // 회정정보 구조체 행, 열 , 방향
vector<int> direction[] = { {0 , 1} , {0 , 1 , 2} , {1 , 2} }; // 갈 수 있는 방향 정보

bool check_dir(Point p, int dir) // 앞으로 갈 방향이 가능한지 검사
{
	if (dir == 1) // 대각선 방향 검사
	{
		for (int i = 0; i < 3; i++) {
			int nx = p.r + dx[i];
			int ny = p.c + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n || mat[nx][ny] == 1)
				return false;
		}
		return true;
	}


	// 진행할 방향
	int nx = p.r + dx[dir]; 
	int ny = p.c + dy[dir];

	if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mat[nx][ny] != 1)
		return true;
	return false;
}

void dfs(Point p)
{
	// 종료조건 : 목적지에 도착한 경우 방법의 수 1증가
	if (p.r == n && p.c == n)
	{
		way++;
		return;
	}
	if (p.dir == 0) // 이전 방향이 가로일경우
	{
		if (check_dir(p, 0)) // 가로방향 검사
			dfs({ p.r + dx[0] ,p.c + dy[0] , 0 }); // 진행한 방향으로 재귀호출
		if (check_dir(p, 1)) // 대각선방향 검사
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // 진행한 방향으로 재귀호출
	}
	else if (p.dir == 1) // 이전 방향이 대각선일 때
	{
		if (check_dir(p, 0)) // 가로방향 검사
			dfs({ p.r + dx[0] ,p.c + dy[0] , 0 }); // 진행한 방향으로 재귀호출
		if (check_dir(p, 1)) // 대각선방향 검사
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // 진행한 방향으로 재귀호출
		if (check_dir(p, 2)) // 세로방향 검사
			dfs({ p.r + dx[2] ,p.c + dy[2] , 2 }); // 진행한 방향으로 재귀호출
	}
	else
	{
		if (check_dir(p, 1)) // 대각선방향 검사
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // 진행한 방향으로 재귀호출
		if (check_dir(p, 2)) // 세로방향 검사
			dfs({ p.r + dx[2] ,p.c + dy[2] , 2 }); // 진행한 방향으로 재귀호출
	}
}
vector<int> direction[] = { {0 , 1} , {0 , 1 , 2} , {1 , 2} }; // 갈 수 있는 방향 정보
void dfs2(Point p)
{

	if (p.r == n && p.c == n) // 종료조건
	{
		way++;
		return;
	}

		for (int d : direction[p.dir]) // 해당 인덱스의 갈 수 있는 방향정보만틈 반복
		{
			int nx = p.r + dx[d];
			int ny = p.c + dy[d];
			if (nx > n || ny > n || mat[nx][ny] == 1) continue;
			if (d == 1) // 대각선 방향의 경우 빈칸 추가 검사
			{
				if (mat[nx - 1][ny] == 0 && mat[nx][ny - 1] == 0)
					dfs2({ nx , ny , d });
			}
			else
				dfs2({ nx, ny ,d });
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mat[i][j];
	dfs2({ 1 , 2 ,0 });
	cout << way;
}

