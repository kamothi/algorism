#include<iostream>
#include<stack>
#include<string>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	stack<char> s;
	int sum = 0;
	int tmp = 1;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
			if (str[i] == '(') tmp *= 2;
			else tmp *= 3;
		}
		else {
			if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					sum = 0;
					break;
				}
				s.pop();

				if (str[i - 1] == '(')
				{
					sum += tmp;
					tmp /= 2;
				}
				else
				{
					tmp /= 2;
				}
			}
			else {
				if (s.empty() || s.top() != '[') {
					sum = 0;
					break;
				}
				s.pop();

				if (str[i - 1] == '[')
				{
					sum += tmp;
					tmp /= 3;
				}
				else
				{
					tmp /= 3;
				}
			}
		}

		
	}
	if (!s.empty()) sum = 0;

	cout << sum;
}
