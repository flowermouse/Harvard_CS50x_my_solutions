// Implements a dictionary's functionality
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int dic_num = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int num = hash(word);
    node *n = table[num];
    while(n != NULL)
    {
        if(strcasecmp(word,n->word)==0)
            return true;
        n = n -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary,"r");
    if(input == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(input,"%s",word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n==NULL)
            return false;
        strcpy(n->word,word);
        int num = hash(word);
        n -> next = table[num];
        table[num] = n;
        dic_num++;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(dic_num>0)
       return dic_num;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i<N; i++)
    {
        node *p = table[i];
        while(p!=NULL)
        {
            node *q = p;
            p = p->next;
            free(q);
        }
        if(i == N-1&&p == NULL)
           return true;
    }
    return false;
}
