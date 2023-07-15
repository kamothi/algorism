#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    deque<int> zero;
    deque<int> one;
    deque<int> two;
    deque<int> result;
    if(n == 1){
        int tmp;
        cin >> tmp;
        if(tmp % 3 == 0) cout << -1;
        else cout << tmp;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] % 3 == 0) zero.push_back(v[i]);
        if(v[i] % 3 == 1) one.push_back(v[i]);
        if(v[i] % 3 == 2) two.push_back(v[i]);
    }
    if(zero.size() == 0 && one.size() >0 && two.size() > 0) {
        cout << -1;
        return 0;
    }

    if((int)(one.size()+two.size()) < (int)(zero.size() -1)) {
        cout << -1;
        return 0;
    }
    else{
        int num = zero.size();
        for(int i=0;i<num-1;i++){
            result.push_back(zero.front());
            zero.pop_front();
            if(!one.empty()) {
                result.push_back(one.front());
                one.pop_front();
            }
            else{
                result.push_back(two.front());
                two.pop_front();
            }
        }
        if(!zero.empty()) {
            result.push_back(zero.front());
            zero.pop_front();
        }
        while(!one.empty()){
            result.push_front(one.front());
            one.pop_front();
        }
        while(!two.empty()){
            result.push_back(two.front());
            two.pop_front();
        }
    }
    for(int i=0;i<result.size();i++) cout << result[i] << " ";


}
