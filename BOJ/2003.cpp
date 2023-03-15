#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    int arr[10000];
    int sum=0,cnt=0;
    cin >> n >> s;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == s) {
            cnt++;
            sum=0;
            continue;
        }
        else if(sum > s) {
            sum = 0;
            continue;
        }
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            if(sum == s) {
                cnt++;
                sum=0;
                break;
            }
            else if(sum > s) {
                sum = 0;
                break;
            }
        }
        sum = 0;
    }
    cout << cnt;
}
