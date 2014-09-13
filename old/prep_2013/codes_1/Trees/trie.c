#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 26

typedef struct _trie {
        unsigned int end;
        char c;
        struct _trie *child[MAX_CHARS];
} trie;

trie* allocate(char c)
{
        int i;
        trie *node = calloc(1, sizeof(trie));

        node->c = c;
        node->end = 0;
        for (i = 0; i < MAX_CHARS; ++i)
                node->child[i] = NULL;

        return (node);
}

trie* insert(trie *root, char *word)
{
        if (root == NULL)
                root = allocate('\0');

        trie *ret = root;
        unsigned int len = strlen(word);
        int i;

        for (i = 0; i < len; ++i) {
                if (root->child[word[i] - 'a'] == NULL)
                        root->child[word[i] - 'a'] = allocate(word[i]);
                root = root->child[word[i] - 'a'];
        }
        root->end += 1;

        return (ret);
}

/* returns the frequency of occurance;
 * 0 - not found
 * positive integer - frequency
 */
unsigned int search(trie *root, char *word)
{
        unsigned int len = strlen(word);
        int i;

        for (i = 0; i < len; ++i) {
                if (root->child[word[i] - 'a'] == NULL)
                        return (0);
                else
                        root = root->child[word[i] - 'a'];
        }
        
        return (root->end);
}

int main()
{
        char *words[] = {"syed", "ahsan", "ishtiaque", "puneet", "ahsan"};

        int i;
        trie *root = NULL;
        int size = sizeof(words)/sizeof(char *);

        for (i = 0; i < 5; ++i)
                root = insert(root, words[i]);

        unsigned int found;

        found = search(root, "ahsan");
        printf("Search: %s | found: %s | frequency: %d\n", "ahsan", (found ? "Yes" : "No"), found);

        found = search(root, "syed");
        printf("Search: %s | found: %s | frequency: %d\n", "syed", (found ? "Yes" : "No"), found);

        found = search(root, "blah");
        printf("Search: %s | found: %s | frequency: %d\n", "blah", (found ? "Yes" : "No"), found);

        return 0;
}
