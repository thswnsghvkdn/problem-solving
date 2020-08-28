#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

string to_lower(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = tolower(str[i]);
	}
	return str;
}
int sumset(vector<string> v1, vector<string> v2)
{
	vector<string>::iterator it;
	vector<string> inter;
	for (int i = 0; i < v1.size(); i++)
	{
		it = find(v2.begin(), v2.end(), v1[i]);
		if (it != v2.end())
		{
			v2.erase(it);
			inter.push_back(v1[i]);
		}
	}
	for (int i = 0; i < v2.size(); i++)
	{
		v1.push_back(v2[i]);
	}
	double size1 = inter.size();
	double size2 = v1.size();
	double ans = 1;
	if(size2 != 0)
		ans = size1 / size2;
	return ans * 65536;
}
int solution(string str1, string str2) {
	int answer = 0;
	str1 = to_lower(str1);
	str2 = to_lower(str2);
	vector<string> v1, v2;
	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
		{
			string temp = "";
			temp += str1[i];
			temp += str1[i+1];

			v1.push_back(temp);
		}
	}
	for (int i = 0; i < str2.size() - 1; i++)
	{
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
		{
			string temp = "";
			temp += str2[i];
			temp += str2[i + 1];
			v2.push_back(temp);
		}
	}
	answer = sumset(v1, v2);

	return answer;
}
int main()
{
	cout << solution("E=M*C^2", "e=m*c^2");
}