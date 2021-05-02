#include <iostream>
#include <cstring>

using namespace std;

int check[10];		//짝을 지었는지 확인
int f[10][10];		//배열을 이용하여 친구끼리 묶기
int num;		//학생 수

int solution(void)
{
	int first = -1;

	for (int i = 0; i < num; i++)				//가장 빠른 학생 찾기
	{
		if (!check[i])
		{
			first = i;
			break;
		}
	}

	if (first == -1) return 1;				//학생의 짝을 다 찾았으면 1로 반환

	int result = 0;

	for (int i = first + 1; i < num; i++)
	{
		if (!check[i] && f[first][i])
		{
			check[first] = check[i] = 1;		//짝이 정해짐
			result += solution();
			check[first] = check[i] = 0;		// 다른 경우의 수를 찾기 위해
		}
	}
	return result;
}

int main(void)
{
	int test_case;

	cin >> test_case;

	while (test_case--)
	{
		int pair;
		cin >> num >> pair;				//num: 학생 수, pair: 친구 쌍의 수
		
		memset(f, 0, sizeof(f));
		memset(check, 0, sizeof(check));

		while (pair--)
		{
			int x, y;
			
			cin >> x >> y;				//x: 친구1, y: 친구2
			f[x][y] = f[y][x] = 1;
		}
		cout << solution() << endl;
	}
	return 0;
}