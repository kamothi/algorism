#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// 3번 정렬해서 1,2번 기준 최대,
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    vector<int> sum1,sum2,sum3; // 1이 12, 2가 23, 3이 13
    int result = -1;
    cin >> n >> k;
    vector<int> v[n];

    for(int i=0;i<n;i++) {
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        sum1.push_back(tmp1+tmp2);
        sum2.push_back(tmp2+tmp3);
        sum3.push_back(tmp1+tmp3);
    }

    sort(sum1.begin(),sum1.end(),greater<>());
    sort(sum2.begin(),sum2.end(),greater<>());
    sort(sum3.begin(),sum3.end(),greater<>());
    int t1=0,t2=0,t3=0;
    for(int i=0;i<k;i++){
        t1 += sum1[i];
        t2 += sum2[i];
        t3 += sum3[i];
    }

    result = max({t1,t2,t3});
    cout << result;

}
