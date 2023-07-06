#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool num[500001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    vector<int> v;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        num[tmp1] = true;
        num[tmp2] = true;
    }
    int temp1,temp2;
    int cnt = 0;
    int chulYoung;
    cin >> temp1 >> temp2;
    chulYoung = abs(temp1%k - temp2%k);
    num[temp1] = true;
    num[temp2] = true;
    for(int i=1;i<=n*4;i++){
        if(num[i]) continue;
        else{
            v.push_back(i%k);
        }
    }
    sort(v.begin(),v.end());
    int left=0, right = v.size()/2;
    while(left < v.size()/2 && right < v.size()){
        if(v[right]-v[left] > chulYoung) {
            left++;
            cnt++;
            right++;
            if(cnt >= m-1) break;
        }
        else right++;
    }
   cout << cnt;
}

