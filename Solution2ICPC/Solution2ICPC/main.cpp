#include <iostream>

using namespace std;

int main() {
	int x1, y1, x2, y2, k;
	cin >> x1 >> y1 >> x2 >> y2 >> k;

	if (abs(x1 - x2) + abs(y1 - y2) <= k) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}