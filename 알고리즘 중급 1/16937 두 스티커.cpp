#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point  // 사각형의 높이 넓이
{
	int r, c;
};

int sticker(int r, int c, int r_input, int c_input) // 스티커를 붙일 수 있는지 검사 
{
	if (r >= r_input && c >= c_input) return 1; // 스티커를 돌리지 않고 붙였으면 1
	if (r >= c_input && c >= r_input) return 2; // 스티커를 돌려서 붙여야 하면 2
	else return 0;
}
int main()
{
	int row, col;
	cin >> row >> col;
	int num;
	cin >> num;
	vector<Point> v(num);
	int nr, nc;
	for (int i = 0; i < num; i++)
	{
		cin >> v[i].r >> v[i].c;
	}

	int ans = 0; // 정답
	for (int i = 0; i < num - 1; i++) // 입력받은 벡터의 크기 - 1 만큼 반복
	{
		int command = sticker(row, col, v[i].r, v[i].c);
		if (command == 1)
		{

			for (int j = i + 1; j < num; j++) // 두번째 도형은 i+1 부터 num까지 반복
			{
				int n_r = row - max(v[i].r , v[j].r);
				int n_c = col - max(v[i].c , v[j].c);
				if (sticker(n_r, col, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
				if (sticker(row, n_c, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
			}
		}
		if (command == 2)
		{

			for (int j = i + 1; j < num; j++) // 두번째 도형은 i+1 부터 num까지 반복
			{
				int n_r = row - max(v[i].c, v[j].c);
				int n_c = col - max(v[i].c, v[j].c);
				if (sticker(n_r, col, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
				if (sticker(row, n_c, v[j].r, v[j].c)) ans = max(ans, (v[i].r * v[i].c) + (v[j].r) * (v[j].c));
			}
		}
		else continue;
	}
	cout << ans;
}