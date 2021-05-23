#include <iostream>
#include <string>

using namespace std;

//수에서 영어로
string arabiaToeng(int n)
{
	string r;
	if (n == 0) r = "zero";
	else if (n == 1) r = "one";
	else if (n == 2) r = "two";
	else if (n == 3) r = "three";
	else if (n == 4) r = "four";
	else if (n == 5) r = "five";
	else if (n == 6) r = "six";
	else if (n == 7) r = "seven";
	else if (n == 8) r = "eight";
	else if (n == 9) r = "nine";
	else if (n == 10) r = "ten";
	return r;
}

//영어에서 수로
int arabia(string s)
{
	int r;
	if (s == "zero") r = 0;
	else if (s == "one") r = 1;
	else if (s == "two") r = 2;
	else if (s == "three") r = 3;
	else if (s == "four") r = 4;
	else if (s == "five") r = 5;
	else if (s == "six") r = 6;
	else if (s == "seven") r = 7;
	else if (s == "eight") r = 8;
	else if (s == "nine") r = 9;
	else if (s == "ten") r = 10;
	return r;
}

//연산자에 맞는 연산 진행
int operation(int a, int b, char op)
{
	int r;
	switch (op)
	{
	case '+':
		r = a + b;
		break;
	case '-':
		r = a - b;
		break;
	case '*':
		r = a * b;
		break;
	default:
		break;
	}
	return r;
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		string A, B, result, com;
		char op, temp;
		int a, b;
		cin >> A >> op >> B >> temp >> result;
		a = arabia(A);				//수로 변환
		b = arabia(B);
		a = operation(a, b, op);	//연산 진행
		com = arabiaToeng(a);		//결과값 문자열로 변환
		if (com.length() != result.length() || (a < 0 && a > 10))	//길이가 다르거나 값이 초과했을 경우
		{
			cout << "No" << endl;
			continue;
		}
		int cnt = 0;
		int memo[10];	//j값 중복 방지
		for (int i = 0; i < com.length(); i++)
		{
			for (int j = 0; j < result.length(); j++)
			{
				int k = -1;
				for (int q = 0; q < i; q++) {
					if (memo[q] == j)		//이미 전에 j값과 같은 값을 인식했을 경우
					{
						k = j;
						break;
					}
				}
				if (k == j) continue;		//해당 j 제외
				if (com[i] == result[j])	//같은 문자일 경우
				{
					memo[i] = j;			//현재 위치의 j값 저장(중복 방지)
					cnt++;					//같은 값이 몇개인지 확인
					break;
				}
			}
		}
		if (cnt == com.length()) cout << "Yes" << endl;	//같은 값이 문자열 길이와 동일하다면
		else cout << "No" << endl;
	}
}