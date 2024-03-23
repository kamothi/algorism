#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Student{
    int ability;
    int algo[30];
};

Student student[100000];
int tmp[30];
int result;
bool cmp(Student s1, Student s2){
    return s1.ability < s2.ability;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,d;
    cin >> n >> k >> d;

    for(int i=0;i<n;i++){
        int m, dd;
        cin >> m >> dd;
        student[i].ability = dd;
        while(m--){
            int a;
            cin >> a;
            student[i].algo[a-1] = 1;
        }
    }

    sort(student,student+n, cmp);

    int left = 0, right = 0;

    while(right < n && left <= right){
        int cnt1 = 0;
        int cnt2 = 0;

        if(student[right].ability - student[left].ability > d){
            for(int i=0;i<k;i++){
                if(student[left].algo[i]) tmp[i]--;
            }
            left++;
            continue;
        }

        // 각 자리마다 체크
        for(int i=0;i<k;i++){
            if(student[right].algo[i]){
                tmp[i]++;
            }
        }

        // 그룹원이 아는 모든 알고리즘, 모두가 아는 알고리즘
        for(int i=0;i<k;i++){
            if(tmp[i] > 0) cnt1++;
            if(tmp[i] == (right-left+1)) cnt2++;
        }


        result = max(result,(cnt1-cnt2)*(right-left+1));
        right++;

    }


    cout << result;
}
