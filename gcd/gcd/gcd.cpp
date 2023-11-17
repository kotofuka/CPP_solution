
#include <iostream>

int do_gcd(int x, int y) {

	if (x == y) {
		return x;
	}
	else if (x > y) {
		return do_gcd(x - y, y);
	}
	return do_gcd(x, y - x);
}

int main()
{
    std::cout << do_gcd(3, 5);
}
