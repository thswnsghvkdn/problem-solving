#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point  // 사각형의 높이 넓이
{
	int r, c;
};
int num; // 개수 
int height, width; // 스티커판의 높이 넓이 

bool checkSticker(int r1, int c1, int r2, int c2)
{
	if (width >= (r1 + r2) && height >= max(c1, c2)) return true;
	if (width >= max(r1 , r2) && height >= (c1 + c2)) return true;
	return false;
}

bool isPossible(int r1, int c1, int r2, int c2)
{
	if (checkSticker(r1, c1, r2, c2)) return true;
	if (checkSticker(c1, r1, r2, c2)) return true;
	if (checkSticker(r1, c1, c2, r2)) return true;
	if (checkSticker(c1, r1, c2, r2)) return true;
	return false;
}

int main()
{
	cin >> width >> height;
	cin >> num;
	vector<Point> v(num);
	for (int i = 0; i < num; i++)
		cin >> v[i].r >> v[i].c;
	
	int ans = 0;
	for(int i  =0 ; i < num ; i++)
		for (int j = i + 1; j < num; j++)
			if (isPossible(v[i].r, v[i].c, v[j].r, v[j].c)) ans = max(ans, ((v[i].r * v[i].c) + (v[j].r * v[j].c)));

	cout << ans;
}