#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
int arr[1001][1001];
int m_size = 0;
struct Point {
	int x, y, z;
};

void init_ar(vector<Point> v)
{
		for(int i= 0 ; i < n ; i++)
			for (int j = 0; j < n ; j++)
			{
				if (i == j) continue;
				arr[i][j] = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
				if (v[i].z == 1 && v[j].z == 1)
				{
					arr[i][j] = min(arr[i][j], t);
				}
			}

}

void floydWarshall()
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}
int main()
{
	cin >> n >> t;
	vector<Point> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].z >> v[i].x >> v[i].y;
	cin >> m;
	vector<pair<int, int >> v2(m);
	for (int i = 0; i < m; i++)
		cin >> v2[i].first >> v2[i].second;

	init_ar(v);
	floydWarshall();

	for (int i = 0; i < m; i++)
		cout << arr[v2[i].first-1][v2[i].second-1] << endl;


}