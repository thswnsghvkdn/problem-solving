#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int ar[8][8];
vector<pair<int, int>> v(8);

int dist(int x1,int x2,int y1,int y2)
{
	return abs((x1)-(x2)) + abs((y1)-(y2));
}
int main()
{
	int tx, ty;
	for (int i = 0; i < 8; i++)
	{
		cin >> tx >> ty;
		v[i].first = tx;
		v[i].second = ty;
	}
	ar[1][0] = ar[0][1] = dist(v[0].first, v[1].first, v[0].second, v[1].second);
	
	for(int i = 0 ; i < 8 ; i++)
		for (int j = 0; j < 8; j++)
			ar[i][j] = dist(v[i].first, v[j].first, v[i].second, v[j].second);
		
	for (int i = 2; i < 8; i += 2)
		ar[i][i + 1] = ar[i + 1][i] = min( 10 , ar[i][i+1] );

	for(int k = 0 ; k < 8 ; k++)
		for(int i = 0 ; i < 8 ; i++)
			for (int j = 0; j < 8; j++)
			{
				if (i == j) continue;
				ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
			}

	cout << ar[0][1];

}