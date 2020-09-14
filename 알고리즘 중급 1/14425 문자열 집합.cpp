#include <iostream>
#include <vector>

using namespace std;

struct Node {
	bool isEnd;
	vector<Node*> node;
	Node() {
		node.assign(26, nullptr);
		isEnd = false;
	}
};
void insertNode(Node* node, string str, int index)
{
	if (index == str.size()) {
		node->isEnd = true;
		return;
	}
	if(node->node[str[index] - 'a'] == nullptr)
	{
		node->node[str[index] - 'a'] = new Node();
	}
	insertNode(node->node[str[index] - 'a'], str, index + 1);
}
bool find(Node* node, string str)
{
	if (str == "")
	{
		if (node->isEnd) return true;
		else return false;
	}
	else if (node->node[str[0] - 'a'] == NULL)
		return false;

	return find(node->node[str[0] - 'a'], str.substr(1));
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s1(n);
	vector<string> s2(m);
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		s1[i] = temp;
	}
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		s2[i] = temp;
	}
	Node node;
	for (int i = 0; i < n; i++)
		insertNode(&node, s1[i], 0);
	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (find(&node, s2[i])) cnt++;

	cout << cnt;
	return 0;
}