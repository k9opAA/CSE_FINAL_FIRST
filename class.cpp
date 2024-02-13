#include <iostream>
#include <cstdlib>

using namespace std;

class myclass {
    int *p;

public:
    myclass(int i);
    ~myclass() { delete p; }
    friend int getval(const myclass& o); // Pass by reference to avoid unnecessary copying
};

myclass::myclass(int i) {
    p = new int;
    if (!p) {
        cout << "Allocation error\n";
        exit(1);
    }
    *p = i;
}

int getval(const myclass& o) {
    return *o.p; // get value
}

int main() {
    myclass a(1), b(2);
    cout << getval(a) << " " << getval(b) << "\n";
    cout << getval(a) << " " << getval(b);
    return 0;
}
