#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n){
        int ret = 0;
        vector<int> lis;
        for(int i=0;i<n;i++) cin >> arr[i];
        lis.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i] > lis.back()){
                lis.push_back(arr[i]);
                ret = lis.size()-1;
            }
            else{
                auto pos = lower_bound(lis.begin(),lis.begin()+ret,arr[i])-lis.begin();
                lis[pos] = arr[i];
            }
        }
        cout << ret+1 << "\n";
    }
}
