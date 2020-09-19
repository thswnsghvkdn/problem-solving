#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 100001
int in[MAX];
int post[MAX];
int position[MAX];

void preorder(int i_s, int i_e, int p_s, int p_e)
{
	if (i_s > i_e || p_s > p_e) return;

	int pos = position[post[p_e]];
	//cout << post[p_e] << ' ';
	printf("%d ", post[p_e]);

	preorder(i_s, pos - 1, p_s, p_s + (pos - i_s) - 1);
	preorder(pos + 1, i_e, p_s + (pos - i_s) - 1, p_e - 1);

}
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &in[i]);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &post[i]);

	for (int i = 0; i < n; i++)
		position[in[i]] = i;

	preorder(0, n - 1, 0, n - 1);
	cout << "\n";
}