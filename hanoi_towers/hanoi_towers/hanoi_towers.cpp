#include <iostream>
#include <stack>
#include <set>
#include <iterator>

using namespace std;

void Tower_hanoi(int n, char from, char to, char buf);
set<stack<int>> Tower_v2(int n, stack<int> x, stack<int> y, stack<int> z);
void print_tower(stack<int> stack, int n);

int main() {

	char from = 'A', to = 'B', buf = 'C';
	int number;

	cin >> number;

	Tower_hanoi(number, from, to, buf);

	stack<int> tower_1, tower_2, tower_3;

	for (int i = number; i > 0; i--) {
		tower_1.push(i);
	}
	//Tower_v2(number, tower_1, tower_2, tower_3);

	return 0;
}

void Tower_hanoi(int n, char from, char to, char buf) {

	if (n == 0) {
		return;
	}
	else if (n == 1) {
		cout << "Move disk " << n << " from " << from << " to " << buf << endl;
	}
	else {
		Tower_hanoi(n - 1, from, buf, to);
		cout << "Move disk " << n << " from " << from << " to " << buf << endl;
		Tower_hanoi(n - 1, to, from, buf);
	}

	return;
}

set<stack<int>> Tower_v2(int n, stack<int> x, stack<int> y, stack<int> z) {

	if (n == 0) {
		print_tower(x, 1);
		print_tower(y, 2);
		print_tower(z, 3);
		return {x, y, z};
	}
	else if (n == 1) {
		x.push(z.top());
		z.pop();

		print_tower(x, 1);
		print_tower(y, 2);
		print_tower(z, 3);

		return { x, y, z };
	}
	//move(n - 1, z, y);
	set <stack<int>> move = Tower_v2(n - 1, x, z, y);
	x = *move.begin();
	y = *next(move.begin(), 1);
	z = *move.rbegin();
	x.push(z.top());
	z.pop();
	
	print_tower(x, 1);
	print_tower(y, 2);
	print_tower(z, 3);

	Tower_v2(n - 1, x, y, z);


	return { x,y,z };
}

void print_tower(stack<int> stack, int n) {
	cout << "Tower " << n << ":" << endl;
	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	return;
}
