#include<iostream>
#include <memory.h>
#include <queue>
using namespace std;

int n; 


int command_L(int temp)
{
	int share = temp / 1000;
	temp %= 1000;
	temp *= 10;
	return (temp + share);
}
int command_R(int temp)
{
	int md = temp % 10;
	temp /= 10;
	md *= 1000;
	if (md == 0)
		md = 1000;
	return (temp + md);
}
int main()
{
	cin >> n;

	bool check[10005];
	int temp1, goal;
	string str = "";
	int arr;
	string t_str;
	bool flag = false;
	while (n--)
	{
		memset(check, 0, sizeof(check));
		str = "";
		flag = false;
		cin >> temp1 >> goal;

		
		queue<pair<int, string>>q;
		q.push(make_pair(temp1, str));
		while (!q.empty() && flag == false) {
			auto test = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (flag == true) break;

				switch (i)
				{
				case 0:
				{
					arr = test.first;
					t_str = test.second;
					t_str += 'D';
					arr *= 2;
					if (arr > 9999)
					{
						arr %= 10000;
					}
					if (arr == goal) {
						cout << t_str << "\n";
						flag = true;
						break;
					}

					if (check[arr]) break;
					check[arr] = true;
					q.push(make_pair(arr, t_str));
					break;
				}
				case 1:
				{
					arr = test.first;
					t_str = test.second;
					t_str += 'S';
					arr -= 1;
					if (arr < 0)
					{
						arr = 9999;
					}
					if (arr == goal) {
						cout << t_str << "\n";
						flag = true;
						break;

					}

					if (check[arr]) break;
					check[arr] = true;
					q.push(make_pair(arr, t_str));
					break;
				}
				case 2:
				{
					arr = test.first;
					t_str = test.second;
					t_str += 'L';
					arr = command_L(arr);
					if (arr == goal) {
						cout << t_str << "\n";
						flag = true;
						break;

					}

					if (check[arr]) break;
					check[arr] = true;
					q.push(make_pair(arr, t_str));
					break;
				}
				case 3:
				{
					arr = test.first;
					t_str = test.second;
					t_str += 'R';
					arr = command_R(arr);
					if (arr == goal) {
						cout << t_str << "\n";
						flag = true;
						break;

					}

					if (check[arr]) break;
					check[arr] = true;
					q.push(make_pair(arr, t_str));
					break;
				}
				default:
					break;
				}
			}
		}
	}
}


