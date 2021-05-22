#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		string arr;
		cin >> arr;

		for (int i = 0; i < arr.length(); i++)
		{
			if (arr[i] == '%' && arr[i + 1] == '2')
			{
				switch (arr[i + 2])
				{
				case '0':
					cout << " ";
					break;
				case '1':
					cout << "!";
					break;
				case '4':
					cout << "$";
					break;
				case '5':
					cout << "%";
					break;
				case '8':
					cout << "(";
					break;
				case '9':
					cout << ")";
					break;
				case 'a':
					cout << "*";
					break;
				default:
					break;
				}
				i += 2;
			}
			else cout << arr[i];
		}
		cout << endl;
	}
}