#include <iostream>
#include <vector>
using namespace std;

struct Dir {
	long long dir[3];
	int wall;
}; // ���� ������ ������ ����ü, wall�� �� ����!

int dx[] = { -1, -1 ,0 }; // �����ؿ��� ���� �˻� �� �밢�� ������ ����
int dy[] = { 0 , -1, -1 };
vector<int> v[] = { {0, 1} , {0 , 1 , 2} , {1, 2} }; // �� ���⿡�� ������ �� �ִ� ����
Dir mat[33][33];
int n;
void checkIn(int r, int c) // ���� ���� ���
{
	for (int i = 0; i < 3; i++) { // i �� �� , �밢�� ���� �� , ������ �ǹ��Ѵ�.
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 1 || nr > n || nc < 1 || nc > n || mat[nr][nc].wall == 1) continue; // ���� �˻�
		if (i == 1 && (mat[r - 1][c].wall == 1 || mat[r][c - 1].wall == 1)) continue; // �밢�� �˻�.
		for (int temp : v[i]) // ������ �� �ִ� ��ġ�� ���� ���� ���� ���Լ��� ���Ѵ�.
		{
			mat[r][c].dir[i] += mat[nr][nc].dir[temp]; // �ش� �ε����� �˻� ����( i )�� ���԰����� ��ġ������ ���� ���� ���Ѵ�.
		}
	}
}
int main()
{
	cin >> n;
	int wall; // �� ������ ���� ����
	for(int i = 1 ; i <= n ; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> wall;
			if (wall == 1)
				mat[i][j].wall = 1;
		}
	mat[1][2].dir[2] = 1; // �������� 1
	
	for(int i = 1 ; i <= n ;i++)
		for (int j = 1; j <= n; j++) {
			if(mat[i][j].wall == 0)
			checkIn(i, j); // �ش� �ε����� �������� ���
		}
		
	long long tot = 0; // ���� �������� ���� ��
	for (int i = 0; i < 3; i++)
		tot += mat[n][n].dir[i];
	cout << tot;
}