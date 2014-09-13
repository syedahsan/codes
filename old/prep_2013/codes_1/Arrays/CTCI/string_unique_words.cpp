#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 1000
#define DEBUG 0

bool is_unique_hash(char *inp)
{
        char *token = NULL;
        map<string, int> hash;

        token = strtok(inp, " ");
        string tok(token);
        hash[tok] = (hash[tok] ? hash[tok] + 1 : 1);
        while (token = strtok(NULL, " ")) {
                tok = token;
                hash[tok] = (hash[tok] ? hash[tok] + 1 : 1);
        }

        map<string, int>::iterator it;
        for (it=hash.begin(); it!=hash.end(); it++) {
#if DEBUG
                cout << it->first << "->" << it->second << endl;
#endif
                if (it->second > 1)
                        return false;
        }

        return true;
}

/* This is not really a correct implementation of not using
 * any additional data structure since we are creating a
 * vector which holds the tokenized string; which is easier
 * to sort and compare
 * Ideally we should sort the string somehow and then compare
 */
bool is_unique_sort(char *inp)
{
        char *token = NULL;
        vector<string> str;

        token = strtok(inp, " ");
        str.push_back(token);
        while (token = strtok(NULL, " ")) {
                str.push_back(token);
        }

#if DEBUG
        for (vector<string>::const_iterator it = str.begin(); it != str.end(); ++it)
                cout << *it << endl;
#endif
        sort(str.begin(), str.end());
#if DEBUG
        for (vector<string>::const_iterator it = str.begin(); it != str.end(); ++it)
                cout << *it << endl;
#endif

        string prev;
        for (vector<string>::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (prev == *it)
                        return false;
                prev = *it;
        }

        return true;
}


int main()
{
#if 0   /* CPP way of reading a line */
        string line;
        getline(cin, line);
#endif
        char inp[MAX_LEN];
        scanf("%[^\n]", inp);

#if DEBUG
        cout << inp << endl;
#endif

        cout << "Is Unique[Hash]: " << (is_unique_hash(strdup(inp)) ? "True" : "False") << endl;
        cout << "Is Unique[Sorting]: " << (is_unique_sort(strdup(inp)) ? "True" : "False") << endl;

}
