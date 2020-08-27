#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> TimeToInt(vector<string> timetable) // 시간을 정수로 
{
	vector<int> v;
	for (int i = 0; i < timetable.size(); i++)
	{
		stringstream temp;
		temp.str(timetable[i]);
		
		int hour;
		char c; // :
		int min;
		temp >> hour;
		hour *= 100;
		c = temp.get();
		temp >> min;
		hour += min;

		v.push_back(hour);
	}
	sort(v.begin(), v.end());
	return v;
}
string IntToTime(int n)
{
	string time;
	for (int i = 0; i < 4; i++, n/= 10)
	{
		if (i == 2)
			time = ':' + time;
		time = (char)((n % 10) + '0') + time;
	}
	return time;
}
int MakeTable(int n, int t, int m, vector<int> time)
{
	vector<int> v[11];

	int start = 900;
	bool flag = false;
	for (int i = 0, k= 0; i < n; i++, start += t)
	{
		if (start % 100 >= 60)
		{
			start += 40;
		}
		for (int j = 0; j < m; j++)
		{
			if (k == time.size() || time[k] > start) break;
			v[i].push_back(time[k++]);
		}

	}
	start -= t;
	if (v[n - 1].size() < m)
	{
		return start;
	}
	else
	{
		if (v[n - 1].back() % 100 == 0)
		{
			return v[n - 1].back() - 41;
		}
		return v[n - 1].back() - 1;
	}
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> time = TimeToInt(timetable);
	int a = MakeTable(n, t, m, time);
	answer = IntToTime(a);
	return answer;
}

int main()
{
	cout << solution(10, 60, 45, { "23:59", "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59","23:59", "23:59", "23:59", "23:59" });
}