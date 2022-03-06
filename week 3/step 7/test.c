// 문자열에서 소문자의 개수를 출력하는 함수 
/*
#include <stdio.h>

#define MAX_LENGTH 64 // 최대 64까지만 입력받음.

int main()
{

    char str[MAX_LENGTH];
    int count = 0, i;
    printf("문자열을 입력하시오 : ");
    //공백을 포함해서 문자열 모두 입력 받기
    // Scanf_s 함수가 공백문자를 입력 구분자로 사용하지 못하게
    // '%[^\n]s 형식 지정자 사용 
    scanf_s("%[^\n]s", str, MAX_LENGTH - 1);

    // 문자열의 끝에 있는 NULL 문자가 나올때까지 반복하기
    for (i = 0; str[i] != 0; i++){
        // 소문자인 경우에 count 값을 1 증가시킨다.
        if (str[i] >= 'a' && str[i] <= 'z') count ++;
    }
    return 0; 
}
*/

/*
// 문자열에 포함된 소문자의 개수를 문자별로 계산

#include <stdio.h>
#define MAX_LENGTH 64  // 최대 64자까지 입력받음.
#define ALPHA_COUNT 26 // 알파벳의 개수는 26개 이다.

int main()
{
    char str[MAX_LENGTH];
    int counts[ALPHA_COUNT] = {0, }, i;

    printf("문자열을 입력하시오 : ");
    //공백을 포함해서 문자열 모두 입력 받기
    scanf_s("%[^\n]s", str ,MAX_LENGTH-1);

    // 문자열의 끝에 있는 NULL 문자가 나올때까지 반복하기.
    for(i=0; str[i] !=0; i++) {
        // str[i]에 저장된 문자가 소문자인지 체크한다.
        if (str[i] >= 'a' && str[i] <= 'z'){

            // 'a' 이면 'a' - 'a' = 0 인덱스에 값을 1 증가시킴.
            // 'b' 이면 'b' - 'a' = 1 인덱스에 값을 1 증가시킴.
            counts[str[i] = 'a']++;            
        }
    }

    //문자열에 포함된 문자의 개수를 출력한다.
    for(i=0; i < ALPHA_COUNT; i++){

        //한번이라도 나타난 문자만 출력함
        if(counts[i] > 0){
            //어떤 문자가 몇번 등장했는지 출력한다.
            printf("'%c':%d번, ", 'a'+i, counts[i]);
        }
    }
    printf("\n");

    

    return 0;

}
*/