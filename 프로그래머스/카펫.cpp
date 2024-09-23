#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int chance = (brown - 8) / 2;

    int w = 3, h = 3;
    for(int i = 0; i < chance; i++)
    {
        int tw = 3 + (chance - i);
        int th = 3 + i;

        if(yellow != (th - 2) * (tw - 2))
        {
            continue;
        }

        if(brown + yellow == tw * th)
        {
            w = tw;
            h = th;
            break;
        }
    }

    answer.push_back(w);
    answer.push_back(h);

    return answer;
}
