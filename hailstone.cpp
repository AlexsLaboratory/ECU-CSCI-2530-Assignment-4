// CSCI 2530
// Assignment: 2
// Author: Alex Lowe
// File: hailstone.cpp
// Tab stops: none


/*
 Reads a positive integer n from the standard input (after giving a suitable
 prompt) and then writes the following information on the standard output:
  1. Print the entire hailstone sequence starting at n separated by spaces.
  2. The length of the hailstone sequence that starts with n.
  3. The largest number in the hailstone sequence.
  4. The longest hailstone sequence that starts with a number from 1 to n. If
  two sequences have the same length only print one of the sequences.
  5. The length of the hailstone sequence from part 4.
  6. A hailstone sequence that starts with a number from 1 to n that contains
  the largest number.
  7. The largest number in the hailstone sequence from part 6.
*/

#include <cstdio>
#include <iostream>

using namespace std;

// next(n) returns the number that follows n in a hailstone sequence.

int next(int n)
{
  if (n % 2 == 0)
  {
    return n / 2;
  }
  else
  {
    return n * 3 + 1;
  }
}

// PrintSequence(n) writes the entire hailstone sequence that starts with n.

void PrintSequence(int n)
{
  if (n == 1)
  {
    cout << n << endl;
  }
  else
  {
    cout << n << " ";
    PrintSequence(next(n));
  }
}

// length(n) returns the length of the hailstone sequence that starts with n.

int length(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    return 1 + length(next(n));
  }
}

// largest(n) returns the largest value in the hailstone sequence that starts
// with n.

int largest(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    int r = largest(next(n));
    return (r > n) ? r : n;
  }
}

// longestStart(n) returns the start value of the longest hailstone sequence
// that starts with an integer from 1 to n.

int longestStart(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    int longStart = longestStart(n - 1);
    if (length(n) > length(longStart))
    {
      return n;
    }
    else
    {
      return longStart;
    }
  }
}

// largestStart(n) returns the start value of the hailstone sequence starting
// with an integer from 1 to n that contains the largest value.

int largestStart(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    int largeStart = largestStart(n - 1);
    if (largest(n) > largest(largeStart))
    {
      return n;
    }
    else
    {
      return largeStart;
    }
  }
}

int main()
{
  printf("What number shall I start with? ");
  int num;
  scanf("%i", &num);
  printf("sequence: ");
  PrintSequence(num);
  printf("length: %i\n", length(num));
  printf("largest: %i\n", largest(num));
  printf("\nFor start values 1 to %i:\n\n", num);
  printf("longest: ");
  PrintSequence(longestStart(num));
  printf("length: %i \n\n", length(longestStart(num)));
  printf("containing largest: ");
  PrintSequence(largestStart(num));
  printf("largest: %i\n", largest(largestStart(num)));

  return 0;
}