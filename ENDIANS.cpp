#include <iostream>

using namespace std;

class Mask {
	unsigned int arr[4];
public:
	Mask()	//Mask 연산을 위한 비트 생성
	{
		arr[3] = 255;
		for (int i = 2; i >= 0; i--)
			arr[i] = arr[i + 1] << 8;
	}
	unsigned int conversion(unsigned int temp)	//리틀엔디안과 빅엔디안 변환
	{
		unsigned int result[4];

		result[3] = temp & arr[3];
		result[3] = result[3] << 24;

		result[2] = temp & arr[2];
		result[2] = result[2] << 8;

		result[1] = temp & arr[1];
		result[1] = result[1] >> 8;

		result[0] = temp & arr[0];
		result[0] = result[0] >> 24;

		temp = 0;
		for (int i = 0; i < 4; i++)		//선택적 선택 연산 OR
			temp |= result[i];

		return temp;
	}
};

int main(void)
{
	int c;
	cin >> c;		//입력 횟수

	while (c--)		//입력 횟수만큼 반복
	{
		unsigned int n;
		cin >> n;

		Mask a;
		cout << a.conversion(n) << endl;
	}
}