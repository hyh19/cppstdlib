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
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<string> coll;

    // 在 Debug 模式下运行，按组合键 Cmd + D 结束输入。

    // read all words from the standard input
    // - source: all strings until end-of-file (or error)
    // - destination: coll (inserting)
    copy(istream_iterator<string>(cin),    // start of source
         istream_iterator<string>(),       // end of source
         back_inserter(coll));             // destination

    // sort elements
    sort(coll.begin(), coll.end());

    // print all elements without duplicates
    // - source: coll
    // - destination: standard output (with newline between elements)
    unique_copy(coll.cbegin(), coll.cend(),           // source
                ostream_iterator<string>(cout, "\n")); // destination
}
