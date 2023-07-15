#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int result = 0;
    vector<int> cross(n);
    vector<int> left(n);
    vector<int> right(n);
    vector<long long> left_sum(n);
    vector<long long> right_sum(n);
    left[0] = 0,right[0] = 0, left_sum[0] = 0, right_sum[0] = 0;
    for(int i=0;i<n;i++) cin >> cross[i];
    for(int i=1;i<n;i++) {
        cin >> left[i];
        left_sum[i] += left[i] + left_sum[i-1];
    }
    for(int i=1;i<n;i++) cin >> right[i];
    result = 1;
    right_sum[0] = cross[0];
    for(int i=1;i<n;i++){
        if(right_sum[i-1] + right[i] > left_sum[i] + cross[i]){
            result = i+1;
            right_sum[i] = left_sum[i] + cross[i];
        }
        else{
            right_sum[i] = right_sum[i-1] + right[i];
        }
    }
    cout << result << " " << right_sum[n-1];
}
