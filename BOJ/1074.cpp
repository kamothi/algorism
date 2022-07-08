#include<iostream>
#include<cmath>
using namespace std;
int N, r, c, Size, result=0;
int temp1, temp2;
void Find_Z(int a,int b) {
	if (Size >= 2) {
		if (Size / 2 >= a && Size / 2 >= b) {
			temp1 = a;
			temp2 = b;
			Size = Size / 2;
			Find_Z(temp1, temp2);
		}
		else if (Size / 2 >= a && Size / 2 < b) {
			result += Size * Size / 4;
			temp1 = a;
			temp2 = b - Size / 2;
			Size = Size / 2;
			Find_Z(temp1, temp2);
		}
		else if (Size / 2 < a && Size / 2 >= b) {
			result += Size * Size / 4 * 2;
			temp1 = a - Size / 2;
			temp2 = b;
			Size = Size / 2;
			Find_Z(temp1, temp2);
		}
		else if (Size / 2 < a && Size / 2 < b) {
			result += Size * Size / 4 * 3;
			temp1 = a - Size / 2;
			temp2 = b - Size / 2;
			Size = Size / 2;
			Find_Z(temp1, temp2);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;
	r += 1;
	c += 1;
	Size = pow(2,N);
	Find_Z(r, c);
	cout << result;
}
