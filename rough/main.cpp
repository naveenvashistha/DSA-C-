#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Inside try block." << endl;
        int x = 10, y = 0;
		if(y == 0) throw "hi";
        int z = x / y;  // Division by zero, ERROR
        cout << "Result: " << z << endl;
    }
    catch (const char* e) {
        cout << "Caught exception: " << e << endl;
    }

    cout << "After try-catch block." << endl;

    return 0;
}
