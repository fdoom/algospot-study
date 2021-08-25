#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int C;
    cin >> C;

    while (C--)
    {
        int N;
        cin >> N;                       //펜스 갯수 입력

        vector<int> fence;
        for (int i = 0; i < N; i++)     //펜스 크기 입력
        {
            int temp;
            cin >> temp;
            fence.push_back(temp);
        }

        int result = 0;                 //결과값
        for (int i = 0; i < N; i++)     //모든 펜스 탐색
        {
            int right = 0, left = 0;            //right: 오른쪽에 위치한 펜스의 크기가 크거나 같다면 증가
                                                //left: 왼쪽에 위치한 펜스의 크기가 크거나 같다면 증가
            for (int j = i + 1; j < N; j++)     //오른쪽의 펜스 크기 탐색
            {
                if (fence[i] <= fence[j])
                    right++;
                else
                    break;
            }
            for (int j = i - 1; j >= 0; j--)    //왼쪽의 펜스 크기 탐색
            {
                if (fence[i] <= fence[j])
                    left++;
                else
                    break;
            }
            int tempResult = fence[i] * (left + right + 1); //현재 펜스 기준 결과값 저장
            if (tempResult > result)                        //크기가 크다면 결과값으로 저장
                result = tempResult;
        }
        cout << result << endl;
    }
    return 0;
}