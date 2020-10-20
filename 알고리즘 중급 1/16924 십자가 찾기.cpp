#include <iostream>
#include <vector>
using namespace std;
// ��ǥ�� �̵��� 4����
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m; // ������ �� , ��
struct Point{
	int row;
	int col;
	int size;
}; // �� �߽��� ��ġ�� ũ�� ����ü
vector<Point> v; // ����ü�� �߰��س��� ����
char star[110][110]; // ������ ������ ���� �� �迭
char spareStar[110][110]; // ���س��� �迭 

void drawSpare(int x, int y, int size)
{
	int nSize = 1;
	spareStar[x][y] = '*';
	while (nSize <= size)
	{
		for (int i = 0; i < n; i++) // �μ��� ���� ������ ��ŭ ������� ���� �׸���.
		{
			int nx = x + dx[i] * nSize;
			int ny = y + dy[i] * nSize;
			spareStar[nx][ny] = '*';
		}
		nSize++;
	}
}

int checkCenter(int x, int y) // �߽����� �޾� 4������ ���� �����ִ��� �˻�
{
	int size = 1;
	int nx, ny;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + (dx[i] * size);
			ny = y + (dy[i] * size);
			if (nx < 1 || nx > n || ny < 1 || ny > m) // ����� ��ǥ�� �������� �ִ��� �˻�
				return size - 1; // ����� ���߾� ��ȯ
			if (star[nx][ny] == '.') // ����� ��ǥ�� ���� ������ ��ȯ
				return size - 1; // ����� ���߾� ��ȯ
		}
		// ���������� ������ٸ� 
		size++;
	}
}


int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n ; i++)
		for (int j = 1; j <= m; j++) 
			cin >> star[i][j];
	// spareStar�ʱ�ȭ
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			spareStar[i][j] = '.';


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (star[i][j] == '*') // ���� �������� ��������� �˻��Ѵ�.
			{
				int size = checkCenter(i, j);
				if (size) // size�� 1�̻��� ���� ���°��
				{
					v.push_back({ i , j , size }); // ���Ϳ� ������ ����
					drawSpare(i, j, size); // spareStar�� �ش� ���� �׸���.
				}
			}
		}

	for (int i = 1; i <= n; i++) // ������ ������ �˻��Ѵ�.
		for (int j = 1; j <= m; j++)
		{
			if (spareStar[i][j] != star[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].row<< ' ' << v[i].col << ' '  << v[i].size << '\n';
	
	
	/*
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++)
			if (i * j % 3 == 0) cout << '*';
			else cout << '.';
		cout << '\n';
	}
	*/
}