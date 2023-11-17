#include <iostream>
#include <cmath>

using namespace std;

int main() {
	short int a = 65535;
	short int s;
	while (a) {
		if (a % 2 == 0) {
			s = (a) / 2 * (a + 1);
			cout << "number " << a << " " << s << endl;
			if (s < 0){
				break;
			}

		}
		else {
			s = (a + 1) / 2 * (a);
			cout << "number " << a << " " << s << endl;
			if (s < 0) {
				break;
			}
		}
		
		a++;
	}

	//cin >> a;
	cout << (a + 1) * a / 2;
	return 1;
}