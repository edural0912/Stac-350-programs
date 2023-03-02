#ifndef WTREE_H
#define WTREE_H
#include "wtreenode.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class WTree
{
    public:
        WTree();
        void insert(string word, int line);
        void printTreeInOrder();
        int countUniqueWords();
        int countWords();
        string fWord();
        string lWord();
        void remove(string);
        vector<int> wordLine(string word);

    protected:
        wTreeNode * insert(wTreeNode * node, string word, int lineNumbers);
        int countUniqueWords (wTreeNode * node);
        int countWords (wTreeNode * node);
        void printTreeInOrder(wTreeNode * node);
        string fWord(wTreeNode * node);
        string lWord(wTreeNode * node);
        wTreeNode * remove(wTreeNode * node, string word);
        vector<int> wordLine(wTreeNode * node, string word);


    private:
        wTreeNode * m_root;
};

#endif // WTREE_H
