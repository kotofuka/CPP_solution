#include <iostream>
#include <string>

using namespace std;
// kahan sum
int main() {
	int n, i;
	double sum = 0.0, c = 0.0;

	cin >> n;
	for (i = 1; i <= n; i++) {
		double y = 1.0 / i - c;
		double t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	cout << sum << endl;
	return 0;
}