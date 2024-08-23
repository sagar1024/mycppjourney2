// D. Alice, Bob and Candies

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n candies in a row, they are numbered from left to right from 1 to n. The size of the i-th candy is ai. Alice and Bob play an interesting and tasty game: they eat candy. Alice will eat candy from left to right, and Bob — from right to left. The game ends if all the candies are eaten. The process consists of moves. During a move, the player eats one or more sweets from her/his side (Alice eats from the left, Bob — from the right). Alice makes the first move. During the first move, she will eat 1 candy (its size is a1). Then, each successive move the players alternate — that is, Bob makes the second move, then Alice, then again Bob and so on. On each move, a player counts the total size of candies eaten during the current move. Once this number becomes strictly greater than the total size of candies eaten by the other player on their previous move, the current player stops eating and the move ends. In other words, on a move, a player eats the smallest possible number of candies such that the sum of the sizes of candies eaten on this move is strictly greater than the sum of the sizes of candies that the other player ate on the previous move. If there are not enough candies to make a move this way, then the player eats up all the remaining candies and the game ends.

// For example, if n=11 and a=[3,1,4,1,5,9,2,6,5,3,5], then:
// move 1: Alice eats one candy of size 3 and the sequence of candies becomes [1,4,1,5,9,2,6,5,3,5].
// move 2: Alice ate 3 on the previous move, which means Bob must eat 4 or more. Bob eats one candy of size 5 and the sequence of candies becomes [1,4,1,5,9,2,6,5,3].
// move 3: Bob ate 5 on the previous move, which means Alice must eat 6 or more. Alice eats three candies with the total size of 1+4+1=6 and the sequence of candies becomes [5,9,2,6,5,3].
// move 4: Alice ate 6 on the previous move, which means Bob must eat 7 or more. Bob eats two candies with the total size of 3+5=8 and the sequence of candies becomes [5,9,2,6].
// move 5: Bob ate 8 on the previous move, which means Alice must eat 9 or more. Alice eats two candies with the total size of 5+9=14 and the sequence of candies becomes [2,6].
// move 6 (the last): Alice ate 14 on the previous move, which means Bob must eat 15 or more. It is impossible, so Bob eats the two remaining candies and the game ends.

// Print the number of moves in the game and two numbers:

// a — the total size of all sweets eaten by Alice during the game;
// b — the total size of all sweets eaten by Bob during the game.

// Input
// The first line contains an integer t (1≤t≤5000) — the number of test cases in the input. The following are descriptions of the t test cases. Each test case consists of two lines. The first line contains an integer n (1≤n≤1000) — the number of candies. The second line contains a sequence of integers a1,a2,…,an (1≤ai≤1000) — the sizes of candies in the order they are arranged from left to right. It is guaranteed that the sum of the values of n for all sets of input data in a test does not exceed 2⋅105.

// Output
// For each set of input data print three integers — the number of moves in the game and the required values a and b.

// Example
// inputCopy
// 7
// 11
// 3 1 4 1 5 9 2 6 5 3 5
// 1
// 1000
// 3
// 1 1 1
// 13
// 1 2 3 4 5 6 7 8 9 10 11 12 13
// 2
// 2 1
// 6
// 1 1 1 1 1 1
// 7
// 1 1 1 1 1 1 1

// outputCopy
// 6 23 21
// 1 1000 0
// 2 1 2
// 6 45 46
// 2 2 1
// 3 4 2
// 4 4 3

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> candySize(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> candySize[i];
//         }

//         //MAIN logic
//         //Total num of moves made
//         int moveCount = 0;

//         //Alice
//         int left = 0;
//         int currScoreA = 0;
//         int aliceScore = 0;
//         //Bob
//         int right = n-1;
//         int currScoreB = 0;
//         int bobScore = 0;

//         while(!candySize.empty())
//         {
//             while(!candySize.empty() || currScoreA<=currScoreB)
//             {
//                 currScoreA = candySize[left++];
//                 aliceScore += currScoreA;
//             }
//             moveCount++;
//             while(!candySize.empty() || currScoreB<=currScoreA)
//             {
//                 currScoreB = candySize[right--];
//                 bobScore += currScoreB;
//             }
//             moveCount++;
//         }

//         cout << moveCount << " " << aliceScore << " " << bobScore << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> candySize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> candySize[i];
        }

        //Alice starts from the left, Bob from the right
        int left = 0, right = n - 1;
        int aliceScore = 0, bobScore = 0;
        int moves = 0;
        int alicePrev = 0, bobPrev = 0;

        while (left <= right)
        {
            int currScoreA = 0, currScoreB = 0;

            //Alice's turn
            while (left <= right && currScoreA <= bobPrev)
            {
                currScoreA += candySize[left++];
            }
            aliceScore += currScoreA;
            alicePrev = currScoreA;

            if (left <= right)
            {
                moves++;

                //Bob's turn
                while (left <= right && currScoreB <= alicePrev)
                {
                    currScoreB += candySize[right--];
                }
                bobScore += currScoreB;
                bobPrev = currScoreB;

                if (left <= right)
                {
                    moves++;
                }
            }
        }

        cout << moves+1 << " " << aliceScore << " " << bobScore << endl;
    }

    return 0;
}
