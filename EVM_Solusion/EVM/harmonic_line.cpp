#include <iostream>

using namespace std;

int main() {
	int a, i;
	cin >> a;
	float s = 0;
	for (int i = 0; i < a; i++) {
		s += 1 / a;
	}
	cout << s;

	return 0;
}