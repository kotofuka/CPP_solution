#include <iostream>

using namespace std;

void ri(int* p);

int main() {
	/*
	int a = 5;
	int& b = a;
	cout << a << endl;
	ri(&a);
	cout << "a = " << a << endl;
	*/

	//massiv
	/*
	int a[10]{};
	ri(a);

	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";

	}
	cout << endl;
	*/

	int a = 7;
	int *p = &a;
	(*p) = 5;
	int** d = &p;
	(**d) = 1;
	cout << "a = " << a << endl;
	cout << "p = " << p << endl;
	cout << "d = " << d << endl;

	return 0;
}

/*
void ri(int* p) {
	cin >> (*p);
}
*/

void ri(int x[]) {
	x[3] = 4;
}