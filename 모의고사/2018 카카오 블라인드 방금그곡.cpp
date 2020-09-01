#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TEMP {
	int min;
	string name;
	string code;
};
string CtoI(string str) // #을 다른 문자로 바꿀것(+7)
{
	string temp;
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (str[i + 1] == '#')
		{
			i++;
			ch += 7;
		}
		temp += ch;
	}
	return temp;
}

TEMP str_tok(string str)
{
	TEMP temp;
	// 시간을 분으로 바꾸어 플레이 타임 저장
	int hour = (((str[0] - '0') * 10) + (str[1] - '0')) * 60;
	int min = ((str[3] - '0') * 10) + (str[4] - '0');
	hour += min;
	int hour2 = (((str[6] - '0') * 10) + (str[7] - '0')) * 60;
	int min2 = ((str[9] - '0') * 10) + (str[10] - '0');
	hour2 += min2;
	
	hour2 -= hour;
	temp.min = hour2;

	int i = 12;
	for (; i < str.size(); i++)
	{
		if (str[i] == ',') {
			i++;
			break;
		}
		else temp.name += str[i];
	}
	string code;
	for (; i < str.size(); i++)
	{
		code += str[i];
	}
	code = CtoI(code);
	for (int i = 0; i < temp.min; i++)
	{
		int index = i % code.size();
		temp.code += code[index];
	}
	return temp;

}


string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	int max = 0;
	m = CtoI(m);
	for (int i = 0; i < musicinfos.size(); i++)
	{
		auto temp = str_tok(musicinfos[i]);
		temp.code = CtoI(temp.code);
		if (temp.code.find(m) != string::npos && max < temp.min)
		{
			max = temp.min;
			answer = temp.name;
		}
	}
	return answer;
}
int main()
{
	solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });
}