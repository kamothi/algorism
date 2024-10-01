#include<iostream>

using namespace std;

// x일 동안 가장 많이 들어온 방문자 수와 그 기간
// int 범위안에 들어옴
int sum[250001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    int result = 0;
    int result2 = 0;
    int left = 1, right =1;
    cin >> n >> x;
    int arr[250001];


    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sum[i] += sum[i-1] + arr[i];
    }

    while(right <= n){
        if(right - left + 1 < x) {
            right++;
            continue;
        }

        if(sum[right] - sum[left-1] > result){
            result = sum[right] - sum[left-1];
            result2 = 1;
        }
        else if(sum[right] - sum[left-1] == result) result2++;

        left++,right++;

    }


    if(result == 0) {
        cout << "SAD";
        return 0;
    }


    cout << result << "\n" << result2;
}
