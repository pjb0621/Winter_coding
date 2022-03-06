/*
2503 숫자야구
https://www.acmicpc.net/problem/2503

레퍼런스 : https://glowdev.tistory.com/21

111 ~ 999 사이의 모든 숫자들을 테스트한다.
테스트 케이스와 전부 비교해서, strike ball 출력이 같은지 비교한다
그리고 그경우 possible_num을 증가시킨다.

유의사항
- 111~999 에서 중복된 숫자는 continue



*/

#include <iostream>
#include <vector>
using namespace std;


int main(){

    int TestCase;
    int possible_num = 0;
    int tmp_num, tmp_s, tmp_b;
    int strike_cnt = 0, ball_cnt = 0;
    bool status = true;
    cin >> TestCase;

    // 테스트 케이스를 모두 담을 board 생성
    vector <vector <int>> board(TestCase, vector<int>(3,0));
    
    for(int i = 0; i < TestCase; i++){
        // vector에 값을 넣음
        // board[i][0] : 숫자
        // board[i][1] : 스트라이크
        // board[i][2] : 볼

        cin >> tmp_num >> tmp_s >> tmp_b;
        board[i][0] = tmp_num;
        board[i][1] = tmp_s;
        board[i][2] = tmp_b;
    }

    //111 ~ 999까지 테스트케이스와 비교
    for(int i = 111; i <= 999; i++){
        // 초기화
        status = true;
        strike_cnt = 0;
        ball_cnt = 0;

        int third = i % 10;
        int second = (i/10) % 10;
        int first = (i/100) % 10;

        

        
        // 중복되는 숫자가 없는 경우만 실행. 
        if(first == second || second == third || third == first) continue;
        if(first == 0 || second == 0 || third == 0) continue;
        
    
        
        // 테스트 케이스와 비교하여 스트라이크, 볼이 전부 일치하면 최종적으로 p_num 증가
        // 스트라이크와 볼 개수가 틀리면 break; 
        for(int i = 0 ; i < TestCase; i++){
           
        

            int tmp_num_third = board[i][0] % 10;
            int tmp_num_second = (board[i][0]/10) % 10;
            int tmp_num_first = (board[i][0]/100) % 10;

            

            
            // strike
            if(first == tmp_num_first) strike_cnt++;
            if(second == tmp_num_second) strike_cnt++;
            if(third == tmp_num_third) strike_cnt++;

            // ball
            if(first == tmp_num_second) ball_cnt++;
            if(first == tmp_num_third) ball_cnt++;
            if(second == tmp_num_first) ball_cnt++;
            if(second == tmp_num_third) ball_cnt++;
            if(third == tmp_num_first) ball_cnt++;
            if(third == tmp_num_second) ball_cnt++;
            
            if(ball_cnt != board[i][2] || strike_cnt != board[i][1]){
                status = false;
            
            }

            ball_cnt = 0;
            strike_cnt = 0;
            

        }

        // 정상적으로 stk, ball cnt가 같으면 status == true
        // status에 따라 p_num 증가.

        if(status) possible_num++;
        
    }
    
    cout << possible_num << '\n';

    return 0;
    
}