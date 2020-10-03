#include <iostream>
using namespace std;
int main()
{
    int N, m, mod, result;
    cin >> N;
    m = N / 5; //m:5kg 봉지의 사용 최대 개수
    while (m >= 0)
    {
        mod = 0;
        result = 0;
        if (m > 0)
        {
            mod = N - 5 * m; //5kg 봉지 사용하고 남은 무게
            result = m;
        }
        else
            mod = N;
        result += mod / 3; //3kg 봉지 사용 개수 더하기
        mod = mod % 3;     //3kg 봉지 사용하고 남은 무게

        if (mod == 0)
        {
            cout << result;
            break;
        }
        m--; // 0으로 나누어 떨어지지 않으므로 5kg 봉지 개수 줄이고 다시 반복
    }
    if (mod != 0)
        cout << -1;
}