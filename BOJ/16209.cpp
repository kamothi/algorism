#include <iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;

    deque<int> d1;
    deque<int> d2;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp > 0) v1.push_back(tmp);
        else v2.push_back(tmp);
    }

    sort(v1.begin(),v1.end(),greater<>());
    sort(v2.begin(),v2.end(),less<>());

    for(int i=0;i<v1.size();i++){
        if(i%2 == 0) d1.push_front(v1[i]);
        else d1.push_back(v1[i]);
    }
    for(int i=0;i<v2.size();i++){
        if(i%2 == 0) d2.push_front(v2[i]);
        else d2.push_back(v2[i]);
    }

    if(!d1.empty() && d1.front() < d1.back()) reverse(d1.begin(),d1.end());
    if(!d2.empty() && d2.front() < d2.back()) reverse(d2.begin(),d2.end());
    for(int i=0;i<d1.size();i++) cout << d1[i] << " ";
    for(int i=0;i<d2.size();i++) cout << d2[i] << " ";





}
