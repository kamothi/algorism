#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> sum(n+2);
    sum[0] = 0, sum[1] = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum[i+2] = 0;
    }
    sum[2] = v[0];
    sum[3] = v[1];
    int result = 0;
    for(int i=4;i<n+2;i++) {
        if(i%2 == 0) sum[i] += sum[i-2] + v[i-2];
        else{
            sum[i] += sum[i-2] + v[i-2];
        }
    }
    //밑장 빼기 전
    result = sum[n];
    for(int i=2;i<n+1;i++){
        int tmp = 0;
        if(i%2 == 0){
            tmp += sum[i-2] + sum[n+1] - sum[i - 1];
        }
        else{
            tmp += sum[i-1] + sum[n-1] - sum[i-2];
        }
        result = max(result,tmp);
    }

    cout  << result;


}
