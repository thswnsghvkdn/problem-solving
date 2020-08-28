#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

using namespace std;
short a, b, C[676], D[676];
int solution(string A, string B) {
	// 2개의 알파벳에 대한 비트 마스킹 ex ) [a][b]
	int C[700] = { 0 };
	int D[700] = { 0 };
	for (int i = 0; i < A.size() - 1; i++)
		if (isalpha(A[i]) && isalpha(A[i + 1])) // 비트연산으로 알파벳처리 'A' = 10 0001
			C[(A[i] & 31) * 26 + (A[i + 1] & 31)]++;
	
	for (int i = 0; i < B.size() - 1; i++)
		if (isalpha(B[i]) && isalpha(B[i + 1]))
			D[(B[i] & 31) * 26 + (B[i + 1] & 31)]++;
	double s_min = 0, s_max = 0;
	for (int i = 0; i < 700; i++)
	{
		s_min += min(C[i], D[i]);
		s_max += max(C[i], D[i]);
	}
	double tot = 1;
	if (s_max != 0)
		tot = s_min / s_max;
	return tot * 65536;
}
int main()
{
	cout << solution("FRANCE", "french");
}
