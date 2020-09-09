#include <string>
#include <vector>

using namespace std;

pair<string,int> str_tok(string str, int n)
{
	int i = 0;
	if (n == 1) {
		for (; i < str.size(); i++)
		{
			if (str[i] != '?')
				return make_pair(str.substr(i), i);
		}
	}
	else {
		for (; i < str.size(); i++)
			if (str[i] == '?')
				return make_pair(str.substr(0, i), i);
	}
}


vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++)
	{
		auto q = queries[i];
		int cnt = 0;
		pair<string, int> tok;
		if (q[0] == '?')
		{
			tok = str_tok(q, 1); // 뒷부분을 저장한다.
			for (int j = 0; j < words.size(); j++)
			{
				if (words[j].size() == queries[i].size())
				{
					string temp = words[j].substr(tok.second);
					if (temp == tok.first)
						cnt++;
				}
			}
		}
		else {
			tok = str_tok(q, 2);
			for (int j = 0; j < words.size(); j++)
			{
				if (words[j].size() == queries[i].size())
				{
					string temp = words[j].substr(0, tok.second );
					if(temp == tok.first)
						cnt++;
				}
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}
int main()
{
	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
}