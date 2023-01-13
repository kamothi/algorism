#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    queue<int> q;
    int Max=0, Number=100001;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a==1){
            cin >> b;
            q.push(b);
            if(q.size() > Max) {
                Max=q.size();
                Number = b;
            }
            else{
                if(q.size() == Max && b < Number) Number = b;
            }
        }
        else{
            q.pop();
        }
    }
    cout << Max << " " << Number;
}
