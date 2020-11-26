#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> friends[4001];
bool friendship[4001][4001];
int n, m;
int ans = -1;
int first;


int main()
{
	cin >> n >> m;
	int t1, t2;
	for (int i = 1; i <= m; i++)
	{
		cin >> t1 >> t2;
		friends[t1].push_back(t2);
		friends[t2].push_back(t1);
		friendship[t1][t2] = friendship[t2][t1] = true;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (friendship[i][j] == false) continue;
			for (int k = j + 1; k <= m; k++)
			{
				if (friendship[j][k] == false) continue;
				if (friendship[i][k])
				{
					int temp = friends[i].size() + friends[j].size() + friends[k].size();
					temp -= 6;
					if (ans == -1 || ans > temp)
						ans = temp;
				}
			}
		}
	}
	cout << ans;
}