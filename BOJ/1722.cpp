#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool visited[21];
int n,x;
long long k;
long long f[21];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    cin >> n >> x;
    f[0] = 1;
    for(int i=1;i<=n;i++) f[i] = f[i-1] * i;

    if(x==1){
        cin >> k;
        vector<int> tmp(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                if(visited[j]) continue;
                if(f[n-i-1] < k){
                    k -= f[n-i-1];
                }
                else{
                    tmp[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) cout <<tmp[i] << " ";
    }
    else{
        vector<int> tmp(n);
        for(int i=0;i<n;i++) cin >> tmp[i];

        long long result = 0;

        for(int i=0;i<n;i++){
            for(int j=1;j<tmp[i];j++){
                if(!visited[j]) result += f[n-i-1];
            }
            visited[tmp[i]] = true;
        }
        cout << result + 1;
    }
}

