#include <iostream>
#include "Hashed_DLL.h"

using namespace std;

int main()
{
        //char a[13][5] = {"I", "am", "a", "good", "boy", "am", "here", "over", "boy", "come", "over", "here", "boy"};
        char a[13][5] = {};
        Hashed_DLL<string> list;
        int size = 13;
       
        for (int i = 0; i < size; ++i)
                list.push(a[i]);

        list.print();
        return 0;
}
