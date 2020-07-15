#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v(55);
bool alpha[28];
bool prev_alpha[28];
int k;
int n;
int tot;
int cnt;
int prev_cnt;

void init_alpha()
{
	alpha[0] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
}
void go(string v, int index)
{
	if (index == v.size())
		return;
	if (cnt > k - 5) {
		tot--;
		cnt = prev_cnt;
		copy(prev_alpha, prev_alpha + 28, alpha);
		return;
	}
	if (alpha[v[index] -'a'])
	{
		go(v, index + 1);
	}
	else
	{
		alpha[v[index] - 'a'] = true;
		cnt++;
		go(v, index + 1);
	}
}


int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	init_alpha();
	copy(alpha, alpha + 28, prev_alpha);

	for (int i = 0; i < n; i++)
	{
		tot++;
		go(v[i], 0);
		prev_cnt = cnt;
		copy(alpha, alpha + 28, prev_alpha);
	}
	cout << tot;
}