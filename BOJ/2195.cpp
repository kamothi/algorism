#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s,p;
    int result = 0;
    cin >> s;
    cin >> p;

    for(int i = 0; i < p.size();){
        int temp = 0;
        for(int j = 0; j < s.size(); j++){
            int tmp = 0;
            while(s[j+tmp] == p[i+tmp])
                tmp++;
            temp = max(temp, tmp);
        }
        i += temp;
        result++;
    }
    cout << result;
}
