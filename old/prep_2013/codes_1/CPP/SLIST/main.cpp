#include <iostream>
#include <string>
#include "SList.h"

using namespace std;

int main()
{
        /* string list */
        SList<string> strlist;
        strlist.insert("syed");
        strlist.insert("ahsan");
        strlist.insert("ishtiaque");
        strlist.print();
        cout << strlist.isPresent("ahsan") << endl;
        strlist.insert("ahsan");
        strlist.print();
        strlist.remove("ahsan");
        strlist.print();

        return 0;
}
