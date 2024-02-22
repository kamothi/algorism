#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isTrue(int n){
    if(n < 2) return false;
    for(int i=2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

// 범위가 작기에 완탐 가능
int solution(string numbers) {
    vector<char> tmp;
    vector<int> nums;
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        tmp.push_back(numbers[i]);
    }
    sort(tmp.begin(),tmp.end());
    
    
    do {
        string temp = "";
        for (int i = 0; i < tmp.size(); i++) {
            temp.push_back(tmp[i]);
            nums.push_back(stoi(temp));
        }
    } while (next_permutation(tmp.begin(), tmp.end()));
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    for (int i = 0; i < nums.size(); i++)
        if (isTrue(nums[i]))
            answer++;
    return answer;
}
