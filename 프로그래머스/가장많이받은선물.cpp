#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int give[50];
int recieve[50];
int point[50];
int arr[50][50];
int result[50];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i=0;i<gifts.size();i++){
        string tmp = gifts[i];
        string a = strtok(&tmp[0]," ");
        string b = strtok(NULL," ");
        int tmp1,tmp2;
        for(int j=0;j<friends.size();j++){
            if(friends[j] == a){
                give[j]++;
                tmp1 = j;
            }
            if(friends[j] == b){
                recieve[j]++;
                tmp2 = j;
            }
        }
        arr[tmp1][tmp2]++;
    }
    
    for(int i=0;i<friends.size();i++){
        point[i] = give[i] - recieve[i];
    }
    
    for(int i=0;i<friends.size();i++){
        for(int j=i+1;j<friends.size();j++){
            if(arr[i][j] > arr[j][i]) result[i]++;
            else if(arr[i][j] < arr[j][i]) result[j]++;
            else{
                if(point[i] > point[j]) result[i]++;
                if(point[i] < point[j]) result[j]++;
            }
            answer = max({result[i],answer,result[j]});
            
        }
    }
    return answer;
}
