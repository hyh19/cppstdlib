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
#include <iterator>
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    auto pos = coll.begin();

    // print actual element
    cout << *pos << endl;

    // step three elements forward
    advance(pos, 3);

    // print actual element
    cout << *pos << endl;

    // step one element backward
    advance(pos, -1);

    // print actual element
    cout << *pos << endl;
}
