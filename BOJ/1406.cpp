#include<iostream>
#include<list>

using namespace std;


// 모든 명령어가 수행하고 난 후의 문자열 출력
// 초기 위치는 가장 오른쪽
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    list<char> l;
    int n; // 명령어의 개수
    cin >> n;

    for(int i=0;i<s.size();i++){
        l.push_back(s[i]);
    }
    auto cur = l.end();

    while(n--){
        char c;
        cin >> c;
        if(c=='L' && cur != l.begin()) cur--;
        if(c=='D' && cur != l.end()) cur++;
        if(c=='B' && cur!=l.begin()) cur = l.erase(--cur);
        if(c=='P'){
            char s;
            cin >> s;
            l.insert(cur,s);
        }
    }

    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it;
    }
    cout << "\n";


}
