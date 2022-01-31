#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    int dec = m;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                int tempdec = m - arr[i] - arr[j] - arr[k];
                if (tempdec < dec && tempdec >= 0){
                    dec = tempdec;
                    sum = m - dec;
                }
            }
        }
    }

    std::cout << sum << std::endl;

}