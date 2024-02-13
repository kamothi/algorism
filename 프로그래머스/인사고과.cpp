#include <string>
#include <vector>
#include<algorithm>

using namespace std;


struct Score {
    int a;
    int b;
};

bool cmp(Score A, Score B){
    return A.a < B.a;
}

bool sumCmp(Score A, Score B){
    return (A.a+A.b) > (B.a+B.b);
}
    
int solution(vector<vector<int>> scores) {
    int answer = 0;
    int attitude  = scores[0][0];
    int evaluation = scores[0][1];
    
    vector<Score> s;
    for(int i=0;i<scores.size();i++){
        s.push_back({scores[i][0],scores[i][1]});
    }
    
    sort(s.begin(),s.end(),cmp);
    
    for(int i=0;i<s.size()-1;i++){
        bool check = false;
        for(int j=i+1;j<s.size();j++){
            if(s[i].a == s[j].a) continue;
            if(s[i].b < s[j].b) {
                s.erase(s.begin()+i);
                check = true;
                break;
            }
        }
        if(check) i--;
    }
    
    sort(s.begin(),s.end(),sumCmp);
    
    bool success = false;
    int rank = 1;
    int nowSum = 0;
    int tmp =0;
    
    for(int i=0;i<s.size();i++){
        int sum = s[i].a + s[i].b;
        if(attitude == s[i].a && evaluation == s[i].b){
            success = true;
            if(nowSum != sum) rank += tmp;
            break;
        }
        if(nowSum == sum) tmp++;
        else{
            rank += tmp+1;
            tmp = 0;
        }
        nowSum = sum;
    }
    
    if(!success) rank = -1;
    
    return rank;
    
}
