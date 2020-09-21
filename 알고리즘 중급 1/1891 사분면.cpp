#include <iostream>

using namespace std;

long long row, col;
pair<long long, long long> rec(string s, int index, long long size, long long row, long long col)
{
	if (index == s.length())
		return (make_pair(row, col));

	switch (s[index])
	{
	case  '1' :
		return rec(s, index + 1, size / 2, row, col + (size / 2));
	
	case '2':
		return rec(s, index + 1, size / 2, row, col);
	
	case '3' :
		return rec(s, index + 1, size / 2, row + (size / 2), col );
		
	default :
		return rec(s, index + 1, size / 2, row + (size / 2), col + (size / 2));
	}
}

string rec2(string s, long long size, long long start, long long end)
{
	long long range = size / 2;
	if (size == 1)
		return s;
	if (row >= start && row < ( start + range ) && col >= start && col < ( start + range ))
	{
		s += '2';
		return rec2(s, size / 2, start, end);
	}
	if (row >= ( start + range )&& row < (start + size) && col >= start && col < (start + range))
	{
		s += '3';
		return rec2(s, size / 2, start + range, end);
	}
	if (row >= (start + range) && row <(start + size) && col >= ( start + range )  && col < ( start + size ) )
	{
		s += '4';
		return rec2(s, size / 2, start + range, end + range);
	}

	s += '1';
	return rec2(s, size / 2, start, end + range);

}
int main()
{
	int d;
	string s;
	long long size;
	cin >> d;
	cin >> s;
	size = 1LL << d;
	auto p = rec(s, 0, size, 0, 0);
	row = p.first;
	col = p.second;
	int a, b;
	cin >> a >> b;
	row -= b;
	col += a;
	string temp, answer;
	if (row >= 0 && row < size && col >= 0 && col < size) {
		s = rec2(temp, size, 0, 0);
		cout << s;
	}
	else
		cout << -1;

}