#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dic;
	char alpha = 'A';
	for (; alpha <= 'Z'; alpha++)
	{
		string temp;
		temp = alpha;
		dic.push_back(temp);
	}
	for (int i = 0; i < msg.size();)
	{
		int index;
		string new_item;
		string temp;
		temp = msg[i];
		while (1) {

			bool find = false;


			int j = 0;
			for (j = 0; j < dic.size(); j++)
			{
				if(temp == dic[j])
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				temp = temp + msg[++i];
				index = j;
			}
			else {
				dic.push_back(temp);
				break;
			}

		}
		answer.push_back(index+1);
	}
	return answer;
}

int main()
{
	auto temp = solution("KAKAO");

}