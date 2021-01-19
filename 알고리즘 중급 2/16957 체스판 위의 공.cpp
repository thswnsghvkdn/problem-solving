#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int ar[502][502];
int parent[251001];
int tot[251001];
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int delete_middleParent(int x) // �߰� �θ���� �����Ͽ� �θ��ε����� ������ ã�´�
{
	if (parent[x] == x) return x;
	return parent[x] = delete_middleParent(parent[x]); // ������ �θ�� ���� ���� �θ� �ε����� �θ�� �����Ѵ�.
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> ar[i][j];

	// �θ� ã�� ����
	for(int i = 0 ; i < r ; i++)
		for (int j = 0; j < c; j++)
		{
			int px = i, py = j; // ���� ��ġ�� ó�� �θ���ġ�� �ȴ�.
			for (int k = 0; k < 8; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (ar[px][py] > ar[nx][ny]) // �θ���ġ ���� ������ġ�� �۴ٸ�
				{
					px = nx;
					py = ny;
				}
			}
			parent[c * i + j] = c * px + py; // �ڽ� �ε����� ���ҷ� �θ� �ε����� ����
		}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			delete_middleParent(c * i + j);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tot[parent[c * i + j]]++;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << tot[c * i + j] << ' ';
		cout << endl;
	}

}