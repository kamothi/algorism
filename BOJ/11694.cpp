#include<iostream>
#include<vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int k;
    cin >> k;
    int cnt = 0;
    vector<int> v(k);
    
    for(int i=0;i<k;i++) {
        cin >> v[i];
        if(v[i] == 1) cnt++;
    }

    if (cnt == k) {
        cout << (cnt % 2 == 0 ? "koosaga" : "cubelover");
    } else {
        if (cnt > 0 && cnt % 2 == 0) {
            for (int i = 0; i < k; i++) {
                if (v[i] != 1) {
                    v[i] = 1;
                    break;
                }
            }
        }

        int x = 0;
        for (int i = 0; i < k; i++) {
            x ^= v[i];
        }
        cout << (x != 0 ? "koosaga" : "cubelover") << '\n';
    }
}

