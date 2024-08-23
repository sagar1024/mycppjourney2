// D2. Prefix-Suffix Palindrome (Hard version)

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// This is the hard version of the problem. The difference is the constraint on the sum of lengths of strings and the number of test cases. You can make hacks only if you solve all versions of this task. You are given a string s, consisting of lowercase English letters. Find the longest string, t, which satisfies the following conditions:
// The length of t does not exceed the length of s.
// t is a palindrome.
// There exists two strings a and b (possibly empty), such that t=a+b ( "+" represents concatenation), and a is prefix of s while b is suffix of s.

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤105), the number of test cases. The next t lines each describe a test case. Each test case is a non-empty string s, consisting of lowercase English letters. It is guaranteed that the sum of lengths of strings over all test cases does not exceed 106.

// Output
// For each test case, print the longest string which satisfies the conditions described above. If there exists multiple possible solutions, print any of them.

// Example
// inputCopy
// 5
// a
// abcdfdcecba
// abbaxyzyx
// codeforces
// acbba
// outputCopy
// a
// abcdfdcba
// xyzyx
// c
// abba

// Note

// In the first test, the string s="a" satisfies all conditions.

// In the second test, the string "abcdfdcba" satisfies all conditions, because:
// Its length is 9, which does not exceed the length of the string s, which equals 11.
// It is a palindrome."abcdfdcba" = "abcdfdc" + "ba", and "abcdfdc" is a prefix of s while "ba" is a suffix of s.
// It can be proven that there does not exist a longer string which satisfies the conditions.

// In the fourth test, the string "c" is correct, because "c" = "c" + "" and a or b can be empty. The other possible solution for this test is "s".

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

const long long int N = 1e9+7;

void solve()
{
    string s;
    cin >> s;

    int n;
    cin >> n;

    string ans;
    for(int i=0; i<n; i++)
    {

    }

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
