#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int num = 0;
    cin >> arr[0] >> arr[1]>> arr[2]>> arr[3]>> arr[4];
    
    for(int i = 0; i<5; i++){
        num += arr[i] * arr[i];
    }

    cout << num % 10 << endl;
}