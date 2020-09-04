#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string reverse(string str)
{
	string ret;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ')') ret += '(';
		else ret += ')';
	}
	return ret;
}
bool check_brace(string str)
{
	if (str[0] == ')') return false;
	stack<char> s;
	s.push(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == ')')
		{
			if (s.empty()) return false;
			s.pop();
		}
		else
			s.push(str[i]);
	}
	return true;
}
string brace(string str)
{
	if (str == "") return "";
	int cnt = 1;
	char tmp = str[0];
	string u = str;
	string v = "";
	for (int i = 1; i < str.size(); i++)
	{
		if (tmp != str[i]) cnt--;
		else if (tmp == str[i]) cnt++;

		if (cnt == 0) {
			u = str.substr(0, i+1);
			if (i == str.size()) break;
			v = str.substr(i+1);
			break;
		}
	}
	if (check_brace(u)) return (u += brace(v));
	string n_str = "(";
	n_str += brace(v);
	n_str += ')';
	u = u.substr(1, u.size() - 2);
	n_str += reverse(u);
	return n_str;
}

string solution(string p)
{
	string answer = "";
	answer = brace(p);
	return answer;
}
int main()
{
	solution("()))((()");
}