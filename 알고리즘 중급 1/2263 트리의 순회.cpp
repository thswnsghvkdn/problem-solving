#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001
int postorder[MAX];
int inorder[MAX];
int position[MAX];

void preorder(int in_s, int in_e, int po_s, int po_e)
{
	if (in_s > in_e || po_s > po_e) return;

	cout << postorder[po_e] << ' ';
	int pos = position[postorder[po_e]];

	preorder(in_s, pos - 1, po_s ,po_s + pos);
	preorder(pos + 1, in_e, pos + in_s, po_e - 1);

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];

	for (int i = 0; i < n; i++)
		position[inorder[i]] = i;

	preorder(0, n - 1, 0, n - 1);

}