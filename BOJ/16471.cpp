#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v1,v2;
    int n, check,cnt=0;
    cin >> n;
    check  = (n+1)/2;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int now = 0;
    for(int i=0;i<n;i++){
        while(1){
            if(now >= n) break;
            if(v1[i] < v2[now]) {
                cnt++;
                now++;
                break;
            }
            else now++;
        }
    }
    if(cnt >= check) cout << "YES";
    else cout << "NO";
}
