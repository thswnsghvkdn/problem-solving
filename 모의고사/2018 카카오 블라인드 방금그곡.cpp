#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TEMP {
	int min;
	string name;
	string code;
};
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
	for (; i < str.size(); i++)
	{
		temp.code += str[i];
	}
	return temp;

}
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


string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int max = 0;
	m = CtoI(m);
	for (int i = 0; i < musicinfos.size(); i++)
	{
		auto temp = str_tok(musicinfos[i]);
		temp.code = CtoI(temp.code);
		for (int j = 0; j < temp.code.size(); j++)
		{
			if (m[0] == temp.code[j])
			{
				string str = temp.code.substr(j) + temp.code.substr(0, j); // 포함여부를 알기위해 코드 재배치 
				if (str.size() >= m.size())
				{
					if (str.find(m) != string::npos && max < temp.min)
					{
						max = temp.min;
						answer = temp.name;
						
					}
					break;
				}
				else
				{
					if (m.find(str) != string::npos && max < temp.min)
					{
						max = temp.min;
						answer = temp.name;
					}
					break;
				}
			}
		}

	}
	if (answer == "")
		answer = "`(None)`";
	return answer;
}
int main()
{
	solution("ABC", { "03:00,03:30,FOO,A#", "03:00,03:30,BAR,zz" });
}