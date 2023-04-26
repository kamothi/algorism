#include<iostream>
#include<queue>

using namespace std;
long long a,b;

int translateNum(){
    queue<int> q;
    long long Size;
    int n=2;
    q.push(a*10+1);
    q.push(a*2);
    while(!q.empty()){
        Size = q.size();
        for(long long i=0;i<Size;i++){
            long long tmp = q.front();
            if(tmp == b) {
                return n;
            }
            else{
                if(tmp*10+1 <= b) q.push(tmp*10+1);
                if(tmp*2 <= b) q.push(tmp*2);
            }
            q.pop();
        }
        n++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << translateNum();
}
