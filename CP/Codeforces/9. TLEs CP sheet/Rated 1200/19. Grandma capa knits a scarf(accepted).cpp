// C. Grandma Capa Knits a Scarf

// time limit per test1 second
// memory limit per test256 megabytes

// Grandma Capa has decided to knit a scarf and asked Grandpa Sher to make a pattern for it, a pattern is a string consisting of lowercase English letters. Grandpa Sher wrote a string s of length n. Grandma Capa wants to knit a beautiful scarf, and in her opinion, a beautiful scarf can only be knit from a string that is a palindrome. She wants to change the pattern written by Grandpa Sher, but to avoid offending him, she will choose one lowercase English letter and erase some (at her choice, possibly none or all) occurrences of that letter in string s. She also wants to minimize the number of erased symbols from the pattern. Please help her and find the minimum number of symbols she can erase to make string s a palindrome, or tell her that it's impossible. Notice that she can only erase symbols equal to the one letter she chose. A string is a palindrome if it is the same from the left to the right and from the right to the left. For example, the strings 'kek', 'abacaba', 'r' and 'papicipap' are palindromes, while the strings 'abb' and 'iq' are not.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases. The next 2⋅t lines contain the description of test cases. The description of each test case consists of two lines. The first line of each test case contains a single integer n (1≤n≤105) — the length of the string. The second line of each test case contains the string s consisting of n lowercase English letters. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case print the minimum number of erased symbols required to make the string a palindrome, if it is possible, and −1, if it is impossible.

// Example
// InputCopy
// 5
// 8
// abcaacab
// 6
// xyzxyz
// 4
// abba
// 8
// rprarlap
// 10
// khyyhhyhky

// OutputCopy
// 2
// -1
// 0
// 3
// 2

// Note
// In the first test case, you can choose a letter 'a' and erase its first and last occurrences, you will get a string 'bcaacb', which is a palindrome. You can also choose a letter 'b' and erase all its occurrences, you will get a string 'acaaca', which is a palindrome as well.
// In the second test case, it can be shown that it is impossible to choose a letter and erase some of its occurrences to get a palindrome.
// In the third test case, you don't have to erase any symbols because the string is already a palindrome.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isPalindrome(string s)
{
    int left=0, right=s.size()-1;
    while(left<=right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int ans = n+1;
    for(int i=0; i<26; i++)
    {
        char c = 'a' + i;
        int count = 0;
        int left=0, right=n-1;
        while(left<=right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else if(s[left]==c)
            {
                count++;
                left++;
            }
            else if(s[right]==c)
            {
                count++;
                right--;
            }
            else
            {
                count = n+1;
                break;
            }
        }

        ans = min(ans,count);
    }

    if(ans==n+1) cout << "-1" << endl;
    else cout << ans << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
