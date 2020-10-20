#include <iostream>
#include <vector>
using namespace std;
// 좌표를 이동할 4방향
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m; // 문제의 행 , 열
struct Point{
	int row;
	int col;
	int size;
}; // 별 중심의 위치와 크기 구조체
vector<Point> v; // 구조체를 추가해나갈 벡터
char star[110][110]; // 문제의 지도를 저장 할 배열
char spareStar[110][110]; // 비교해나갈 배열 

void drawSpare(int x, int y, int size)
{
	int nSize = 1;
	spareStar[x][y] = '*';
	while (nSize <= size)
	{
		for (int i = 0; i < n; i++) // 인수로 받은 사이즈 만큼 뻗어나가면 별을 그린다.
		{
			int nx = x + dx[i] * nSize;
			int ny = y + dy[i] * nSize;
			spareStar[nx][ny] = '*';
		}
		nSize++;
	}
}

int checkCenter(int x, int y) // 중심점을 받아 4방향의 별이 뻗어있는지 검사
{
	int size = 1;
	int nx, ny;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + (dx[i] * size);
			ny = y + (dy[i] * size);
			if (nx < 1 || nx > n || ny < 1 || ny > m) // 뻗어나간 좌표가 범위내에 있는지 검사
				return size - 1; // 사이즈를 낮추어 반환
			if (star[nx][ny] == '.') // 뻗어나간 좌표가 별이 없는지 반환
				return size - 1; // 사이즈를 낮추어 반환
		}
		// 정상적으로 뻗어나갔다면 
		size++;
	}
}


int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n ; i++)
		for (int j = 1; j <= m; j++) 
			cin >> star[i][j];
	// spareStar초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			spareStar[i][j] = '.';


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (star[i][j] == '*') // 별을 기준으로 뻗어나가도록 검사한다.
			{
				int size = checkCenter(i, j);
				if (size) // size가 1이상인 별이 들어온경우
				{
					v.push_back({ i , j , size }); // 벡터에 정보를 저장
					drawSpare(i, j, size); // spareStar에 해당 별을 그린다.
				}
			}
		}

	for (int i = 1; i <= n; i++) // 스페어와 원본을 검사한다.
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