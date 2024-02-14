#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
bool visited[9];
int arr[9];

void solve(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }


    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            solve(cnt+1);
            visited[i] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    solve(0);
 
}

