#ifndef WTREENODE_H
#define WTREENODE_H
#include <vector>
#include <string>

using namespace std;

class wTreeNode
{
    public:
        wTreeNode();
        string m_word;
        int m_wordCount = 0;
        int m_uniqueWords;
        vector<int> m_lineNumbers;

        int wordCount;
        wTreeNode * m_left;
        wTreeNode * m_right;
        wTreeNode* m_parent;


    protected:

    private:
};

#endif // WTREENODE_H
