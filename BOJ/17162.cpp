#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
int check[100] = {0,};
stack<int> dist[100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int n, m;
    int num1=0;
    stack<int> s;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int tmp;
        int num;
        cin >> tmp;
        if(tmp == 1){
            cin >> num;
            s.push(num);
            check[num%m]++;
            dist[num%m].push(num1);
            num1++;
        }
        else if(tmp == 2){
            if(num1 == 0) continue;
            num = s.top();
            s.pop();
            check[num%m]--;
            dist[num%m].pop();
            num1--;
        }
        else{
            bool c = true;
            for(int j=0;j<m;j++){
                if(!check[j]) {
                    c = false;
                    break;
                }
            }
            if(c){
                int t = 1000000000;
                for(int j=0;j<m;j++)  t = min(t,dist[j].top());
                cout << num1 - t << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
}
