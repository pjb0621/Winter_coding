/*
최대공약수와 최소공배수 계산

최대공약수를 계산하려면 어케해야할까

24 18

18 6

6  1



24 15

15 9

9 6

6 3

3 1 


25 20

20 5

5 1
*/
#include <iostream>
using namespace std;


int gcd(int x, int y){
    
    int tmp;

    
    while(y != 1){
        tmp = x % y;
        if(tmp == 0){
            return y;
        }
        else{
            x = y;
            y = tmp;
        }
    }

    return y;

   
}

int lcm(int x, int y, int gcd){

    int lcm = (y/gcd) * (x/gcd) * gcd;
    return lcm;

}

int main(){
    int x, y;
    cin >> x >> y;

    cout << gcd(x,y) << endl;
    cout << lcm(x,y,gcd(x,y)) << endl;

    return 0;


}


