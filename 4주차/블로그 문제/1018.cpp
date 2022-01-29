#include <iostream>
#include <vector>
using namespace std;

int find_min(vector<vector<char>> v, int I, int J){
    int cnt_white=0, cnt_black=0, cnt;
    
    for(int i=I; i<I+8; i++){
        for(int j=J; j<J+8; j++){
            if(i%2==j%2){
                if(v[i][j]=='W') ++cnt_black;
                else ++cnt_white;
            }
            else{
                if(v[i][j]=='B') ++cnt_black;
                else ++cnt_white;
            }
        }
    }
    if(cnt_white<cnt_black) cnt = cnt_white;
    else cnt = cnt_black;
    return cnt;
}
    
int main(){
    int M, N, min, n;
    char s;
    cin>>M>>N;
    min = M*N;
    vector<vector<char>> v(M);

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>s;
            v[i].push_back(s);
        }
    }

    for(int i=0; i<M-7; i++){
        for(int j=0; j<N-7; j++){
            n = find_min(v, i, j);
            if(n<min) min=n;
        }
    }

    cout<<min;
}