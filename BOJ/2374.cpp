#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int Max = -1;
    long long int result = 0;
    stack<int> s;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Max = max(tmp,Max);
        if(s.empty()) s.push(tmp);
        else{
            if(s.top() > tmp){
                s.pop();
                s.push(tmp);
            }
            else if(s.top()<tmp){
                result += tmp - s.top();
                s.pop();
                s.push(tmp);
            }
        }
    }
    result += Max - s.top();
    cout << result;

}
