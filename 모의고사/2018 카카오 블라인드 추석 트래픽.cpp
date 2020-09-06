#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;



float t_min = 86400;
float t_max = 0;
pair<float, float> returnTime(string s) // ���۽ð��� ���� �ð� ��ȯ
{
	stringstream ss;
	ss.str(s);
	string temp;
	ss >> temp;
	ss >> temp; // ���۽ð��� �����´�. 
	float dur;
	ss >> dur; // ó���ð��� �����´�.
	float hour = ((temp[0] - '0') * 10 + (temp[1] - '0')) * 3600; // �ð��� �ʷ�
	float min = ((temp[3] - '0') * 10 + (temp[4] - '0')) * 60; // ���� �ʷ�
	temp = temp.substr(6); // ������ �ʸ� �����´�.
	float sec = stof(temp);
	float end = hour + min + sec;
	float start = end - dur;
	start += 0.001;
	if (start < t_min)
		t_min = start;
	if (end > t_max)
		t_max = end;
	return make_pair(start, end);
}
bool inTime(pair<float, float> v, float time)
{
	float start = time;
	float end = time + 0.999;
	bool one = false, two = false;

	if (v.first < end || abs(v.first - end) < 0.0008)
		if(v.second > start || abs(v.second - start) < 0.0008)
		     return true;
	return false;
}
int solution(vector<string> lines)
{
	int answer = 0;
	string temp;
	vector<pair<float, float> > v(2001);
	for (int i = 0; i < lines.size(); i++)
	{
		v[i] = returnTime(lines[i]);
	}
	for (int i = 0; i < lines.size(); i++) // �ϳ��� Ʈ������ ������ �ð��� �������� 1�ʵ��� ������ Ʈ������ ������ ������.��
	{
		float time = v[i].second;
		int tot = 0;
		for (int j = 0; j < lines.size(); j++)
		{
			if (inTime(v[j], time)) tot++;
		}
		if (answer < tot)
			answer = tot;
	}

	return answer;

}
int main()
{
	solution({ 
"2016-09-15 01:00:04.001 2.0s",
"2016-09-15 01:00:07.000 2s"

/*"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
		*/});
}