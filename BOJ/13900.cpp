#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long sum = 0;
    cin >> n;
    vector<long long> v;
    vector<long long> prefix(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        (i == 0) ? (prefix[i] += tmp) : (prefix[i] += tmp + prefix[i-1]);
        v.push_back(tmp);
    }

    for(int i=n-1;i>0;i--){
        sum += prefix[i-1] * v[i];
    }
    cout << sum;

}
