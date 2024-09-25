#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check[50000];

// 구명보트의 limit을 생각해서 구명보트의 최소
// 최대 탑승 인원은 2명
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int l = 0, r = people.size()-1;
    
     while(l <= r) {
        if(people[l] + people[r] <= limit) {
            ++l, --r;
        }
        else --r;

        answer++;
    }
    return answer;
}
