#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    deque<int> dq;
    int N, M, sum = 0;
    cin >> N >> M;

    vector<int> vec(M,0);
    for(int i = 0 ; i < M; i++){
        cin >> vec[i];
    }

    for(int i = 0 ; i < N; i++){
        dq.push_back(i+1);
    }

    for(int i = 0; i < M; i++){
        auto it = find(dq.begin(), dq.end(), vec[i]); // 찾고자하는 원소의 인덱스를 구하자.
        int index = it - dq.begin();
        int min_num = index <= dq.size()-index ? index : dq.size()-index;
        sum += min_num;
        if(min_num == 0){
            dq.pop_front();
        }
        else if(index <= dq.size()- index ){ // 2번 연산
            for(int j = 0; j < min_num; j++){
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
            dq.pop_front();
        }
        else{
            for(int j = 0; j< min_num; j++){
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
            dq.pop_front();
        }

       /*
        cout << " ----- " << endl;
        cout << "index : " << index << endl;
        cout << "min_num : " << min_num << endl;
        cout << "원소 개수 : " << dq.size() << endl;
        cout << " ----- " << endl;

        for(auto it = dq.begin(); it != dq.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        */
        
    }

    cout << sum << endl;
    



}