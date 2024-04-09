#include<iostream>

using namespace std;

int node[500001];

void make_set(int n){
    for(int i = 0; i < n; i++) node[i] = i;
}

int Find(int i) {
    if(node[i] == i) return i;
    node[i] = Find(node[i]);
    return (node[i]);
}

// b가 오른쪽 값
void Union(int a, int b) {
    node[Find(a)] = Find(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    make_set(n+1);

    int day = 0;
    int result = 0;
    for(int i=0;i<m;i++){
        // 하루 추가
        day++;
        int a,b,cnt=0;
        cin >> a >> b;
        for(int j=a;j<=b-1;j++){
            if(Find(j) != j){
                j = Find(j)-1;
            }
            else{
                Union(j,j+1);
                cnt++;
            }
        }
        if(day<cnt){
            result += cnt-day;
            day=0;
        }
        else{
            day -= cnt;
        }
    }
    cout << result;
}
