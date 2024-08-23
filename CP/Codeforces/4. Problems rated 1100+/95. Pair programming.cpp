// C. Pair Programming

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// Monocarp and Polycarp are learning new programming techniques. Now they decided to try pair programming. It's known that they have worked together on the same file for n+m minutes. Every minute exactly one of them made one change to the file. Before they started, there were already k lines written in the file. Every minute exactly one of them does one of two actions: adds a new line to the end of the file or changes one of its lines. Monocarp worked in total for n minutes and performed the sequence of actions [a1,a2,…,an]. If ai=0, then he adds a new line to the end of the file. If ai>0, then he changes the line with the number ai. Monocarp performed actions strictly in this order: a1, then a2, ..., an. Polycarp worked in total for m minutes and performed the sequence of actions [b1,b2,…,bm]. If bj=0, then he adds a new line to the end of the file. If bj>0, then he changes the line with the number bj. Polycarp performed actions strictly in this order: b1, then b2, ..., bm. Restore their common sequence of actions of length n+m such that all actions would be correct — there should be no changes to lines that do not yet exist. Keep in mind that in the common sequence Monocarp's actions should form the subsequence [a1,a2,…,an] and Polycarp's — subsequence [b1,b2,…,bm]. They can replace each other at the computer any number of times. Let's look at an example. Suppose k=3. Monocarp first changed the line with the number 2 and then added a new line (thus, n=2,a=[2,0]). Polycarp first added a new line and then changed the line with the number 5 (thus, m=2,b=[0,5]). Since the initial length of the file was 3, in order for Polycarp to change line number 5 two new lines must be added beforehand. Examples of correct sequences of changes, in this case, would be [0,2,0,5] and [2,0,0,5]. Changes [0,0,5,2] (wrong order of actions) and [0,5,2,0] (line 5 cannot be edited yet) are not correct.

// Input
// The first line contains an integer t (1≤t≤1000). Then t test cases follow. Before each test case, there is an empty line. Each test case contains three lines. The first line contains three integers k, n, m (0≤k≤100, 1≤n,m≤100) — the initial number of lines in file and lengths of Monocarp's and Polycarp's sequences of changes respectively. The second line contains n integers a1,a2,…,an (0≤ai≤300). The third line contains m integers b1,b2,…,bm (0≤bj≤300).

// Output
// For each test case print any correct common sequence of Monocarp's and Polycarp's actions of length n+m or -1 if such sequence doesn't exist.

// Example
// inputCopy
// 5

// 3 2 2
// 2 0
// 0 5

// 4 3 2
// 2 0 5
// 0 6

// 0 2 2
// 1 0
// 2 3

// 5 4 4
// 6 0 8 0
// 0 7 0 9

// 5 4 1
// 8 7 8 0
// 0

// outputCopy
// 2 0 0 5 
// 0 2 0 6 5 
// -1
// 0 6 0 7 0 8 0 9
// -1

