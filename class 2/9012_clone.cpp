#include <cstdio>

int main()
{
    int t, top;
    char input[51];

    
    
    
    scanf("%d", &t);

    while(t--) // 테스트케이스 횟수만큼 input에 문자열 입력받음
    {
        top = 0; // 어떤 변수인지 확인해보자
        scanf("%s", input);

        for(int i=0; input[i] != '\0'; i++)
            if(input[i] == '(')
                top++;
            else   // ')'가 있으면
                if(top <= 0)  // 이미 기존에 top이 0보다 작으면, VPS가 아니므로 TOP 감소후 BREAK
                {
                    top--;
                    break;
                }
                else  // top > 0 이면 '('와 맞는 쌍을 찾은것이므로 감소만 하고 다음 for loop로 넘어감.
                    top--;
        printf("%s\n", top ? "NO" : "YES"); // top이 0이면 false, 1이면 true인데 
    }
    
}