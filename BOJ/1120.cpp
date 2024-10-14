#include<iostream>
#include<algorithm>

using namespace std;


// A의 길이는 B의 길이 보다 작거나 같다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    int dist = 1e9;
    cin >> a >> b;

    for(int i = 0; i <= b.size()-a.size(); i++){
        int tmp = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] != b[j+i]) tmp++;
        }
        dist = min(dist,tmp);
    }

    cout << dist;

}
