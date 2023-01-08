/*
큐에서 규칙
1. 현재 Queue의 가장 맨 앞에 있는 문서의 중요도 확인.
2. 나머지 문서중 더 높은 중요도가 있다면 다시 큐 뒤로 재배치,
그렇지 않다면 인쇄

ㄴ현재 큐에 있는 문서의 수, 중요도가 주어졌을때
특정 문서가 몇번째로 인쇄되는지 알아내야함.

3
1 0 : 문서의 개수 N, 현재 큐에 몇번째에 놓여있는지 나타내는 정수(0~N의 범위), 이떄 맨 왼쪽은 0번째

5 : 두번쨰 줄에는 n개 문서의 중요도가 차례대로 주어짐. 중요도는 [1,9], 중요도 같은거 여러개있을수 있다.

4 2 : 현재 문서 개수는 4개이며, 내가 원하는 문서는 인덱스 2에 놓임
1 2 3 4 : 중요도가 1 2 3 4 //중요도가 3이므로 2번쨰로 출력될것. 

6 0 : 현재 문서개수 6개, FRONT에 있 음
1 1 9 1 1 1 : 중요도가 1이므로 뒤로 빠짐. 

내가 원하는 원소가 POP을 할때가지 계속 순서를 세야하나..?


----
계획
큐에서 내가 원하는 문서의 위치를 확인한다. 그리고 저장.
front에 있는 원소가 queue에서 최대값인지 확인.
아니면 pop -> push하고, cnt++
최대값


어려운 이유가 위치에따라서 빠지는 순서가 달라진다.
2 1 4 3 이라도 중요도

pop pop pop 이것도 괜찮은건 맞는데
,이렇게 하면 내가 처음에 본 원소가 어떤 원소인지 확인이 안된다.

1 1 9 1 1 1 만 봐도
0번째 인덱스를 지칭함.
얘가 근데 만약에 달라지면? 
인덱스를 바꿔야함 5로,
매번 pop이나 푸쉬 할때마다 인덱스도 새로 계산해야하고
cnt도 증가시켜야함.
음? 하면 되겠네.

1. 최댓값 확인
2. 현재 front에 있는 것이 중요도 최댓값인지 비교.
맞으면 : pop , cnt로 몇번쨰 출력인지 확인(cnt = 0 초기)
틀리면 : pop -> push하고 처음에 주어진 문서의 위치 M 값을 수정시키기.
if(M == 0) M = N-1;
else M--;

3. 종료 조건은 원래 우리가 M번쨰 위치한 원소가 빠져야하는것임.
즉, M 번째 원소가 FRONT에 왔을때, 이게 최댓값이면 종료시키자.
M != 0 || front != MAX
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n,m; // n은 큐의 크기, m은 원하는 문서의 인덱스를 뜻함.
        cin >> n >> m;
        queue <int> q;
        priority_queue<int> pq;

        for(int i = 0 ; i < n; i++){
            int temp;
            cin >> temp;
            q.push(temp);
            pq.push(temp);
        }

        int cnt = 0;
        int qmax = pq.top();
        while(m >= 0){
            qmax = pq.top();
            if(q.front() == qmax){ // front가 큐의 최댓값인 경우 원소 뺴고 횟수 증가
                q.pop();
                pq.pop();
                cnt++;
                m--; // 여기에서 종료조건에 걸리게 할것.
            }
            else{ // front가 큐의 최댓값이 아닌 경우
                int temp = q.front();
                q.pop();
                q.push(temp);
                if(m == 0) m = q.size()-1;
                else m--;
            }
        }

        cout << cnt << endl;




    }
}