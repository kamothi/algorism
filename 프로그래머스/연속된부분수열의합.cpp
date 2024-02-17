#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,0};
    int sum = 0;
    int left = 0;
    int right = 0;
    int line = 2000000000;

    
    while(1){
        if(sum >= k){
            if (sum == k && (right - left) < line) {
                line = right - left;
                answer[0] = left;
                answer[1] = right - 1;
            }
            sum -= sequence[left++];
            
        }else{
            if(right == sequence.size()) break;
            else{
                sum += sequence[right++];
            }
        }
    }
    
    return answer;
}
