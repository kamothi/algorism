#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int,int>> node[10001];
bool visited[10001];
int destA,destB;


bool dfs(int x, int weight){
    visited[x] = true;

    if(destB == x) return true;
    else{
        for(auto tmp : node[x]){
            if(!visited[tmp.first] && weight <= tmp.second){
                if(!dfs(tmp.first,weight)) continue;
                else return true;
            }
        }
    }

    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 섬의 이동은 다이렉트로 갈 수도 있고 아니면 다른 섬을 통해서 이동 가능
    // 제한 무게를 걸고 dfs로 탐색을 해서 가보자. 제한 무게의 경우 이분 탐색으로 결정.
    // 즉 원래는 완탐으로 해결될 것을 이분탐색으로 logN으로 처리

    // n개의 섬, m개의 다림 
    int n,m;
    int left=0,right=1000000000;
    int result = 0;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }

    // 공장이 있는 섬
    cin >> destA >> destB;

    while(left<=right){
        int mid = (left + right) / 2;
        if(dfs(destA,mid)){
            result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        memset(visited, false, sizeof(visited));
    }

    cout << result;

}
