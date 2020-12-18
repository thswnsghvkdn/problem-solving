#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string str;
int n; // 수식 길이
long long sum_max; // 결과의 최댓값
struct Oper{
	char ch; // 연산자
	int pri; // 우선순위
}; // 연산자 구조체
stack<Oper> s1; // 연산자 스택
stack<long long> s2; // 피연산자 스택

long long cal(long long a, long long b, char ch)
{
	switch (ch)
	{
	case '*' :
		return a * b;
	case '+' :
		return a + b;
	case '-' :
		return a - b;
	}
}

void input(Oper op) // 중위 연산자를 계산하는 함수
{
	if (s1.empty() || op.pri > s1.top().pri)
	{
		s1.push(op);
		return;
	}
	else if (op.pri <= s1.top().pri) // 새로 들어온 연산자가 우선순위가 더 높거나 같은 경우 계산
	{
		while (!s1.empty()) {
			long long b = s2.top();
			s2.pop();
			long long a = s2.top();
			s2.pop();
			char ch = s1.top().ch;
			s1.pop();
			s2.push(cal(a, b, ch)); // s2에 결과를 저장한다. 
		}
		s1.push(op);
		return;
	}
	

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
void dfs(int index) // 두개의 스택에 dfs 방식으로 연산순위를 다르게 하여 저장
{
	if (index + 1 == n)
	{
		s2.push(str[index] - '0');
		while (!s1.empty()) {
			long long b = s2.top();
			s2.pop();
			long long a = s2.top();
			s2.pop();
			char ch = s1.top().ch;
			s1.pop();
			s2.push(cal(a, b, ch)); // s2에 결과를 저장한다. 
		}
		long long res = s2.top();
		s2.pop();
		sum_max = max(sum_max, res);
		return;
	}
	s2.push(str[index] - '0');
	input({ str[index + 1] , get_pri(str[index + 1]) });
	dfs(index + 2);
	s2.push(str[index] - '0');
	input({ str[index + 1], 2 });
	dfs(index + 2);


}

int main()
{
	cin >> n;
	cin >> str;
	dfs(0);
	cout << sum_max;

}
