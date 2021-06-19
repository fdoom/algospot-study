#include <iostream>
using namespace std;

//XOR 연산
bool checking(int a, int b, int c, int d)
{
	return a ^ b ^ c ^ d;
}

//XOR 연산 결과에 따른 오류 위치 값 확인
void check(string& x)
{
	bool a = checking(x[0] - '0', x[2] - '0', x[4] - '0', x[6] - '0');
	bool b = checking(x[1] - '0', x[2] - '0', x[5] - '0', x[6] - '0');
	bool c = checking(x[3] - '0', x[4] - '0', x[5] - '0', x[6] - '0');

	int index;
	index = a * 1 + b * 2 + c * 4 - 1;		//오류 위치값 2진수에서 십진수로

	//오류가 있다면 실행
	if (index >= 0) {
		//오류 위치값 반대로 저장
		if (x[index] - '0') x[index] = 0 + '0';
		else x[index] = 1 + '0';
	}
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		string arr;
		cin >> arr;
		check(arr);

		cout << arr[2] << arr[4] << arr[5] << arr[6] << endl;
	}
}