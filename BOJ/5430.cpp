#include<iostream>
#include<deque>
#include<string>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        // 수행할 함수
        string f;
        int n;
        deque<int> d;
        // true -> 정방향 , false -> 역방향
        bool flag = true;
        bool error = false;
        
        cin >> f;
        cin >> n;

        string tmp;
        cin >> tmp;

        for(int j = 1; j < tmp.size(); j++){
            string num = "";
            while(tmp[j]!=',' && tmp[j]!=']') num += tmp[j++];
            if(num!="") d.push_back(stoi(num));
        }

        for(int i=0;i<f.size();i++){
            if(f[i] == 'R') {
                flag = !flag;
                continue;
            }
            else{
                if(d.empty()) {
                    error = true;
                    break;
                }
                if(flag) d.pop_front();
                else d.pop_back();
            }
        }

        if(error){
            cout << "error" << "\n";
            continue;
        }
        cout << '[';
        int SIZE = d.size();
        for(int i=0;i<SIZE;i++){
            if(i!=0) cout << ',';
            if(flag) {
                cout << d.front();
                d.pop_front();
            }
            else{
                cout << d.back();
                d.pop_back();
            }
        }
        cout << ']';
        cout << "\n";
    }

}
