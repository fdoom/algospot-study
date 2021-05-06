#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int arr[4][2];		//좌표 저장 [i][0] = x좌표, [i][1] = y좌표

		for (int i = 0; i < 3; i++)
			cin >> arr[i][0] >> arr[i][1];

		for (int i = 0; i < 3; i++)
		{
			bool flag1 = true;		//x좌표 확인
			bool flag2 = true;		//y좌표 확인
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;	//좌표가 동일할 경우 제외
				if (arr[i][0] == arr[j][0]) flag1 = false;
				if (arr[i][1] == arr[j][1]) flag2 = false;
			}
			if (flag1) arr[3][0] = arr[i][0];
			if (flag2) arr[3][1] = arr[i][1];
		}
		cout << arr[3][0] << " " << arr[3][1] << endl;	//마지막 x좌표와 y좌표 출력
	}
}