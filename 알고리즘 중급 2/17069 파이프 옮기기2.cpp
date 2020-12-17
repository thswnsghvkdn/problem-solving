#include <iostream>
#include <vector>
using namespace std;

struct Dir {
	long long dir[3];
	int wall;
}; // 진입 방향을 저장할 구조체, wall은 벽 정보!

int dx[] = { -1, -1 ,0 }; // 진입해오는 방향 검사 위 대각선 왼쪽위 왼쪽
int dy[] = { 0 , -1, -1 };
vector<int> v[] = { {0, 1} , {0 , 1 , 2} , {1, 2} }; // 세 방향에서 접근할 수 있는 방향
Dir mat[33][33];
int n;
void checkIn(int r, int c) // 진입 수를 계산
{
	for (int i = 0; i < 3; i++) { // i 는 위 , 대각선 왼쪽 위 , 왼쪽을 의미한다.
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 1 || nr > n || nc < 1 || nc > n || mat[nr][nc].wall == 1) continue; // 범위 검사
		if (i == 1 && (mat[r - 1][c].wall == 1 || mat[r][c - 1].wall == 1)) continue; // 대각선 검사.
		for (int temp : v[i]) // 접근할 수 있는 위치의 진입 수를 현재 진입수에 더한다.
		{
			mat[r][c].dir[i] += mat[nr][nc].dir[temp]; // 해당 인덱스의 검사 방향( i )에 진입가능한 위치에서의 진입 수를 더한다.
		}
	}
}
int main()
{
	cin >> n;
	int wall; // 벽 유무를 받을 변수
	for(int i = 1 ; i <= n ; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> wall;
			if (wall == 1)
				mat[i][j].wall = 1;
		}
	mat[1][2].dir[2] = 1; // 가로진입 1
	
	for(int i = 1 ; i <= n ;i++)
		for (int j = 1; j <= n; j++) {
			if(mat[i][j].wall == 0)
			checkIn(i, j); // 해당 인덱스의 진입차수 계산
		}
		
	long long tot = 0; // 최종 목적지의 진입 수
	for (int i = 0; i < 3; i++)
		tot += mat[n][n].dir[i];
	cout << tot;
}