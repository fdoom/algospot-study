#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int w, temp, sum = 0;
		cin >> w;

		for (int i = 0; i < 9; i++)
		{
			cin >> temp;
			sum += temp;
		}
		if (w >= sum) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}