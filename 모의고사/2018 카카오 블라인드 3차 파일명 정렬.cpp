#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

struct STR{
	string head;
	int tail;
	int index;
};
bool cmp(STR s1, STR s2)
{
	if (s1.head == s2.head) return s1.tail < s2.tail;
	return s1.head < s2.head;
}
STR str_tok(string temp, int index)
{
	string head;
	int tail = 0;
	int i = 0;
	for (; i < temp.size(); i++)
	{
		if (isdigit(temp[i])) break;

		else {
			if(isalpha(temp[i]))
				temp[i] = tolower(temp[i]);
			head += temp[i];
		}
	}

	
	for ( ; i < temp.size(); i++)
	{
		if (isdigit(temp[i]))
			tail = (tail * 10) + (temp[i] - '0');
		else break;
	}
	return { head, tail, index };
}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<STR> tok;
	stringstream ss;

	for (int i = 0; i < files.size(); i++)
		tok.push_back(str_tok(files[i], i));
	
	sort(tok.begin(), tok.end(), cmp);
	for (int i = 0; i < tok.size(); i++)
		answer.push_back(files[tok[i].index]);

	return answer;
}
int main()
{
	solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });
}