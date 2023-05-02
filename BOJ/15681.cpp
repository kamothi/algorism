#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int parent;
    vector<int> child;
    int value;
};

vector<int> v[100001];
vector<int> query;
Node node[100001];
int countSub[100001] ={0,};


void makeTree(int now,int parent){
    node[now].value = now;
    for(int next : v[now]){
        if(next != parent){
            node[now].child.push_back(next);
            node[next].parent = now;
            makeTree(next,now);
        }
    }
}

int findSubtree(int now,int parent){
    countSub[now] = 1;
    if(node[now].child.size() == 0) {
        return 1;
    }
    else{
        for(int next : v[now]){
            if(parent != next){
                countSub[now] += findSubtree(next,now);
            }
        }
    }
    return countSub[now];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,r,q;//n은 정점의 수, r루트번호, q 가 쿼리의 수
    cin >> n >> r >> q;
    for(int i=0;i<n-1;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    for(int i=0;i<q;i++){
        int tmp;
        cin >> tmp;
        query.push_back(tmp);
    }
    makeTree(r,-1);
    int result = findSubtree(r,-1);

    for(int next : query){
        cout << countSub[next] << "\n";
    }
}
