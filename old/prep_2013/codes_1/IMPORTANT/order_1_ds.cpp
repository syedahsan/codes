#include <iostream>
#include "Hashed_DLL.h"

using namespace std;

int main()
{
        Hashed_DLL<int> list;
        int n;
        bool is_deleted;

        cout << "Enter integers to insert into this DS; enter \"-1\" to exit" << endl;
        while (true) {
                cin >> n;
                if (n == -1)
                       break;
                list.push_back(n);
        }
        list.print();
        cout << endl;
        list.print(PRINT_HASH);
        cout << endl;

        cout << "Enter interger to delete its single occurance (if any): ";
        cin >> n;
        is_deleted = list.delete_one(n);
        list.print();
        
        cout << "Enter interger to delete its all occurance (if any): ";
        cin >> n;
        is_deleted = list.delete_all(n);
        list.print();

        return 0;
}
