#include <iostream>
#include <vector>

using namespace std;

int N;		//크기
bool flag;	//정답 확인
void solution(vector <vector <int>> g, vector <vector <int>> &c, int x, int y)
{
	if (c[y][x] == 1) return;	//이미 탐색한 구역이라면
	if (flag == true) return;	//정답을 이미 확인했다면
	if (x == N - 1 && y == N - 1) flag = true;
	if (x + g[y][x] < N) solution(g, c, x + g[y][x], y);	//오른쪽 탐색
	if (y + g[y][x] < N) solution(g, c, x, y + g[y][x]);	//아래쪽 탐색
	c[y][x] = 1;	//오른쪽과 아래쪽을 탐색이 끝났다면
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> N;
		vector <vector <int>> ground;
		vector <vector <int>> cache(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++)
		{
			vector <int> line;
			for (int j = 0; j < N; j++)
			{
				int temp;
				cin >> temp;
				line.push_back(temp);
			}
			ground.push_back(line);
		}
		flag = false;
		solution(ground, cache, 0, 0);
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}