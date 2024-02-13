// This program contains an error.
#include <iostream > #include <cstdlib > using namespace std;
 class myclass {
int *p; public:
 myclass(int i);
~myclass() { delete p; } friend int getval(myclass o);
};
 myclass::myclass(int i) {
p = new int;
if(!p) {
 cout << "Allocation error\n";
exit(1); }
*p = i; }
 int getval(myclass o) {
return *o.p; // get value }
 int main () {
myclass a(1), b(2);
 cout << getval(a) << " " << getval(b); cout << "\n";
cout << getval(a) << " " << getval(b);
return 0;
 }
132

FUNCTION OVERLOADING
5.3. THE OVERLOAD ANACHRONISM
3. In your ow
