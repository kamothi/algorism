#include<iostream>
#include<vector>

using namespace std;

int n,q;
vector<int> s(1000001);
vector<int> e(1000001);
int ans[1000001];

// 시각은 0 ~ 1,000,000
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        s[a]++;
        e[b]++;
    }

    int tmp = 0;
    for(int i=0;i<=1000000;i++){
        tmp += s[i];
        ans[i] = tmp;
        tmp -= e[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        cout << ans[a] << "\n";
    }
}
