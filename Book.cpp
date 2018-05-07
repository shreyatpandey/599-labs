//
// Created by Biru Lyu on 3/26/18.
//

#include "Book.h"
#include <fstream>
#include <cstdlib>
/* Book default constructor
* Postcondition: title, author, ISBN, publisher and publishedYear are empty strings
*            && publishedYear == 0.
*/
Book::Book() {
    title = "";
    author = "";
    ISBN = "";
    publisher = "";
    publishedYear = 0;
}


/* Explicit constructor
    * @param: title, a string
    * @param: author, a string
    * @param: ISBN, a string
    * @param: publisher, a string
    * @param: publishedYear, an unsigned int.
    * Postcondition: this -> title == title &&
    *                this -> author == author &&
    *                this -> ISBN == ISBN &&
    *                this -> publisher == publisher &&
    *                this -> publishedYear == publishedYear.
    */
Book::Book(const string& title, const string& author, const string& ISBN, const string& publisher, unsigned publishedYear) {
    this -> title = title;
    this -> author = author;
    this -> ISBN = ISBN;
    this -> publisher = publisher;
    this -> publishedYear = publishedYear;
}

/* Book input method...
 * @param: in, an istream
 * Precondition: in contains the title, author, ISBN, publisher and published year data for a Book.
 * Postcondition: the title, author, ISBN, publisher and published year data have been read from in &&
 *                this -> title == title &&
 *                this -> author == author &&
 *                this -> ISBN == ISBN &&
 *                this -> publisher == publisher &&
 *                this -> publishedYear == publishedYear.
 */
void Book::readFrom(istream& in) {
    getline(in, this -> title);
    getline(in, this -> author);
    getline(in, this -> ISBN);
    getline(in, this -> publisher);
    string yearString;
    getline(in, yearString);
    this -> publishedYear = atoi( yearString.c_str());
}

/* Book output...
 * @param: out, an ostream
 * Postcondition: out contains title, a newline,
 *                             author, a newline,
 *                             ISBN, a newline,
 *                             publisher, a newline,
 *                             publishedYear, and a newline.
 *
 */
void Book::writeTo(ostream& out) const {
    out << this -> title << '\n'
        << this -> author << '\n'
        << this -> ISBN << '\n'
        << this -> publisher << '\n'
        << this -> publishedYear  << '\n';
}


/* getter method for title
 * Return: title
 */
string Book::getTitle() {
    return title;
}

/* getter method for author
 * Return: author
 */
string Book::getAuthor() {
    return author;
}

/* getter method for ISBN
 * Return: ISBN
 */
string Book::getISBN() {
    return ISBN;
}

/* getter method for publisher
 * Return: publisher
 */
string Book::getPublisher() {
    return publisher;
}

/* getter method for publishedYear
 * Return: publishedYear
 */
unsigned Book::getPublishedYear() {
    return publishedYear;
}