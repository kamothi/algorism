#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> v;

void showPost(int s, int e){
    if(s >= e) return;
    int cnt = s+1;
    while(cnt < e){
        if(v[s] < v[cnt]) {
            break;
        }
        cnt++;
    }
    showPost(s+1,cnt);
    showPost(cnt, e);
    cout << v[s] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    while (cin >> tmp) {
        v.push_back(tmp);
    }
    showPost(0,v.size());
    return 0;
}
