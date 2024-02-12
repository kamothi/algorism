#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// n*m 격자판, x,y -> r,c로 이동하는 거리가 총 k여야함.
// 사전순으로 빠른 경로로 해야함. 즉 탐색을 할 때 d, l, r, u 순으로 탐색해야함.

bool check(int nx, int ny, int n, int m){
    return (nx > 0 && ny > 0 && nx <= n && ny <= m);
}

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

void dfs(int n,int m, int nowX ,int nowY, int r, int c, int k,string& answer, bool& isTrue , int nowCnt, string& stack){
    if(isTrue) return;
    
    if (k - nowCnt < abs(nowX-r) + abs(nowY-c)){
        return;
    }
    if(nowCnt == k && nowX == r && nowY == c){
        isTrue = true;
        answer = stack;
        return;
    }
    if(nowCnt == k) return;
        
        for(int i=0;i<4;i++){
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];
            if(check(nx,ny,n,m)){
                if(i==0) {
                    stack += "d";
                    dfs(n,m,nx,ny,r,c,k,answer,isTrue,nowCnt+1,stack);
                }
                else if(i==1) {
                    stack += "l";
                    dfs(n,m,nx,ny,r,c,k,answer,isTrue,nowCnt+1,stack);
                }
                else if(i==2) {
                    stack += "r";
                    dfs(n,m,nx,ny,r,c,k,answer,isTrue,nowCnt+1,stack);
                }
                else {
                    stack += "u";
                    dfs(n,m,nx,ny,r,c,k,answer,isTrue,nowCnt+1,stack);
                }
                stack = stack.erase(stack.size()-1);
            }
        }
}


string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    bool isTrue = false;
    string stack = "";
    int remain = abs(x-r) + abs(y-c);
    if ((k - remain) % 2 != 0 || remain > k) {
       return "impossible";
    }
    dfs(n,m,x,y,r,c,k,answer,isTrue,0,stack);
    if(answer == ""){
        return "impossible";
    }
    
    return answer;
}
