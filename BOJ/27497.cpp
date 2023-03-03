#include<iostream>
#include<deque>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int S=0;
    char temp1,temp2;
    stack<int> s;
    deque<char> d;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> temp1;
        if(temp1 == '1' || temp1 == '2') cin >> temp2;
        if(temp1 == '1') {
            d.push_back(temp2);
            s.push(1);
            S++;
        }
        else if(temp1 == '2') {
            d.push_front(temp2);
            s.push(2);
            S++;
        }
        else {
            if(s.empty()) continue;
            if(s.top() == 1) {
                d.pop_back();
                s.pop();
                S--;
            }
            else if(s.top() == 2){
                d.pop_front();
                s.pop();
                S--;
            }
        }
    }
    if(S==0) {
        cout << 0;
        return 0;
    }
    for(int i=0;i<S;i++) {
        cout << d[i];
    }
}
