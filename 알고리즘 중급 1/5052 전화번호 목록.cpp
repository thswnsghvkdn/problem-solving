#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Trie {
	Trie* arr[10];
public :

	Trie()
	{
		for (int i = 0; i < 10; i++)
			arr[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (arr[i] != NULL)
				delete arr[i];
	}
	void insert(string words)
	{
		if (words[1] == '\0') return;
		int next = words[0] - '0';
		if (arr[next] == NULL)
			arr[next] = new Trie();
		arr[next]->insert(words.substr(1));
	}
	bool find(string words)
	{
		int temp = words[0] - '0';


		if (arr[temp] == NULL) return true;
		if (words[1] == '\0' && arr[temp] != NULL) return false;



		return arr[temp]->find(words.substr(1));
	}
};
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> v;
		Trie tri;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			v.push_back(temp);
			tri.insert(temp);
		}
		for (int i = 0; i < n; i++)
		{
			if (!tri.find(v[i])) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << endl;

	 }
}