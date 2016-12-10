#include <iostream>
#include <string>
#include <memory>
#include "i_ptr.h"
using namespace std;
int main() {
    i_ptr<string> ptr(new string("object1"));
    i_ptr<string> ptr1(new string("object2"));
    i_ptr<string> ptr2;
    ptr2 = ptr;
    ptr2 = ptr1;



    return 0;
}