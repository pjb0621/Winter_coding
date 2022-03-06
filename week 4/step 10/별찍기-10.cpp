/*
별 찍기 - 10 , 2447
https://www.acmicpc.net/problem/2447
*/
// reference idea : 이영은

#include <iostream>
using namespace std;

// star를 출력하는데, N/3으로 나눈 몫이 1 일떈 공백
// 처음 0 1 2 인덱스를 기준으로 하므로 i,j 값을 수정해서 재귀.
int star(int N, int i, int j){

    // base case
    
    if (N==1) {
        
        cout << "*";
        return 0;
    }

    if (i/(N/3) == 1 && j/(N/3) == 1){
        cout << " ";
        return 0;
    }
    
    else{
        if(i/(N/3) == 0 && j/(N/3) == 0) return star((N/3),i,j);
        if(i/(N/3) == 0 && j/(N/3) == 1) return star((N/3),i,j-(N/3));
        if(i/(N/3) == 0 && j/(N/3) == 2) return star((N/3),i,j-2*(N/3));
        if(i/(N/3) == 1 && j/(N/3) == 0) return star((N/3),i-(N/3),j);
        if(i/(N/3) == 1 && j/(N/3) == 1) return star((N/3),i-(N/3),j-(N/3));
        if(i/(N/3) == 1 && j/(N/3) == 2) return star((N/3),i-(N/3),j-2*(N/3));
        if(i/(N/3) == 2 && j/(N/3) == 0) return star((N/3),i-2*(N/3),j);
        if(i/(N/3) == 2 && j/(N/3) == 1) return star((N/3),i-2*(N/3),j-(N/3));
        if(i/(N/3) == 2 && j/(N/3) == 2) return star((N/3),i-2*(N/3),j-2*(N/3));
        
    }

    

    return 0;



}
    


int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j ++){
            star(n,i,j);
        }
        cout << '\n';
    }
   
    return 0;
}

