#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int depth[4] = {1, 3 , 5 , 7 }; // 별의 세로 길이
int star_size[4] = { 1, 5 , 9 ,13 }; // 별의 사이즈


int n, m;  // 문제에서 주어진 행 , 열 
int tot = -1;
void draw_star(char ar[16][16], int r, int c, int size) // 별을 그린다.
{
	int mid = depth[size] / 2;  // 사이즈의 중앙값
	for (int i = 0; i < depth[size]; i++) {
		ar[r + i][c] = '*'; // 세로축 그리기
		ar[r + mid][c - mid + i] = '*'; // 가로축 그리기
	}
}

int check_star( char ar[16][16], int r , int c ) // 맨 위 좌표를 받고 해당 좌표에서 최대로 뻗어나갈 수 있는 별을 반환
{
	int i;
	
	for (i = 1; i < 4; i++)
	{
		int mid = depth[i] / 2;
		int d = depth[i];
		for (int j = 0; j < d; j++ ) // 세로 검사
		{
			if (r + j >= n || c - mid + j < 0 || c - mid + j >= m || ar[r + j][c] != '#' || ar[r + mid][c - mid + j] != '#') {
				draw_star(ar, r , c , i - 1);
				return i - 1;
			}
		}
	}

	draw_star(ar, r, c, 3); // 가장 긴 별을 그린다.
	return 3;
}

void copy_map(char origin[16][16], char backup[16][16])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			backup[i][j] = origin[i][j];
}

int main()
{
	int temp_ans;
	cin >> n >> m; 
	char map[16][16];
	char ori[16][16];
	char backup[16][16];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ori[i][j];

	copy_map(ori, map);
	
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < m; j++)
		{
			if (ori[i][j] == '#') {
				temp_ans = star_size[check_star(map, i, j)];
				copy_map(map, backup);
				for (int k = i; k < n; k++)
					for (int l = 0; l < m; l++)
					{
						if (k == i && l <= j) continue;
						if (map[k][l] == '#') {
							tot = max(tot, temp_ans * star_size[check_star(backup, k, l)]);
							copy_map(map, backup);
						}
					}
				copy_map(ori, map);
			}
		}

	cout << tot;
}