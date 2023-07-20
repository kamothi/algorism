#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001][1001] ={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2,ans;
    cin >> s1 >> s2;
    pair<int,int> p;
    int cnt = 0;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
                cnt = max(cnt, arr[i][j]);
                p = {i,j};
            }
            else{
                arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
                cnt = max(cnt, arr[i][j]);
                p = {i,j};
            }
        }
    }
    cout << cnt << "\n";
    int a = p.first, b = p.second;
    while(a>0 && b>0) {
        if(arr[a][b] == arr[a-1][b]) a--;
        else if(arr[a][b] == arr[a][b-1]) b--;
        else ans += s1[--a], b--;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}
