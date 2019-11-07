#include <iostream>
using namespace std;
int main(){
    long long arr[91];
    arr[0] = 0;
    arr[1] = 1;
    long long end1 = 1;
    long long end0 = 0;
    long long temp;
    for(int i = 2; i <= 90; i++){
        temp = end0;
        end0 = end1 + end0;
        end1 = temp;
        arr[i] = end1 + end0;
    }
    int N;
    cin >> N;
    cout << arr[N];
}