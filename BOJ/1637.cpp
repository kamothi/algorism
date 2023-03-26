#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

struct abc{
    ll A;
    ll B;
    ll C;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll num=0;
    cin >> n;
    vector<abc> v(n);
    ll left=1, right=2200000000, mid;

    for(int i=0;i<n;i++){
        cin >> v[i].A >> v[i].C >> v[i].B;
    }

    while(left <= right){
        mid = (left+right)/2;
        ll sum=0;
        for(int i=0;i<n;i++){
            ll temp;
            if(v[i].C >= mid) temp = (mid - v[i].A);
            else temp = (v[i].C - v[i].A);
            if(temp < 0) continue;
            sum += temp/v[i].B+1;
        }
        if(sum%2 == 0) left = mid + 1;
        else {
            num = mid;
            right = mid-1;
        }
    }

    if(num == 0){
        cout << "NOTHING";
        return 0;
    }
    cout << num << " ";
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        ll temp;
        if(v[i].C >= num) temp = (num - v[i].A)/v[i].B;
        else temp = (v[i].C - v[i].A)/v[i].B;
        if(temp < 0) continue;
        sum1 += temp+1;
    }
    for(int i=0;i<n;i++){
        ll temp;
        if(v[i].C >= num-1) temp = (num-1 - v[i].A)/v[i].B;
        else temp = (v[i].C - v[i].A)/v[i].B;
        if(temp < 0) continue;
        sum2 += temp+1;
    }
    cout << sum1-sum2;
}
