#include<iostream>
#include<stack>

using namespace std;


// 중위 표기식이 주어지면 후위 연산으로 변경
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    stack<char> c;
    string s,result;
    cin >> s;

    for(int i=0;i<s.size();i++){
        //문자면 그냥 출력
        //여는 괄호는 그냥 push
        //* , / 는 스택의 top에 우선순위가 같은 연산자가 있으면 계속 pop
        //+ , - 는 스택이 비거나 ( 를 만날때까지 연산자 계속 pop
        //닫는 괄호는 여는 괄호를 만날때까지 모두 pop

        // +, -, *, /, (, )
        if(s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-'
        && s[i] != '*' && s[i] != '/')
            result.push_back(s[i]);
        else if(s[i] == '('){
            c.push(s[i]);
        }
        else if(s[i] == '*' || s[i] == '/'){
            while(!c.empty() && (c.top() == '*' || c.top() == '/')) {
                result += c.top();
                c.pop();
            }
            c.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-'){
            while(!c.empty() && c.top() != '(') {
                result += c.top();
                c.pop();
            }
            //마지막에 push
            c.push(s[i]);
        }
        else{
            while(!c.empty() && c.top() != '(') {
                result += c.top();
                c.pop();
            }
            //여는 괄호 pop
            c.pop();
        }
    }

    while(!c.empty()) {
        result += c.top();
        c.pop();
    }
    cout << result;


}
