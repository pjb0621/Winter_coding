/* https://www.acmicpc.net/problem/2503
정보문화진흥원 정보 영재 동아리에서 동아리 활동을 하던 영수와 민혁이는 쉬는 시간을 틈타 숫자야구 게임을 하기로 했다.

영수는 1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수를 마음속으로 생각한다. (예: 324)
민혁이는 1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수를 영수에게 묻는다. (예: 123)
민혁이가 말한 세 자리 수에 있는 숫자들 중 하나가 영수의 세 자리 수의 동일한 자리에 위치하면 스트라이크 한 번으로 센다. 
숫자가 영수의 세 자리 수에 있긴 하나 다른 자리에 위치하면 볼 한 번으로 센다.
예) 영수가 324를 갖고 있으면 

429는 1 스트라이크 1 볼이다.
241은 0 스트라이크 2 볼이다.
924는 2 스트라이크 0 볼이다.
영수는 민혁이가 말한 수가 몇 스트라이크 몇 볼인지를 답해준다.
민혁이가 영수의 세 자리 수를 정확하게 맞추어 3 스트라이크가 되면 게임이 끝난다. 아니라면 민혁이는 새로운 수를 생각해 다시 영수에게 묻는다.
현재 민혁이와 영수는 게임을 하고 있는 도중에 있다. 민혁이가 영수에게 어떤 수들을 물어보았는지, 그리고 각각의 물음에 영수가 어떤 대답을
했는지가 입력으로 주어진다. 이 입력을 바탕으로 여러분은 영수가 생각하고 있을 가능성이 있는 수가 총 몇 개인지를 알아맞혀야 한다.

아래와 같은 경우를 생각해보자.  

민혁: 123
영수: 1 스트라이크 1 볼.
민혁: 356
영수: 1 스트라이크 0 볼.
민혁: 327
영수: 2 스트라이크 0 볼.
민혁: 489
영수: 0 스트라이크 1 볼.
이때 가능한 답은 324와 328, 이렇게 두 가지이다.

영수는 동아리의 규율을 잘 따르는 착한 아이라 민혁이의 물음에 곧이곧대로 정직하게 답한다. 그러므로 영수의 답들에는 모순이 없다.

민혁이의 물음들과 각각의 물음에 대한 영수의 답이 입력으로 주어질 때 영수가 생각하고 있을 가능성이 있는 답의 총 개수를 출력하는 
프로그램을 작성하시오.

입력
첫째 줄에는 민혁이가 영수에게 몇 번이나 질문을 했는지를 나타내는 1 이상 100 이하의 자연수 N이 주어진다. 
이어지는 N개의 줄에는 각 줄마다 민혁이가 질문한 세 자리 수와 영수가 답한 스트라이크 개수를 나타내는 정수와 볼의 개수를 나타내는 정수, 
이렇게 총 세 개의 정수가 빈칸을 사이에 두고 주어진다.

출력
첫 줄에 영수가 생각하고 있을 가능성이 있는 답의 총 개수를 출력한다.*/
#include <iostream>
#include <vector>

using namespace std;

bool isCandidate(int N,int candidate,vector<int> question, int *strike, int *ball) {
    bool result = true;
    int tmp[3];
    int eachnum[3];
    int *resultstrike=new int[N];
    int *resultball=new int[N];
    for(int i = 0; i<N; i++) {
        resultball[i] = 0;
        resultstrike[i] = 0;
    }
    eachnum[0] = int(candidate / 100);
    eachnum[1] = int((candidate / 10) % 10);
    eachnum[2] = int(candidate%10);
    for(int i = 0; i<N; i++) {
        tmp[0] = int(question[i] / 100);
        tmp[1] = int((question[i] / 10) % 10);
        tmp[2] = int(question[i]%10);
        for (int j = 0; j < 3; j++)
        {
            for(int k = 0; k<3; k++){
                if(tmp[j] == eachnum[k]) {
                    if(j==k) resultstrike[i]++;
                    else resultball[i]++;
                }
            }
            
        }
        
    }
    for (int j = 0; j < N; j++)
    {
        if(resultstrike[j] != strike[j] || resultball[j]!=ball[j]) return false;
    }
    return true;
    
}

int main(void){
    int N,tmp,i;
    int count = 0;
    vector<int> question;
    cin >> N;
    int *strike  = new int[N];
    int *ball  = new int[N];
    for (i = 0; i < N; i++)
    {
        cin >> tmp >> strike[i] >> ball[i];
        question.push_back(tmp);
    }
    for(i = 123; i<=999; i++) {
        if( int(i/10)%10 == 0) {
            
            continue;
        }
        if(i%10 == 0) {
            
            continue;
        }
        if(i%10 == int(i/10)%10 || i%10 == int(i/100) || i/100 == int(i/10)%10 ) {
            
            continue;
        }
        if( isCandidate(N, i, question, strike, ball) ) {
           // cout << i << endl;
            count++;
        }
    }

    cout<<count;

}