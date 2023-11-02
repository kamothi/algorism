#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v(10000);
int board[10000][10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int sum=0;

    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.begin()+n);
    for(int i=0;i<n;i++){
        sum += v[i];
        if(sum < (i+1)*i/2){
            cout << -1;
            return 0;
        }
    }


    if(sum == n*(n-1)/2) cout << 1;
    else cout << -1;




}
