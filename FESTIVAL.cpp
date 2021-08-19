#include <iostream>

using namespace std;

double min_cost = 0;
int N, L;               //N: 공연장을 빌릴 수 있는 날, L: 섭외한 공연팀의 수
int * arr;              //날마다 생기는 비용(동적할당)

//문제 해결을 위한 재귀 함수
void solution(int cur, int cnt)     //cur: 현재 배열의 위치, cnt: 추가적으로 더하는 수치
{
    double temp = 0;
    for(int i = cur; i < L + cnt; i++)
        temp += arr[i];
    
    temp /= (L + cnt) - cur;        //날마다 발생하는 평균 계산
    
    if(min_cost > temp)
        min_cost = temp;
    
    if(L + cnt < N)         //더할 수 있는 범위가 남아있다면
        solution(cur, cnt + 1);
    else if(cur < N - L)    //추가적으로 탐색이 가능하다면
        solution(cur + 1, cur + 1);
}

int main(void)
{
    cout.setf(ios::fixed);  //소수점 자리 고정
    cout.precision(11);     //소수점 이하의 갯수를 11자리로 설정
    
    int C;      //테스트 케이스 횟수
    cin >> C;
    
    while(C--)
    {
        cin >> N >> L;
        arr = new int[N];
        for(int i = 0; i < N; i++)      //날마다 비용 입력
        {
            cin >> arr[i];
            min_cost += arr[i];         //최대한 큰 값으로 만들기 위해
        }
        solution(0, 0);
        
        cout << min_cost << endl;
        delete [] arr;
    }
    return 0;
}
