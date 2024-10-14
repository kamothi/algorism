#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 테케, 최소 개수
int t,k;
string w;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        int result1=1e9,result2=-1;
        vector<vector<int>> v((int)'z'+1);
        cin >> w;
        cin >> k;

        for(int i=0;i<w.size();i++){
            v[w[i]].push_back(i);
        }

        for (auto indexes : v) {
            for (int start = 0, end = k - 1; end < indexes.size(); ++end, ++start) {
                int length = indexes[end] - indexes[start] + 1;
                result1 = min(result1, length);
                result2 = max(result2, length);
            }
        }

        if (result1 == 1e9) {
            cout << -1 << "\n";
        }
        else {
            cout << result1 << " " << result2 << "\n";
        }


    }
}
