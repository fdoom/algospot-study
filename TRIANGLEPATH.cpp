#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int solution(vector <vector <int>> t, vector <vector <int>>& c, int x, int y)
{
	if (y == N - 1) return t[y][x];
	if (c[y][x] != 0) return c[y][x];
	int result = t[y][x] + max(solution(t, c, x, y + 1), solution(t, c, x + 1, y + 1));
	c[y][x] = result;
	return result;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> N;

		vector <vector <int>> tri;
		vector <vector <int>> check(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++)
		{
			vector <int> temp;
			for (int j = 0; j <= i; j++)
			{
				int input;
				cin >> input;
				temp.push_back(input);
			}
			tri.push_back(temp);
		}

		cout << solution(tri, check, 0, 0) << endl;
	}
}