#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    long long sum[300000];
    long long input[300000];
    for(int i=0;i<m;i++){
        cin >> input[i];
        if(i == 0){
            sum[i] = input[i];
            continue;
        }
        sum[i] = input[i] + sum[i-1];
    }
    while(n--){
        long long num;
        long long result;
        cin >> num;
        if(num > sum[m-1]){
            cout << "Go away!" << "\n";
            continue;
        }
        int left = 0, right = m-1;
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(sum[mid] >= num){
                right = mid - 1;
                result = mid;
            }
            else{
                left = mid + 1;
            }
        }
        cout << result + 1 << "\n";
    }
}
