#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N;
    scanf("%d",&N);
    int *arr = new int[N];
    int *cnt = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    int max = 1;
    for(int i = 0; i < N; i++){
        cnt[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && cnt[j] + 1 > cnt[i]){
                cnt[i] = cnt[j] + 1;
            }
        }
        if(max < cnt[i])
            max = cnt[i];
    }
    printf("%d",max);
}