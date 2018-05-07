#include "BookTester.h"
#include "BookListTester.h"
#include <iostream>
using namespace std;

int main()
{
    BookTester bookTester;
    bookTester.runTests();
    BookListTester aBookListTester;
    aBookListTester.runTests();
}