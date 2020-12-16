#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // ��, �� , ȸ�� ��
int row_sum = -1; // ���� �ּڰ�
int mat[51][51]; // ���
bool visit[6];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


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
	/*������ �迭�� �������� �Լ�.
	  1. while���� ���ؼ� �� ���κ��� �ƴ�, �� ���� ó���ϴ� ������ ����.
	  2. ������ �� �簢���� ���� ������ ������ ��� ������ �ٲ��ִ� ������ ����. */
	  /*=======================================================================*/

	int Sx = T.r - T.s;
	int Sy = T.c - T.s;
	int Ex = T.r + T.s;
	int Ey = T.c + T.s;
	int Turn_Count = (Ex - Sx) / 2;    // �� ���� �簢���� ������� �ϴ��� 

	for (int i = 0; i < Turn_Count; i++)    // ������ �� �簢���� ������ŭ �ݺ�
	{
		int x = Sx;                    // x = ���� X��ǥ
		int y = Sy;                    // y = ���� y��ǥ
		int Temp = map[x][y];        // ���� ù �������� Temp�� �ӽ������� ����
		int d = 2;                    // 0 = ��, 1 = ��, 2 = ��, 3 = ��. ù ������ ���� !
		/* ù ������ �������� ���� ����
		   - �ð�������� �迭�� ȸ���Ǵ� ���̱� ������, �̴� ��� ����
			 �ڱ� �ڽ��� �������� �� �ð� ���⿡ �ִ� ���� �ڱ� �ڽ��� �ڸ��� ��ġ�ϰ� �ȴ�.
			 ��, �������� �������� ���� ���κ�, �ϴ� ���κ�, ���� ���κ�, ��� ���κ� ������
			 �����̸鼭 ���� ������ �־���. */

		while (1)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			// (nx, ny) = ������ ���ߵ���, ���� �ڱ��ڽ��� �������� �� ĭ ����(�ݽð����) �� �ִ� ��ǥ

			if (nx == Sx && ny == Sy)    // �ٽ� ó�� ��ġ�� ���ƿ��� �ȴٸ�
			{
				map[x][y] = Temp;        // ������ �����ص� �ӽ� ���� ������ ���� ���� �� ����.
				break;
			}

			if (Sx <= nx && nx <= Ex - i && Sy <= ny && ny <= Ey - i)    // ���� �簢���� ���� ���� �ִ� ��ǥ���
			{
				map[x][y] = map[nx][ny];        // �ڱ��ڽ��� �ڸ��� �� �ð���⿡ �ִ� ��ǥ�� �־��ش�.
				x = nx;                                // x�� �缳��
				y = ny;                                // y�� �缳��
			}
			else
			{
				/* �׷���, ������ ���󰡴� ���� ������ �簢���� ������ ����� ��찡 ������.
				   �׷� ���� ������ �ٲ��ش�.
				   ���� -> ���� -> ���� -> ���� ������ ! */
				d = change_Direction(d);
			}
		}
		Sx++;
		Sy++;
		/* �� ���� �簢������ ���� ���� Sx, Sy�� ����.
		   ����, ������ �� �簢���� ������ 2���̰�, ���� �ٱ��� �簢���� �������� (1, 1)�̿��ٸ�
		   �� �������� ������ �� �簢���� �������� (2, 2)�� �� ���̴�.
		   ��, Sx++ ,Sy++ */
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



