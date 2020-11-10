#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

char board[5][5];					// 게임 보드판 알파벳 배열
char word[10];						// 키워드 입력 배열
int check[5][5][10];					// 글자별 확인여부 체크 [ x 좌표 ] [ y 좌표 ] [ 글자의 위치 ]
int word_len;						// 키워드의 길이
const int dx[8] = { -1,-1,-1, 0, 1, 1, 1, 0 };		// ↖ 방향부터 시계 방향으로 진행
const int dy[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };

int solution(int x, int y, int ptr)
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return 0;		// 범위 초과시 실패
	if (check[x][y][ptr]) return 0;					// 이미 확인한 것이면 실패
	check[x][y][ptr] = 1;						// 확인하지 않았으므로 1로 초기화

	if (board[x][y] != word[ptr]) return 0;				// 보드판의 글자와 키워드의 해당 글자가 일치하지않으면 실패
	if (ptr == word_len - 1) return 1;				// 바로 위에서 글자 검사에서 통과했기에 글자의 마지막 위치라면 성공

	for (int i = 0; i < 8; i++)					//인접한 8칸 검사
	{
		int result = solution(x + dx[i], y + dy[i], ptr + 1);	// ↖ 방향부터 시계 방향으로 진행
		if (result) return 1;					// 참이라면 성공
	}
	return 0;							// 거짓이라면 실패
}

int main(void)
{
	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		memset(board, 0, sizeof(board));				// board의 배열을 0으로 초기화

		for (int i = 0; i < 5; i++) cin >> board[i];

		int word_num;
		cin >> word_num;

		while (word_num--)
		{
			memset(check, 0, sizeof(check));			// check의 배열을 0으로 초기화
			cin >> word;
			word_len = strlen(word);
			int out = 0;						// 중첩 반복문 빠져나오는 키워드

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (solution(i, j, 0))
					{
						out = 1;
						break;
					}
				}
				if (out) break;
			}
			if (out) printf("%s YES\n", word);
			else printf("%s NO\n", word);
		}
	}
	return 0; 
}