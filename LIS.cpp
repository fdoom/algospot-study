#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector <int> a)
{
	int ret = 0;
	vector <int> b;		//최대 길이 저장
	for (int i = 0; i < a.size(); i++)		//기준
	{
		int longest = 0;
		for (int j = 0; j < i; j++)			//이전의 값들 비교
			if (a[j] < a[i] && longest < b[j])
				longest = b[j];

		b.push_back(longest + 1);	//자기 자신 포함
		ret = max(ret, b[i]);
	}
	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		int N;
		cin >> N;
		vector <int> arr;

		int temp;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		cout << solution(arr) << endl;
	}
}