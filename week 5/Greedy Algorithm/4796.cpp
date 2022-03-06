        /*
        4796 캠핑
        https://www.acmicpc.net/problem/4796
        */

        #include <iostream>
        #include <vector>
        using namespace std;

        int main(){

            // 연속하는 P일 중, l일 동안만 사용 가능
            // 준병이는  V일 짜리 휴가를 시작
            // 준병이는 최대 며칠동안 캠핑장을 사용 가능할까?
            int L , P , V;
            int cnt = 0 , i = 1;
            
            while(true){
                // 0 0 0 이 주어지면 종료한다. 
                cin >> L >> P >> V; 
                if(L == 0 && P == 0 && V == 0) break;

                

                    // 시간초과를 피하기 위해 cnt += (V/P) * L; 
                    if(V > P){
                        cnt += (V/P)*L;
                        V = V % P;
                        if(V < L) cnt += V;
                        else cnt += L;   
                    }

                

                        
                    
                
                cout << "Case " << i << ": " << cnt << endl;
                i++;
                cnt = 0;
            }

            return 0;






        }