#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long sum = 0;
    long long tmp = 0;
    int cnt = 1;
    cin >> n;
    vector<int> v(n);
    vector<int> Cnt(200000);
    for(int i=0;i<200000;i++) Cnt[i] = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        Cnt[v[i]]++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(Cnt[v[i]]){
            tmp = v[i];
            Cnt[v[i]]--;
            cnt = 1;
            for(int j=v[i]+1;;j++){
                if(Cnt[j]){
                    tmp = j;
                    cnt++;
                    Cnt[j]--;
                }
                else{
                    sum += tmp*cnt;
                    break;
                }
            }
        }
    }

    cout << sum;
}
