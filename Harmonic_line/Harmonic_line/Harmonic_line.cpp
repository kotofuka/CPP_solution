#include <iostream>

using namespace std;
/*
int do_reduction(int x, int y) {
	int k = 1;
	for (int i = 1; i <= min(x, y); i++) {
		if (x % i == 0 and y % i == 0) {
			k = i;
		}
	}

	return k;
}
*/
/*
int do_gcd(int x, int y) {

	if (x == y) {
		return x;
	}
	else if (x > y) {
		return do_gcd(x - y, y);
	}
	return do_gcd(x, y - x);
}

pair <double, double> do_sum(double n, double x, double y) {

	double numerator = 1 * y + x * n;
	double denominator = n * y;

	int reduction = do_reduction(numerator, denominator);
	//cout << "numerator = " << numerator << ", denominator = " << denominator << ", reduction = " << reduction << ", n = " << n << ", x = " << x << ", y = " << y << ", k = " << k << endl;
	return { numerator / reduction, denominator / reduction};
}
*/

int main() {
	int n;
	cin >> n;
	pair <double, double> fraction = { 1, 1 };
	for (int i = 2; i <= n; i++) {
		fraction = do_sum(i, fraction.first, fraction.second);
		//cout << fraction.first << " " << fraction.second << " !" << endl;
	}
	cout << fraction.first << " " << fraction.second << endl;
	printf ("%.15f", long double(fraction.first) / long double(fraction.second));
	return 0;
}