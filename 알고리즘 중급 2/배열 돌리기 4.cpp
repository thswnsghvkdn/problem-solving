#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // 행, 열 , 회전 수
int row_sum = -1; // 행의 최솟값
int mat[51][51]; // 행렬
bool visit[6];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


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

int change_Direction(int cur)
{
	if (cur == 0) return 3;
	else if (cur == 1) return 2;
	else if (cur == 2) return 0;
	else if (cur == 3) return 1;
}
void Simulation(Point T, int map[51][51])
{
	/*=======================================================================*/
	/*실제로 배열을 돌려보는 함수.
	  1. while문을 통해서 각 라인별이 아닌, 한 번에 처리하는 식으로 구현.
	  2. 돌려야 할 사각형의 범위 밖으로 나가는 경우 방향을 바꿔주는 식으로 구현. */
	  /*=======================================================================*/

	int Sx = T.r - T.s;
	int Sy = T.c - T.s;
	int Ex = T.r + T.s;
	int Ey = T.c + T.s;
	int Turn_Count = (Ex - Sx) / 2;    // 몇 개의 사각형을 돌려줘야 하는지 

	for (int i = 0; i < Turn_Count; i++)    // 돌려야 할 사각형의 갯수만큼 반복
	{
		int x = Sx;                    // x = 시작 X좌표
		int y = Sy;                    // y = 시작 y좌표
		int Temp = map[x][y];        // 가장 첫 시작점을 Temp에 임시적으로 저장
		int d = 2;                    // 0 = 동, 1 = 서, 2 = 남, 3 = 북. 첫 방향은 남쪽 !
		/* 첫 방향을 남쪽으로 잡은 이유
		   - 시계방향으로 배열이 회전되는 것이기 때문에, 이는 어떻게 보면
			 자기 자신을 기준으로 반 시계 방향에 있는 값이 자기 자신의 자리에 위치하게 된다.
			 즉, 시작점을 기준으로 왼쪽 세로변, 하단 가로변, 우측 세로변, 상단 가로변 순서로
			 움직이면서 값을 설정해 주었다. */

		while (1)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			// (nx, ny) = 위에서 말했듯이, 현재 자기자신을 기준으로 한 칸 왼쪽(반시계방향) 에 있는 좌표

			if (nx == Sx && ny == Sy)    // 다시 처음 위치로 돌아오게 된다면
			{
				map[x][y] = Temp;        // 위에서 저장해둔 임시 저장 값으로 값을 설정 후 종료.
				break;
			}

			if (Sx <= nx && nx <= Ex - i && Sy <= ny && ny <= Ey - i)    // 현재 사각형의 범위 내에 있는 좌표라면
			{
				map[x][y] = map[nx][ny];        // 자기자신의 자리에 반 시계방향에 있는 좌표를 넣어준다.
				x = nx;                                // x값 재설정
				y = ny;                                // y값 재설정
			}
			else
			{
				/* 그렇게, 방향을 따라가다 보면 정해진 사각형의 범위를 벗어나는 경우가 존재함.
				   그럴 때는 방향을 바꿔준다.
				   남쪽 -> 동쪽 -> 북쪽 -> 서쪽 순으로 ! */
				d = change_Direction(d);
			}
		}
		Sx++;
		Sy++;
		/* 그 다음 사각형으로 가기 위한 Sx, Sy값 설정.
		   만약, 돌려야 할 사각형의 갯수가 2개이고, 가장 바깥쪽 사각형의 시작점이 (1, 1)이엿다면
		   그 다음으로 돌려야 할 사각형의 시작점은 (2, 2)가 될 것이다.
		   즉, Sx++ ,Sy++ */
	}
}


void dfs(int map[51][51], int cnt)
{
	int backup[51][51];
	copy_mat(map, backup);
	if (cnt == k) {
		add_row(map);
		return;
	}
	for (int i = 0; i < k; i++)
	{
		if (visit[i] == true) continue;
		visit[i] = true;
		//rotate_map(map, v[i].r, v[i].c, v[i].s, cnt+1);
		Simulation(v[i], map);
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



