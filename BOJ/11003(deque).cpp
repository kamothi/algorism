#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<pair<int,int>> d;
    int n,l;
    cin >> n >> l;

    for(int i=0;i<n;i++){
        int MIN = i-l+1;
        int num;
        cin >> num;
        if(i==0) {
            d.push_front(make_pair(num,i));
            cout << d.front().first <<" ";
            continue;
        }
        if(d.front().second < MIN) {
            d.pop_front();
        }
        while(1){
            if(d.back().first >= num && d.size()) d.pop_back();
            else {
                d.push_back(make_pair(num,i));
                break;
            }
        }
//        for(int j=0;j<d.size();j++) cout << d[j].first << " ";
//        cout << "\n";
        cout << d.front().first <<" ";
    }

}
