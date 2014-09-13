#include <iostream>
#include <string>
#include "SLL.h"

using namespace std;

int main()
{
        /* string list */
        SList<string> strlist;
        strlist.push_back("syed");
        strlist.push_back("ahsan");
        strlist.push_front("ishtiaque");
        strlist.print();
        cout << strlist.is_present("ahsan") << endl;
        strlist.push_back("ahsan");
        strlist.print();
        strlist.delete_first("ahsan");
        strlist.print();
        strlist.push_back("ahsan");
        strlist.print();
        strlist.delete_all("ahsan");
        strlist.print();


        return 0;
}
