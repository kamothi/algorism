#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,cnt=0;
    int arr[101];
    vector<int> v1,v2;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        if(cnt > 100) {
            cout << -1;
            return 0;
        }
        if(i != arr[i]){
            for(int j=i+1;j<=n;j++){
                if(arr[j] == i){
                    v1.push_back(i);
                    v2.push_back(j);
                    reverse(arr+i,arr+j+1);
                    cnt++;
                    break;
                }
            }
        }
        else continue;
    }
    cout << cnt << "\n";
    for(int i=0;i<cnt;i++){
        cout << v1[i] << " " << v2[i] <<"\n";
    }
}
