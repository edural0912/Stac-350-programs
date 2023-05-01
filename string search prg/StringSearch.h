#ifndef STRINGSEARCH_H
#define STRINGSEARCH_H

#include <string>
#include <thread>

using namespace std;

class StringSearch
{
public:
    StringSearch();
    static int brute (string text, string pattern);
    static int boyerMoore (string text, string pattern);
    static int knuthMorrisPratt (string text, string pattern);
    static int* buildLast(int last[], string pattern)
    void lpsCalculation(string pattern, int m, int*lps)


protected:
    static int bruteThread(string text, string pattern, int start, int end);
    static int boyerMooreThread(string text, string pattern, int start, int end);
    static int knuthMorrisPrattThread(string text, string pattern, int start, int end, int* result);

private:
};

#endif // STRINGSEARCH_H
