#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
struct CCTV
{
	int r, c, type;
};
vector<CCTV> v;
int row;
int col; 
int rot[] = { 4 , 2, 4, 4 , 1 };
int map[10][10];
int ans = 999;

int cnt() // 빈칸세기
{
	int space = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (!map[i][j]) space++;
	return space;
}

void copy_map(int origin[10][10], int backup[10][10]) // 뒤에 오는 인수에 복사하기 
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			backup[i][j] = origin[i][j];
}
void move(int dir, CCTV cctv)
{
	int nx = cctv.r;
	int ny = cctv.c;
	switch (dir)
	{
	case 0 : // 북쪽
		nx--;
		while (nx >= 0)
		{
			if (map[nx][ny] == 6) break;
			if (!map[nx][ny])
			map[nx][ny] = -1;
			nx--;
		}
		break;
	case 1: // 동쪽
		ny++;
		while (ny < col)
		{
			if (map[nx][ny] == 6) break;
			if(!map[nx][ny])
			map[nx][ny] = -1;
			ny++;
		}
		break;
	case 3: // 서쪽
		ny--;
		while (ny >= 0)
		{
			if (map[nx][ny] == 6) break;
			if (!map[nx][ny])
			map[nx][ny] = -1;
			ny--;
		}
		break;
	default: // 남쪽
		nx++;
		while (nx < row)
		{
			if (map[nx][ny] == 6) break;
			if (!map[nx][ny])
			map[nx][ny] = -1;
			nx++;
		}
		break;
	}
}

void dfs(int count)
{
	if (count == v.size())
	{
		int temp = cnt();
		ans = min(ans, temp);
		return;
	}
	for (int i = 0; i < rot[v[count].type]; i++)
	{
		auto temp = v[count];
		int t_map[10][10];
		copy_map(map, t_map);
		switch (temp.type)
		{
		case 0 :
			move(i, temp);
			dfs(count + 1);
			break;
		case 1:
			move(i, temp);
			move( (i + 2 ) % 4, temp);
			dfs(count + 1);
			break;
		case 2 :
			move(i, temp);
			move((i + 1) % 4, temp);
			dfs(count + 1);
			break;
		case 3:
			move(i, temp);
			move((i + 1) % 4, temp);
			move((i + 2) % 4, temp);
			dfs(count + 1);
			break;
		default:
			move(i, temp);
			move((i + 1) % 4, temp);
			move((i + 2) % 4, temp);
			move((i + 3) % 4, temp);
			dfs(count + 1);
			break;
		}
		copy_map(t_map, map);
	}
}


int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0)
				v.push_back({ i , j , map[i][j] - 1 });
		}

	dfs(0);
	cout << ans;
}