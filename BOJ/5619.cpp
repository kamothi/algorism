#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int checkCnt(int num){
    int cnt = 0;
    while(num != 0){
        num = num/10;
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> arr;
    vector<int> comp;
    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int Max;
    (n >= 4) ? (Max = 4) : (Max = n);
    for(int i=0;i<Max;i++){
        for(int j=i+1;j<Max;j++){
            int tmp1=0,tmp2=0;
            tmp1 += arr[i]*pow(10,checkCnt(arr[j])) + arr[j];
            tmp2 += arr[j]*pow(10,checkCnt(arr[i])) + arr[i];
            comp.push_back(tmp1);
            comp.push_back(tmp2);

        }
    }
    sort(comp.begin(),comp.end());
    cout << comp[2];
}
