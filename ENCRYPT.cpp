#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;

		for (int i = 0; i < a.length(); i += 2)		//짝수 부분 출력
			cout << a[i];
		for (int i = 1; i < a.length(); i += 2)		//홀수 부분 출력
			cout << a[i];
		cout << endl;
	}
}