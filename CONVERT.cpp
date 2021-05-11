#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for(int pk = 1; pk <= t; pk++)
	{
		double n;
		string unit;
		cin >> n >> unit;

		if (unit == "kg")
		{
			n *= 2.2046;
			unit = "lb";
		}
		else if (unit == "l")
		{
			n *= 0.2642;
			unit = "g";
		}
		else if (unit == "lb")
		{
			n *= 0.4536;
			unit = "kg";
		}
		else if (unit == "g")
		{
			n *= 3.7854;
			unit = "l";
		}
		cout << fixed;			//소수점이하 수 출력
		cout.precision(4);		//4자리까지
		cout << pk << " " << n << " " << unit << endl;
	}
}