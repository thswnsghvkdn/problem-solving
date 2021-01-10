#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

int ans = -1;
int n;
int  B[51];



void div()
{
	for (int i = 0; i < n; i++)
		B[i] /= 2;
	return;
}
bool isSame()
{
	for (int i = 0; i < n; i++)
		if (B[i]) return false;
	return true;
}



int isOdd() // b�迭���� Ȧ���� ī��Ʈ
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (B[i] % 2)
		{
			cnt++;
			B[i]--;
		}
	return cnt;
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> B[i];
	
	int cnt = 0;
	while (1)
	{
		if (isSame())
		{
			cout << cnt;
			return 0;
		}
		cnt += isOdd();
		if (isSame())
		{
			cout << cnt;
			return 0;
		}
		div();
		cnt++;
	}


}
