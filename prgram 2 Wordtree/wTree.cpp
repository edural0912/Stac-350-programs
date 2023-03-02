#include "wTree.h"
#include "wtreenode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

WTree::WTree() : m_root(NULL)
{

}
wTreeNode * WTree::insert(wTreeNode * node, string word, int line)
{
    //if tree doesnt exist create new node as root
    //insert new node here
    if(node== NULL) {
        node = new wTreeNode();
        node -> m_word = word;
        node->m_left = NULL;
        node->m_right = NULL;
        node->m_parent = NULL;

    }
    else if (node->m_word == word)
    {
        // Check if already in tree, if so increment word
        // count and add line number to vector
        node->m_wordCount++;
    }
     // If the given key is greater than node's key then go to right subtree
    else if (node->m_word < word)
    {
        node->m_right = insert(node->m_right, word, line);
        node->m_right->m_parent = node;
    }
    else if (node->m_word == word)
    {
        // Check if already in tree, if so increment word
        // count and add line number to vector
        node->m_wordCount++;
        node->m_lineNumbers.push_back(line);
    }

    // If the given key is smaller than node's key then go to left subtree
    else
    {
        node->m_left = insert(node->m_left,word,line);
        node->m_left->m_parent = node;
    }

    return node;
}

void WTree::insert(string word, int line)
{
    // Invoking Insert() function and passing root node and given key
    m_root = insert(m_root, word,line);
}

void WTree::printTreeInOrder(wTreeNode * node)
{
    // Stop printing if no node found
    if (node == NULL)
        return;

    // Get the smallest key first which is in the left subtree
    printTreeInOrder(node->m_left);

    // Print the key, word count, and line numbers
    cout << node->m_word << " occurs " << node->m_wordCount + 1 << " times, on line(s) ";

     // for loop to print out the vector
    for (int i=0; i < node->m_lineNumbers.size(); i++)
    {
        cout << node->m_lineNumbers[i] << " \n";

        // Print a comma and space after each element, except the last one
        if (i != node->m_lineNumbers.size() - 1)
        {
            cout << " ,";
        }
    }

    cout << endl;

    // Continue to the greatest key which is in the right subtree
    printTreeInOrder(node->m_right);
}

void WTree::printTreeInOrder()
{
    printTreeInOrder(m_root);
    cout << endl;
}

string WTree::fWord(wTreeNode * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->m_left == NULL)
    {
        return node->m_word;
    }
    else
    {
        return fWord(node->m_left);
    }
}

string WTree::fWord()
{
    return fWord(m_root);
}

string WTree::lWord(wTreeNode * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->m_right == NULL)
    {
        return node->m_word;
    }
    else
    {
        return lWord(node->m_right);
    }
}

string WTree::lWord()
{
    return lWord(m_root);
}

int WTree::countUniqueWords()
{
    return countUniqueWords(m_root);
}

int WTree::countUniqueWords(wTreeNode * node)
{
    if (node == NULL)
        return 0;

    return 1 + countUniqueWords(node->m_left) + countUniqueWords(node->m_right);
}

int WTree::countWords()
{
    return countWords(m_root);
}

int WTree::countWords(wTreeNode * node)
{
   if (node == NULL)
        return 0;

    ifstream file("test.txt");
    int counttt = 0;
    string word;

    while (file >> word)
    {
        ++counttt;
    }

    return counttt;

}



