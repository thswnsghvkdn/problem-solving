#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>v;
int ar[3];
void recur(int index, int row, int col)
{
	int num = v[row][col];
	int n_index = index / 3;
	for(int i = row ; i < row + index ; i++)
		for(int j = col ; j < col + index; j++)
			if (v[i][j] != num) {
				for (int a = 0; a < 3; a++)
					for (int b = 0; b < 3; b++)
						recur(n_index, row + a * n_index, col + b * n_index);
				return;
			}
	ar[num + 1]++;
}
int main()
{
	int n;
	cin >> n;
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
		v.push_back(temp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	recur(n, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << ar[i] << endl;
}