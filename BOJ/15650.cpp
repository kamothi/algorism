#include<iostream>
#include<algorithm>


using namespace std;

bool visited[9];
int arr[9];
int n, m;

void solve(int idx, int cnt){
    if(cnt == m){
        for(int i=0;i<cnt;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            solve(i+1,cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    solve(1,0);
}

