#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // 행, 열 , 회전 수
int row_sum = -1; // 행의 최솟값
int mat[51][51]; // 행렬
bool visit[6];

struct Point{
	int r , c, s;
};
vector<Point> v; // 회전정보를 담을 벡터

void add_row(int mat[51][51]) // 배열에서 행을 더하며 행의 최솟값을 갱신하는 함수
{
	int temp; // 각 행의 합을 더할 변수 
	for (int i = 1; i <= n; i++) {
		temp = 0;
		for (int j = 1; j <= m; j++)
			temp += mat[i][j];
		if (row_sum == -1 || row_sum > temp)
			row_sum = temp;
	}
}

void copy_mat(int origin[51][51], int backup[51][51]) // 복사
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			backup[i][j] = origin[i][j];
}
void rotate_map(int map[51][51], int r, int c, int s, int cnt) // 행렬의 일부를 회전시킬 함수 , cnt는 수행한 회전연산수를 의미한다.
{
	int backup[51][51];
	copy_mat(map, backup); // 백업파일에 저장

	if (s == 0) {
		if(cnt == k)
			add_row(map);
			return;
	}
	int move = s * 2; // 움직일 거리는 각 줄마다 2 * s 만큼 움직인다.
	int temp_r = r - s, temp_c = c - s; // 처음 출발할 장소로 움직일 위치를 초기화
	int temp_factor; // 임시원소

	// 오른쪽 방향으로 가기
	for (int i = 0; i < move; i++, temp_c++)
		map[temp_r][temp_c+1] = backup[temp_r][temp_c]; // 한칸씩 옆 칸에 저장한다.
	
	// 아래로 가기
	for (int i = 0; i < move; i++, temp_r++)
		map[temp_r+1][temp_c] = backup[temp_r][temp_c];
	// 왼쪽
	for (int i = 0; i < move; i++, temp_c--)
		map[temp_r][temp_c-1] = backup[temp_r][temp_c];
	// 위로
	for (int i = 0; i < move; i++, temp_r--)
		map[temp_r-1][temp_c] = backup[temp_r][temp_c];

	rotate_map(map, r, c, s / 2, cnt);
}
void dfs(int map[51][51], int cnt)
{
	int backup[51][51];
	copy_mat(map, backup);
	if (cnt == k) return;
	for (int i = 0; i < k; i++)
	{
		if (visit[i] == true) continue;
		visit[i] = true;
		rotate_map(map, v[i].r, v[i].c, v[i].s, cnt+1);
		dfs(map, cnt + 1);
		visit[i] = false;
		copy_mat(backup, map);
	}
}
int main()
{
	int r, c, s; // 회전정보 변수
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mat[i][j];
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c >> s;
		v.push_back({ r, c , s });
	}

	dfs(mat, 0);

	cout << row_sum << "\n";

}



