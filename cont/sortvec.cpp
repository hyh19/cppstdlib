/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    // create a string vector
    // - initialized by all words from standard input
    vector<string> coll((istream_iterator<string>(cin)),
                        istream_iterator<string>());

    // sort elements
    sort(coll.begin(), coll.end());

    // print all elements ignoring subsequent duplicates
    unique_copy(coll.cbegin(), coll.cend(),
                ostream_iterator<string>(cout, "\n"));
}
