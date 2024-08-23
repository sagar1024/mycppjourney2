// C. Traffic Light

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You find yourself on an unusual crossroad with a weird traffic light. That traffic light has three possible colors: red (r), yellow (y), green (g). It is known that the traffic light repeats its colors every n seconds and at the i-th second the color si is on. That way, the order of the colors is described by a string. For example, if s="rggry", then the traffic light works as the following: red-green-green-red-yellow-red-green-green-red-yellow- ... and so on. More formally, you are given a string s1,s2,…,sn of length n. At the first second the color s1 is on, at the second — s2, ..., at the n-th second the color sn is on, at the n+1-st second the color s1 is on and so on. You need to cross the road and that can only be done when the green color is on. You know which color is on the traffic light at the moment, but you don't know the current moment of time. You need to find the minimum amount of time in which you are guaranteed to cross the road. You can assume that you cross the road immediately. For example, with s="rggry" and the current color r there are two options: either the green color will be on after 1 second, or after 3. That way, the answer is equal to 3 — that is the number of seconds that we are guaranteed to cross the road, if the current color is r.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. Then the description of the test cases follows. The first line of each test case contains an integer n and a symbol c (1≤n≤2⋅105, c is one of allowed traffic light colors r, y or g)— the length of the string s and the current color of the traffic light. The second line of each test case contains a string s of the length n, consisting of the letters r, y and g. It is guaranteed that the symbol g is in the string s and the symbol c is in the string s. It is guaranteed, that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case output the minimal number of second in which you are guaranteed to cross the road.

// Example
// inputCopy
// 6
// 5 r
// rggry
// 1 g
// g
// 3 r
// rrg
// 5 y
// yrrgy
// 7 r
// rgrgyrg
// 9 y
// rrrgyyygy
// outputCopy
// 3
// 0
// 2
// 4
// 1
// 4

// Note
// The first test case is explained in the statement.
// In the second test case the green color is on so you can cross the road immediately.
// In the third test case, if the red color was on at the second second, then we would wait for the green color for one second, and if the red light was on at the first second, then we would wait for the green light for two seconds.
// In the fourth test case the longest we would wait for the green color is if we wait for it starting from the fifth second.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Length of the string
//         int n;
//         cin >> n;

//         //Current color
//         char c;
//         cin >> c;

//         //Traffic lights
//         string s;
//         cin >> s;

//         //MAIN logic
//         //Modifying the string(cyclic string)
//         string modifiedString = s+s;

//         //Finding the current color
//         //Starting the loop from there
//         int currentColorIndex = 0;
//         while(modifiedString[currentColorIndex]!=c)
//         {
//             currentColorIndex++;
//         }

//         //Calculating the longest time between two greens
//         //Calculating the longest time between current color and green
//         int timeBetweenGs = 0;
//         int longestTime = 0;

//         for(int i=currentColorIndex; i<2*n-currentColorIndex; i++)
//         {
//             if(modifiedString[i]=='g')
//             {
//                 timeBetweenGs = 0;
//             }
//             else if(modifiedString[currentColorIndex]!='g')
//             {
//                 timeBetweenGs++;
//                 longestTime = max(timeBetweenGs, longestTime);
//             }
//         }

//         if(n==1 && c=='g')
//         {
//             cout << 0 << endl;
//             continue;
//         }

//         cout << longestTime << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        int n;
        cin >> n;

        char c;
        cin >> c;

        string s;
        cin >> s;

        //Doubling the string
        s += s;

        //Initialize variables
        int lastGreen = -1;
        int ans = 0;

        //Iterating from right to left
        for (int i=2*n-1; i>=0; i--)
        {
            if (s[i] == 'g')
            {
                lastGreen = i;
            }
            else if (s[i] == c)
            {
                //Here "i" will be decremented faster than "lastGreen"
                //Giving the min time that guarantees road crossing
                ans = max(ans, lastGreen - i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
