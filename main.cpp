#include <iostream>
#include <string>
#include <memory>
#include "i_ptr.h"
using namespace std;
int main() {
    i_ptr<string> ptr(new string("aaaa"));
    i_ptr<string> ptr1(new string("ddddd"));
    i_ptr<string> ptr2(ptr);
    ptr1 = ptr;
    ptr1 = ptr;
    return 0;
}