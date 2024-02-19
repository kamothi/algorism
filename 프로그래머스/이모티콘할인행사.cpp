#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int discount[7];
int possibleUser = 0;
int totalPrice = 0;

void solve(vector<vector<int>>& users, vector<int>& emoticons, int idx, int cnt){
    if(idx >= cnt){
        int tmpUser = 0;
        int tmpTotal = 0;
        for(int i=0;i<users.size();i++){
            int userTotal = 0;
            for(int j=0;j<emoticons.size();j++){
                if(users[i][0] <= discount[j]){
                    userTotal += emoticons[j]*(1-discount[j]*0.01);
                }
            }
            if(userTotal >= users[i][1]){
                tmpUser++;
            }else{
                tmpTotal += userTotal;
            }
        }
        if(tmpUser > possibleUser){
            possibleUser = tmpUser;
            totalPrice = tmpTotal;
        }
        else if(tmpUser == possibleUser){
            if(tmpTotal > totalPrice) totalPrice = tmpTotal;
        }
        return;
    }
    else{
        for(int i=1;i<=4;i++){
            discount[idx] = i*10;
            solve(users,emoticons,idx+1,cnt);
        }   
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    solve(users,emoticons,0,emoticons.size());
    answer.push_back(possibleUser);
    answer.push_back(totalPrice);
    return answer;
}
