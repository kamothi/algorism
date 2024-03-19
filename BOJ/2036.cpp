#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    ll result = 0;
    vector<ll> plus;
    vector<ll> minus;
    vector<ll> zero;
    ll cntOne = 0;

    for(int i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        if(tmp > 1) plus.push_back(tmp);
        else if(tmp == 1) cntOne++;
        else if(tmp == 0) zero.push_back(tmp);
        else minus.push_back(tmp);
    }

    sort(plus.begin(),plus.end(),greater<>());
    sort(minus.begin(),minus.end(),less<>());

    ll tmpM = 0;
    ll tmpP = 0;
    for(int i=0;i<plus.size();i+=2){
        if(i == plus.size()-1){
            tmpP += plus[i];
            break;
        }
        result += plus[i]*plus[i+1];
    }


    for(int i=0;i<minus.size();i+=2){
        if(i == minus.size()-1){
            tmpM = minus[i];
            break;
        }
        result += minus[i] * minus[i+1];
    }


    if(zero.size() != 0){
        tmpM = 0;
    }
    result += tmpM + tmpP;
    result += cntOne;

    cout << result;
}
