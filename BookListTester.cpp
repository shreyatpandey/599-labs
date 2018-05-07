//
// Created by Biru Lyu on 3/26/18.
//

#include "BookListTester.h"
#include "BookList.h"
#include <iostream>
#include <cassert>
using namespace std;

void BookListTester::runTests() {
    cout << "\nTesting class BookList..." << endl;
    testConstructors();
    testAuthorname();
    testtitlename();
    testpubyear();
    cout << "All tests passed!" << endl;
}

void BookListTester::testConstructors() {
    cout << "- constructors..." << flush;
    BookList bList("input.txt");
    assert( bList.getNumBooks() == 5 );
    cout << " 0 " << flush;

    cout << " Passed!" << endl;
}
void BookListTester::testAuthorname() {
    cout<<"\n"<<endl;
    cout << "Author test starts:" << endl;
    BookList blist("input.txt");
    int count = blist.searchauthorname("Jane Austen");
    assert(count == 2);
    cout<<" Author Test Passed "<<endl;

}
void BookListTester::testtitlename()
{
  cout<<"\n"<<endl;
    cout<<"Titlename test starts:"<<endl;
    BookList blist("input.txt");
    int count = blist.searchtitlename("Beloved");
    assert(count == 1);
    cout<<"Titlename test passed"<<endl;
}
void BookListTester::testpubyear() {
    cout<<"\n"<<endl;
    cout<<"Published year test starts:"<<endl;
    BookList blist("input.txt");
    int count = blist.searchpubyear(1970);
    assert(count == 1);
    cout<<"Published year test passed"<<endl;

}
