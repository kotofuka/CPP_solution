#include <iostream>

using namespace std;

typedef unsigned long long int ll;

ll fib(ll n, ll cache[]) {
	if (cache[n] == 0) {
		cache[n] = fib(n - 1, cache) + fib(n - 2, cache);
	}
	return cache[n];
}

int main() {
	ll n;
	ll cache[100] = { 1 , 1 };
	cin >> n;

	cout << fib(n, cache) << endl;
	return 0;
}
/*
ll fib(ll n) {
	if (n < 2) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}
*/
