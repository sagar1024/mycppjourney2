// B. Alternating Current

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Mad scientist Mike has just finished constructing a new device to search for extraterrestrial intelligence! He was in such a hurry to launch it for the first time that he plugged in the power wires without giving it a proper glance and started experimenting right away. After a while Mike observed that the wires ended up entangled and now have to be untangled again. The device is powered by two wires "plus" and "minus". The wires run along the floor from the wall (on the left) to the device (on the right). Both the wall and the device have two contacts in them on the same level, into which the wires are plugged in some order. The wires are considered entangled if there are one or more places where one wire runs above the other one. For example, the picture below has four such places (top view):

// Mike knows the sequence in which the wires run above each other. Mike also noticed that on the left side, the "plus" wire is always plugged into the top contact (as seen on the picture). He would like to untangle the wires without unplugging them and without moving the device. Determine if it is possible to do that. A wire can be freely moved and stretched on the floor, but cannot be cut. To understand the problem better please read the notes to the test samples.

// Input
// The single line of the input contains a sequence of characters "+" and "-" of length n (1 ≤ n ≤ 100000). The i-th (1 ≤ i ≤ n) position of the sequence contains the character "+", if on the i-th step from the wall the "plus" wire runs above the "minus" wire, and the character "-" otherwise.

// Output
// Print either "Yes" (without the quotes) if the wires can be untangled or "No" (without the quotes) if the wires cannot be untangled.

// Examples
// inputCopy
// -++-
// outputCopy
// Yes
// inputCopy
// +-
// outputCopy
// No
// inputCopy
// ++
// outputCopy
// Yes
// inputCopy
// -
// outputCopy
// No

// Note
// The first testcase corresponds to the picture in the statement. To untangle the wires, one can first move the "plus" wire lower, thus eliminating the two crosses in the middle, and then draw it under the "minus" wire, eliminating also the remaining two crosses.
// In the second testcase the "plus" wire makes one full revolution around the "minus" wire. Thus the wires cannot be untangled:
// In the third testcase the "plus" wire simply runs above the "minus" wire twice in sequence. The wires can be untangled by lifting "plus" and moving it higher:
// In the fourth testcase the "minus" wire runs above the "plus" wire once. The wires cannot be untangled without moving the device itself:

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// void solve()
// {
//     string s;
//     cin >> s;

//     if(s.size()==1)
//     {
//         cout << "No" << endl;
//         return;
//     }

//     stack<char> st;
//     bool allPlus = true;
//     bool allMinus = true;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]=='-')
//         {
//             allPlus &= false;
//         }
//         if(s[i]=='+')
//         {
//             allMinus &= false;
//         }
//         if(!st.empty() && s[i]==st.top())
//         {
//             st.pop();
//         }
//         else
//         {
//             st.push(s[i]);
//         }
//     }

//     if(st.empty())
//     {
//         cout << "Yes" << endl;
//         return;
//     }
//     else if(allMinus || allPlus)
//     {
//         cout << "Yes" << endl;
//         return;
//     }

//     cout << "No" << endl;
//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int countA = 0, countB = 0;

    for(int i = 0; i < n; ++i)
    {
        //Even index in 0-based, odd in 1-based
        if(i % 2 == 0)
        {
            if(s[i] == '-')
            {
                ++countB; //transform '-' to 'B'
            }
            else
            {
                ++countA; //transform '+' to 'A'
            }
        }
        //Odd index in 0-based, even in 1-based
        else
        {
            if(s[i] == '-')
            {
                ++countA; //transform '-' to 'A'
            }
            else
            {
                ++countB; //transform '+' to 'B'
            }
        }
    }

    if(countA == countB) cout << "Yes" << endl;
    else cout << "No" << endl;

    return;
}

int main()
{
    solve();
    return 0;
}
