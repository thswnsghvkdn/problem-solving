#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // ��, �� , ȸ�� ��
int row_sum = -1; // ���� �ּڰ�
int mat[51][51]; // ���
bool visit[6];

struct Point{
	int r , c, s;
};
vector<Point> v; // ȸ�������� ���� ����

void add_row(int mat[51][51]) // �迭���� ���� ���ϸ� ���� �ּڰ��� �����ϴ� �Լ�
{
	int temp; // �� ���� ���� ���� ���� 
	for (int i = 1; i <= n; i++) {
		temp = 0;
		for (int j = 1; j <= m; j++)
			temp += mat[i][j];
		if (row_sum == -1 || row_sum > temp)
			row_sum = temp;
	}
}

void copy_mat(int origin[51][51], int backup[51][51]) // ����
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			backup[i][j] = origin[i][j];
}
void rotate_map(int map[51][51], int r, int c, int s, int cnt) // ����� �Ϻθ� ȸ����ų �Լ� , cnt�� ������ ȸ��������� �ǹ��Ѵ�.
{
	int backup[51][51];
	copy_mat(map, backup); // ������Ͽ� ����

	if (s == 0) {
		if(cnt == k)
			add_row(map);
			return;
	}
	int move = s * 2; // ������ �Ÿ��� �� �ٸ��� 2 * s ��ŭ �����δ�.
	int temp_r = r - s, temp_c = c - s; // ó�� ����� ��ҷ� ������ ��ġ�� �ʱ�ȭ
	int temp_factor; // �ӽÿ���

	// ������ �������� ����
	for (int i = 0; i < move; i++, temp_c++)
		map[temp_r][temp_c+1] = backup[temp_r][temp_c]; // ��ĭ�� �� ĭ�� �����Ѵ�.
	
	// �Ʒ��� ����
	for (int i = 0; i < move; i++, temp_r++)
		map[temp_r+1][temp_c] = backup[temp_r][temp_c];
	// ����
	for (int i = 0; i < move; i++, temp_c--)
		map[temp_r][temp_c-1] = backup[temp_r][temp_c];
	// ����
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
	int r, c, s; // ȸ������ ����
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



