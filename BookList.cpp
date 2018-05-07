

#include "BookList.h"
#include <cassert>
#include<bits/stdc++.h>
using namespace std;

/*  BookList constructor
    * @param: fileName, a string
    * Precondition: fileName contains the name of a input file.
    */
BookList::BookList(const string& fileName) {
    // open a stream to the booklist file
    ifstream fin( fileName.c_str() );
    assert( fin.is_open() );

    // read each book and append it to totalBooks
    Book book;
    string separator;
    while (true) {
        book.readFrom(fin);
        if ( !fin ) { break; }
        getline(fin, separator);
        totalBooks.push_back(book);
    }

    // close the stream
    fin.close();
}

/* Retrieve length of the book list
 * Return: the number of books in the list.
 */
unsigned BookList::getNumBooks() const {

    return totalBooks.size();
}

unsigned BookList::searchauthorname(string Author) {
    string ret_author;
    int count=0;
    vector<Book>::iterator it;
    for(it=totalBooks.begin();it!=totalBooks.end();++it)
    {
        ret_author = (*it).getAuthor();
        if(ret_author == Author)
        {
          count++;
         }
     }
    if(count == 0)
    {
         cout<<"Author name does not exist in directory"<<endl;
    }
    else {
        cout << "Author name exist in directory" << endl;

    }
    if(count>0)
    {
        for(it=totalBooks.begin();it!=totalBooks.end();++it)
        {
            ret_author = (*it).getAuthor();
            if(ret_author == Author)
            {
                string ret_title = (*it).getTitle();
                cout<<"Book written by author:"<<Author<<" "<<"is"<<" "<<ret_title<<endl;
                int num = (*it).getPublishedYear();
                cout<<"It was published in:"<<num<<endl;
                string isbn= (*it).getISBN();
                cout<<"ISBN:"<<isbn<<endl;
                string publisher = (*it).getPublisher();
                cout<<"Publisher:"<<publisher<<endl;
            }
        }
    }
 return count;
    }


unsigned BookList::searchtitlename(string title) {
    string ret_title;
    vector<Book>::iterator it;
    int flag=0;
    for(it=totalBooks.begin();it!=totalBooks.end();++it)
    {
        ret_title = (*it).getTitle();

        if(ret_title == title) {
           flag ++;

        }
    }

    if (flag == 0)
    {
        cout<<"No book of this title exists in directory"<<endl;

    }
    else {
        cout << "Book containing this title exists in directory" << endl;

    }
    if(flag>0)
    {
        for(it=totalBooks.begin();it!=totalBooks.end();++it)
        {
            ret_title = (*it).getTitle();
            if(ret_title == title)
            {
                string ret_author = (*it).getTitle();
                cout<<"Book written by author:"<<ret_author<<" "<<"is"<<" "<<ret_title<<endl;
                int num = (*it).getPublishedYear();
                cout<<"It was published in:"<<num<<endl;
                string isbn= (*it).getISBN();
                cout<<"ISBN:"<<isbn<<endl;
                string publisher = (*it).getPublisher();
                cout<<"Publisher:"<<publisher<<endl;
            }
        }
    }
    return flag;

}

unsigned BookList::searchpubyear(int num)
{
    int ret_year;
    int count=0;
    vector<Book>::iterator it;
    for(it=totalBooks.begin();it!=totalBooks.end();++it)
    {
        ret_year = (*it).getPublishedYear();

        if(ret_year == num) {
            count +=1;

            //return ret_title;
        }
    }
    if(count == 0)
    {
          cout<<"No books in this directory were ever published in year:"<<num<<endl;

    } else{
        cout<<"The number of books published in year:"<<num<<" "<<"is"<<" "<<count<<endl;
    }
    return count;

}
