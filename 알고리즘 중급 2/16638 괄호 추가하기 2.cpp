#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string str;
int n; // 수식 길이
long long sum_max; // 결과의 최댓값
struct Oper{
	char ch; // 연산자
	int pri; // 우선순위 , 우선수위 3은 숫자를 나타낸다.
}; // 연산자 구조체
stack<long long> s2; // 피연산자 스택
stack<long long> res; // 후위표기자 결과를 저장할 스택

void cal(queue<char> &post, stack<Oper> &s1)
{
	while (!s1.empty())
	{
		post.push(s1.top().ch);
		s1.pop();
	}
	long long a, b, r; //연산시에 사용할 변수
	while (!post.empty()) // 후위표기자 스택에 데이터가 남아있는경우 반복
	{
		char ch = post.front();
		if (ch >= 0 && ch <= 9) // 피연산자의 경우
		{
			res.push(ch);
		}
		else
		{
			b = res.top();
			res.pop();
			a = res.top();
			res.pop();
			switch (ch)
			{
			case '*':
				r = a * b;
				break;
			case '+':
				r = a + b;
				break;
			case '-':
				r = a - b;
				break;
			}
			res.push(r);
		}
		post.pop();
	}
	sum_max  = max(sum_max, res.top());
	res.pop();
	return;
}

void input(Oper op, queue<char> &post, stack<Oper> &s1) // 연산자의 우선순위에 따라 스택에 삽입한다.
{
	if (s1.empty()) // 연산자 스택이 비어있으면 push
	{
		s1.push(op);
		return;
	}
	while (!s1.empty() && s1.top().pri >= op.pri) // 스택의 최상위 연산자가 우선순위가 높거나 같은경우 후위표기자 스택에 저장한다.
	{
		post.push(s1.top().ch);
		s1.pop();
	}
	s1.push(op);
}




int get_pri(char ch) // 연산자의 우선순위
{
	switch (ch)
	{
	case '+' : case '-' :
		return 0;
	case '*' :
		return 1;
	}
}


void dfs(queue<char> &post, stack<Oper> &s1, int index) // 두개의 스택에 dfs 방식으로 연산순위를 다르게 하여 저장
{
	queue<char> post2 = post;
	stack<Oper> s2 = s1;
	if (index + 1 == n)
	{
		post.push(str[index] - '0');
		cal(post, s1);
		return;
	}
	post2.push(str[index] - '0');
	input({ str[index + 1] , get_pri(str[index + 1]) } , post2 , s2);
	dfs(post2 , s2 ,index + 2);
	post.push(str[index] - '0');
	input({ str[index + 1], 2 } , post, s1);
	dfs(post , s1, index + 2);

}

int main()
{
	queue<char> post;
	stack<Oper> s1;

	cin >> n;
	cin >> str;
	dfs(post, s1, 0);
	cout << sum_max;

}
