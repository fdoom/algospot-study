#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool flag;
void solve(vector <int> arr, int n, int sum, int cnt)
{
	if (n == sum)	//덧셈 결과 n과 같다면 이상한 숫자 확인
	{
		flag = true;
		return;
	}

	for (int i = cnt; i >= 0; i--)
	{
		if (flag) return;
		if (sum + arr[i] > n) continue;
		solve(arr, n, sum + arr[i], i - 1);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;

	while (c--)
	{
		int n, sum = 1;
		vector <int> arr;
		cin >> n;
		arr.push_back(1);
		flag = false;
		for (int i = 2; i * i <= n; i++)		//n의 약수 저장
		{
			if (n % i == 0) {
				arr.push_back(i);
				arr.push_back(n / i);
				sum += i + n / i;
			}
		}
		if (sum <= n) {		//약수의 합이 n보다 작거나 같다면 n은 이상한 숫자가 아니다.
			cout << "not weird" << '\n';
			continue;
		}
		sort(arr.begin(), arr.end());		//약수 저장한 벡터 정렬
		solve(arr, n, 0, arr.size() - 1);	//백트래킹으로 덧셈 진행

		if (flag) cout << "not ";
		cout << "weird" << '\n';
	}
}