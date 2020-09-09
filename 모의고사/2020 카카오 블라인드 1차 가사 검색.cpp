#include <string>
#include <vector>
#include <algorithm>
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
vector<string> remove(vector<string> v, int s)
{
	vector<string> temp;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() < s) continue;
		temp.push_back(v[i].substr(s-1));
	}
	return temp;
}
int find_word(vector<string> words, int key_size, string key)
{
	int start = 0;
	int end = words.size() - 1;
	int cen = (start + end) / 2;
	int cnt = 0;
	bool find = false;
	while (words[++start].size() < key_size);
	while (start < end)
	{
		cen = (start + end) / 2;
		if (key_size == words[cen].size() && key == words[cen].substr(0, key.size()) )
		{
			while (cen >= 0 && key_size == words[cen].size() && key == words[cen].substr(0, key.size()) ) // 여러 동일 단어중 가장 윗 인덱스를  찾는다.
				cen--;
			cen++;
			find = true;
			break;
		}
		else if (key > words[cen])
			start = cen + 1;
		else
			end = cen - 1;
	}
	if (find)
	{
		while (key_size == words[cen].size() && key == words[cen].substr(0, key.size()))
		{
			cnt++;
			cen++;
		}
	}
	return cnt;
}
int find_word2(vector<string> words, string key)
{
	int start = 0;
	int end = words.size() - 1;
	int cen = (start + end) / 2;
	int cnt = 0;
	bool find = false;
	while (start < end)
	{
		cen = (start + end) / 2;
		if ( key == words[cen].substr(0, key.size()))
		{
			while (cen >= 0  && key == words[cen].substr(0, key.size())) // 여러 동일 단어중 가장 윗 인덱스를  찾는다.
				cen--;
			cen++;
			find = true;
			break;
		}
		else if (key > words[cen])
			start = cen + 1;
		else
			end = cen - 1;
	}
	if (find)
	{
		while ( key == words[cen].substr(0, key.size()))
		{
			cnt++;
			cen++;
		}
	}
	return cnt;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<vector<string>> w_list;
	int max = 0;
	for (int i = 0; i < words.size(); i++)
		if (words[i].size() > max) max = words[i].size();
	sort(words.begin(), words.end());
	w_list.push_back(words);
	for (int i = 2; i <= max; i++)
	{
		vector<string> temp = remove(words, i);
		sort(temp.begin(), temp.end());
		w_list.push_back(temp);
	}

	for (int i = 0; i < queries.size(); i++)
	{
		auto q = queries[i];
		int cnt = 0;
		pair<string, int> tok;
		if (q[0] == '?') {
			tok = str_tok(q, 1); // 뒷부분을 저장한다.
			cnt = find_word2(w_list[tok.second], tok.first);
		}
		else {
			tok = str_tok(q, 2);
			cnt = find_word(w_list[0], queries[i].size(), tok.first);
		}
		answer.push_back(cnt);
	}
	return answer;
}
int main()
{
	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
}