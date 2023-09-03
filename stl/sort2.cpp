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
#include <algorithm>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

/* class Person
 */
class Person {
private:
    string fn;    // first name
    string ln;    // last name
public:
    Person() = default;

    Person(string f, string n)
            : fn(std::move(f)), ln(std::move(n)) {
    }

    string firstname() const;

    string lastname() const;
    // ...
};

inline string Person::firstname() const {
    return fn;
}

inline string Person::lastname() const {
    return ln;
}

ostream &operator<<(ostream &s, const Person &p) {
    s << "[" << p.firstname() << " " << p.lastname() << "]";
    return s;
}


int main() {
    // create some persons
    Person p1("nicolai", "josuttis");
    Person p2("ulli", "josuttis");
    Person p3("anica", "josuttis");
    Person p4("lucas", "josuttis");
    Person p5("lucas", "otto");
    Person p6("lucas", "arm");
    Person p7("anica", "holle");

    // insert person into collection coll
    deque<Person> coll;
    coll.push_back(p1);
    coll.push_back(p2);
    coll.push_back(p3);
    coll.push_back(p4);
    coll.push_back(p5);
    coll.push_back(p6);
    coll.push_back(p7);

    // print elements
    cout << "deque before sort():" << endl;
    deque<Person>::iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << endl;
    }

    // sort Persons according to lastname (and firstname):
    sort(coll.begin(), coll.end(),                // range
         [](const Person &p1, const Person &p2) { // sort criterion
             return p1.lastname() < p2.lastname() ||
                    (p1.lastname() == p2.lastname() &&
                     p1.firstname() < p2.firstname());
         });

    // print elements
    cout << "deque after sort():" << endl;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << endl;
    }
}
