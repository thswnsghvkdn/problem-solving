#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int ar[502][502];
int parent[251001];
int tot[251001];
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int delete_middleParent(int x) // 중간 부모들을 삭제하여 부모인덱스를 빠르게 찾는다
{
	if (parent[x] == x) return x;
	return parent[x] = delete_middleParent(parent[x]); // 본인을 부모로 갖는 최종 부모 인덱스를 부모로 갱신한다.
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> ar[i][j];

	// 부모를 찾는 과정
	for(int i = 0 ; i < r ; i++)
		for (int j = 0; j < c; j++)
		{
			int px = i, py = j; // 현재 위치가 처음 부모위치가 된다.
			for (int k = 0; k < 8; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (ar[px][py] > ar[nx][ny]) // 부모위치 보다 현재위치가 작다면
				{
					px = nx;
					py = ny;
				}
			}
			parent[c * i + j] = c * px + py; // 자식 인덱스의 원소로 부모 인덱스를 삽입
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