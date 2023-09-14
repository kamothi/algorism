#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct s{
    int addh,addt,mint,addo,mino,t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t ;
    while(t--){
        queue<s> q;
        bool visited[61] ={false,};

        cin >> n;
        int h,m;
        h = n/60;
        m = n%60;
        q.push({0,0,0,0,0,0});
        while(!q.empty()){
            s temp = q.front();
            q.pop();
            if(temp.t >= 0 && temp.t <= 60 && !visited[temp.t]) {
                visited[temp.t] = true;
                if(temp.t == m){
                    cout << h+temp.addh << " " << temp.addt << " " << temp.mint << " " << temp.addo << " " << temp.mino << "\n";
                    break;
                }
                q.push({temp.addh,temp.addt,temp.mint,temp.addo,temp.mino+1,temp.t-1});
                q.push({temp.addh,temp.addt,temp.mint,temp.addo+1,temp.mino,temp.t+1});
                q.push({temp.addh,temp.addt,temp.mint+1,temp.addo,temp.mino,temp.t-10});
                q.push({temp.addh,temp.addt+1,temp.mint,temp.addo,temp.mino,temp.t+10});
                q.push({temp.addh+1,temp.addt,temp.mint,temp.addo,temp.mino,temp.t+60});
            }
        }
    }

}
