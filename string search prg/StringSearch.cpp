#include "StringSearch.h"
#include <string>
#include <thread> 
#include <vector>
using namespace std;

StringSearch::StringSearch()
{
}

// Search for the pattern and return the position
//   where it is found, otherwise return -1

int StringSearch::brute(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int j;
    for (int i=0; i<=(n-m); i++) {
        j = 0;
        while ((j<m)  && (text[i+j] == pattern[j])) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int StringSearch::bruteThread(string text, string pattern, int start, int end)
{
    int n = text.length();
    int m = pattern.length();
    int j;
    for (int i=start; i<=end; i++) {
        j = 0;
        while ((j<m)  && (text[i+j] == pattern[j])) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}


static int* buildLast(int last[], string pattern)
{
    for (int i=0; i<128; i++)
        last[i] = -1;
    for (int i=0; i<pattern.length(); i++)
        last[pattern[i]] = i;
    return last;
}

int StringSearch::boyerMoore(string text, string pattern)
{
    int last[128];
    buildLast(last,pattern);
    int n = text.length();
    int m = pattern.length();

    int i = m -1;
    if (i > n-1) return -1;  // no match if pattern is longer than text

    int j = m-1;
    do {
        if (pattern[j] == text[i])
            if ( j == 0) {
                return i; // match
            }
            else {  // looking-glass technique
                i--;
                j--;
            }
            else {  // character jump technique
                int lastOccurrence = last[text[i]];  // get the last occurrence
                i = i + m - min(j, 1+lastOccurrence);
                j = m -1;
            }
    } while (i <= n-1);
    return -1;
}

int StringSearch::boyerMooreThread(string text, string pattern, int start, int end)
{
    int last[128];
    buildLast(last,pattern);
    int n = text.length();
    int m = pattern.length();

    int i = end - 1;
    if (i > n-1) return -1;  // no match if pattern is longer than text

    int j = m-1;
    do {
        if (pattern[j] == text[i])
            if ( j == 0) {
                return i; // match
            }
            else {  // looking-glass technique
                i--;
                j--;
            }
            else {  // character jump technique
                int lastOccurrence = last[text[i]];  // get the last occurrence
                i = i + m - min(j, 1+lastOccurrence);
                j = m -1;
            }
    } while (i >= start);
    return -1;
}


void lpsCalculation(string pattern, int m, int*lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m){
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int StringSearch::knuthMorrisPratt(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    lpsCalculation(pattern, m, lps);
    int i=0;
    int j=0;
    while ((n-i) >= (m-j)) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m){
            return i-j;
        }
        else if (i<n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return -1;
}

int StringSearch::knuthMorrisPrattThread(string text, string pattern, int start, int end, int* result)
{
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    lpsCalculation(pattern, m, lps);
    int i = start;
    int j = 0;
    while (i <= end && (n - i) >= (m - j)) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            *result = i - j;
            return 0;
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    *result = -1;
    return 0;
}