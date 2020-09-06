#include <string>

using namespace std;

bool check_brace(string str)
{
	int cnt = 0;
	for (char c : str)
	{
		if (c == ')') cnt--;
		else cnt++;
		if (cnt < 0) return false;
	}
	return true;
}

string solution(string p)
{
	string answer = "";
	if (check_brace(p)) return p;
	int cnt = 0, i = 1;
	for (; i < p.size(); i++)
	{
		if (cnt < 0) break;
		if (p[i] != p[0])cnt--;
		else cnt++;
	}
	string u = p.substr(0, i + 1);
	string v = p.substr(i + 1);
	if (check_brace(u)) return u + solution(v);

	for (char& c : u) c = c == ')' ? '(' : ')';
	return '(' + solution(v) + ')' + u.substr(1 , u.size() - 2);
}