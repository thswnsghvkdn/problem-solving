#include <iostream>
#include <vector>
using namespace std;

int n; // ����� ũ��
int mat[17][17]; // ���
int way; // �� �� �ִ� ��� ��
int dx[] = { 0, 1 , 1 }; // ȸ�� ���� ���� �밢�� ����
int dy[] = { 1, 1, 0 }; // ȸ�� ���� ���� �밢�� ����
struct Point
{
	int r ,c , dir;
}; // ȸ������ ����ü ��, �� , ����
vector<int> direction[] = { {0 , 1} , {0 , 1 , 2} , {1 , 2} }; // �� �� �ִ� ���� ����

bool check_dir(Point p, int dir) // ������ �� ������ �������� �˻�
{
	if (dir == 1) // �밢�� ���� �˻�
	{
		for (int i = 0; i < 3; i++) {
			int nx = p.r + dx[i];
			int ny = p.c + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n || mat[nx][ny] == 1)
				return false;
		}
		return true;
	}


	// ������ ����
	int nx = p.r + dx[dir]; 
	int ny = p.c + dy[dir];

	if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mat[nx][ny] != 1)
		return true;
	return false;
}

void dfs(Point p)
{
	// �������� : �������� ������ ��� ����� �� 1����
	if (p.r == n && p.c == n)
	{
		way++;
		return;
	}
	if (p.dir == 0) // ���� ������ �����ϰ��
	{
		if (check_dir(p, 0)) // ���ι��� �˻�
			dfs({ p.r + dx[0] ,p.c + dy[0] , 0 }); // ������ �������� ���ȣ��
		if (check_dir(p, 1)) // �밢������ �˻�
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // ������ �������� ���ȣ��
	}
	else if (p.dir == 1) // ���� ������ �밢���� ��
	{
		if (check_dir(p, 0)) // ���ι��� �˻�
			dfs({ p.r + dx[0] ,p.c + dy[0] , 0 }); // ������ �������� ���ȣ��
		if (check_dir(p, 1)) // �밢������ �˻�
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // ������ �������� ���ȣ��
		if (check_dir(p, 2)) // ���ι��� �˻�
			dfs({ p.r + dx[2] ,p.c + dy[2] , 2 }); // ������ �������� ���ȣ��
	}
	else
	{
		if (check_dir(p, 1)) // �밢������ �˻�
			dfs({ p.r + dx[1] ,p.c + dy[1] , 1 }); // ������ �������� ���ȣ��
		if (check_dir(p, 2)) // ���ι��� �˻�
			dfs({ p.r + dx[2] ,p.c + dy[2] , 2 }); // ������ �������� ���ȣ��
	}
}
vector<int> direction[] = { {0 , 1} , {0 , 1 , 2} , {1 , 2} }; // �� �� �ִ� ���� ����
void dfs2(Point p)
{

	if (p.r == n && p.c == n) // ��������
	{
		way++;
		return;
	}

		for (int d : direction[p.dir]) // �ش� �ε����� �� �� �ִ� ����������ƴ �ݺ�
		{
			int nx = p.r + dx[d];
			int ny = p.c + dy[d];
			if (nx > n || ny > n || mat[nx][ny] == 1) continue;
			if (d == 1) // �밢�� ������ ��� ��ĭ �߰� �˻�
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

