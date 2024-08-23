// A. Double Cola

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola" drink vending machine; there are no other people in the queue. The first one in the queue (Sheldon) buys a can, drinks it and doubles! The resulting two Sheldons go to the end of the queue. Then the next in the queue (Leonard) buys a can, drinks it and gets to the end of the queue as two Leonards, and so on. This process continues ad infinitum. For example, Penny drinks the third can of cola and the queue will look like this: Rajesh, Howard, Sheldon, Sheldon, Leonard, Leonard, Penny, Penny. Write a program that will print the name of a man who will drink the n-th can. Note that in the very beginning the queue looks like that: Sheldon, Leonard, Penny, Rajesh, Howard. The first person is Sheldon.

// Input
// The input data consist of a single integer n (1 ≤ n ≤ 109). It is guaranteed that the pretests check the spelling of all the five names, that is, that they contain all the five possible answers.

// Output
// Print the single line — the name of the person who drinks the n-th can of cola. The cans are numbered starting from 1. Please note that you should spell the names like this: "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" (without the quotes). In that order precisely the friends are in the queue initially.

// Examples
// inputCopy
// 1
// outputCopy
// Sheldon
// inputCopy
// 6
// outputCopy
// Sheldon
// inputCopy
// 1802
// outputCopy
// Penny

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Input
    //Index of the person in the queue
    long long int n;
    cin >> n;

    //MAIN logic
    int currPosition = 1;

    while(n>currPosition*5)
    {
        currPosition = currPosition*2;
    }

    //Index of the person
    int index = (n-1)/currPosition + 1;

    //Output
    if(index==1)
    {
        cout << "Sheldon" << endl;
    }
    else if(index==2)
    {
        cout << "Leonard" << endl;
    }
    else if(index==3)
    {
        cout << "Penny" << endl;
    }
    else if(index==4)
    {
        cout << "Rajesh" << endl;
    }
    else
    {
        cout << "Howard" << endl;
    }

    return 0;
}
