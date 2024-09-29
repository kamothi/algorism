#include<iostream>

using namespace std;

// 시뮬레이션
// 남학생(1)은 배수의 숫자를 체인지
// 여학생(2)은 수 중심으로 대칭인 지점 모두 스위치
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[100];

    for(int i=1;i<=n;i++) cin >> arr[i];

    int s;
    cin >> s;

    while(s--){
        int sex, num;
        cin >> sex >> num;

        if(sex == 1){
            for(int i=num;i<=n;i+=num){
                arr[i] = (arr[i]+1)%2;
            }
        }
        else {
            int i = 1;
            arr[num] = (arr[num]+1)%2;
            while (1) {
                if (num + i > n || num - i < 1) break;
                if (arr[num + i] != arr[num - i]) break;
                arr[num + i] = (arr[num - i] + 1) % 2;
                arr[num - i] = (arr[num - i] + 1) % 2;
                i++;
            }
        }

    }
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
        if(i%20==0) cout<<"\n";
    }
}
