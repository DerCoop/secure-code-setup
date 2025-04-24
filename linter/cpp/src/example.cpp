#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x; // no input validation
    if (x = 42) { // assignment instead of comparison
        cout << "You found the secret!" << endl;
    }
    return 0;
}