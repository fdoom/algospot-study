#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for(int j = 0; j < t; j++)
	{
		int n;
		string arr;
		cin >> n >> arr;
		cout << j + 1 << " ";
		for (int i = 0; i < arr.length(); i++)
		{
			if (n == i + 1) continue;
			cout << arr[i];
		}
		cout << endl;
	}
}