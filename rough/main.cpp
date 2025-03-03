#include <iostream>
using namespace std;

int globalVar = 100;  // ✅ Global variable

void myFunction() {
    class LocalClass {  // Local class inside function
    public:
        void show() {
            cout << "Global Variable: " << globalVar << endl;  // ✅ Allowed
        }
    };

    LocalClass obj;
    obj.show();
}

int main() {
    myFunction();
    return 0;
}
