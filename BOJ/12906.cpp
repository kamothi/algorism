#include<iostream>
#include<queue>
#include<set>

using namespace std;

// 막대 A,B,C 원판 A,B,C
// 각각 맞는 막대에 원판을 옮기기. 여기서 최소 횟수

set<pair<pair<string,string>,string>> visited;

typedef struct{
    string a;
    string b;
    string c;
} Status;

bool check(string a, string b, string c){
    if(a.size() > 0){
        for(int i=0;i<a.size();i++){
            if(a[i] != 'A') return false;
        }
    }

    if(b.size() > 0){
        for(int i=0;i<b.size();i++){
            if(b[i] != 'B') return false;
        }
    }

    if(c.size() > 0){
        for(int i=0;i<c.size();i++){
            if(c[i] != 'C') return false;
        }
    }

    return true;
}

void bfs(Status s,int Cnt){
   queue<pair<Status,int>> q;
    string tmpA;
    string tmpB;
    string tmpC;
   q.push({s,Cnt});
   visited.insert({{s.a,s.b},s.c});

    while(!q.empty()){
        string a = q.front().first.a;
        string b = q.front().first.b;
        string c = q.front().first.c;
        int cnt = q.front().second;
        q.pop();

        if(check(a,b,c)){
            cout << cnt;
            return;
        }

        // a의 사이즈가 0보다 크면
        if(a.size() > 0){
            // a를 b로 옮기기
            tmpB = b + a[a.size()-1];
            tmpC = c;
            tmpA = a;
            tmpA.pop_back();
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }

            //  a를 c로 옮기기
            tmpC = c + a[a.size()-1];
            tmpB = b;
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }
        }

        // b의 사이즈가 0보다 크면
        if(b.size() > 0){
            // b를 a로 옮기기
            tmpA = a + b[b.size()-1];
            tmpC = c;
            tmpB = b;
            tmpB.pop_back();
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }

            //  b를 c로 옮기기
            tmpC = c + b[b.size()-1];
            tmpA = a;
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }
        }

        // c의 사이즈가 0보다 크면
        if(c.size() > 0){
            // c를 b로 옮기기
            tmpB = b + c[c.size()-1];
            tmpA = a;
            tmpC = c;
            tmpC.pop_back();
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }

            //  c를 a로 옮기기
            tmpA = a + c[c.size()-1];
            tmpB = b;
            if(visited.find({{tmpA,tmpB},tmpC}) == visited.end()){
                visited.insert({{tmpA,tmpB},tmpC});
                Status tmpS = {tmpA,tmpB,tmpC};
                q.push({tmpS,cnt+1});
            }
        }

    }


    // b의 사이즈가 0보다 크면
    // b를 a로 옮기기, b를 c로 옮기기

    // c의 사이즈가 0보다 크면
    // c를 a로 옮기기, c를 b로 옮기기
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, c;
    for(int i=0;i<3;i++){
        int n;
        char tmp;
        cin >> n;
        switch (i) {
            case 0: for(int j=0;j<n;j++){
                        cin >> tmp;
                        a.push_back(tmp);
                    }
                    break;
            case 1: for(int j=0;j<n;j++){
                    cin >> tmp;
                    b.push_back(tmp);
                }
                break;
            case 2: for(int j=0;j<n;j++){
                    cin >> tmp;
                    c.push_back(tmp);
                }
                break;
        }

    }
    bfs({a,b,c},0);

}
