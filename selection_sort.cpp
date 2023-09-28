#include <cstdio>

/*
Selection sort Technique

For an input,

[3, 2, 4, 6, 1, 5]

For each pass select the minimum number in the array and copy it as the element with smallest index of the array. This will be in-place variant of Selection sort. One of the slowest algorithms.
  O(n^2)

Variant : Having an intermediate array to copy the minimum element from each pass. This will increase the space complexity and is propotional to the input array length

Time complexity Analysis

c1(n-1) + c2 (n(n-1)/2) + c3(n-1)
This will finally be a polynomial equation like 
an^2 + bn + c, where a, b and c are constants in terms of c1, c2 and c3

The time complexity in such a polynomial is always the highest order and an^2 is that and thus O(n^2)
*/ 

int selection_sort (int input[], int n)
{
  for (int i = 0; i < n -1; ++i)
  {
    
    int iMin = i; /* THis statement will have constant time c1 and will be run (n-1) * c1 */
//***
//The following loop will run as an arithmetic progression
// (n-1) + (n-2) + (n-3) + ... + 1 = n(n-1)/2
    for (int j = i + 1; j < n; ++j)
    {
      //The following 2 lines will have a constant run time of c2 
      if (input[j] < input[iMin])
        iMin = j;
    }
//***
//The following 3 lines will have a constant running time of c3 and will be run n-1 times. So, (n-1)*c3
    int temp = input[i];
    input[i] = input[iMin];
    input[iMin] = temp;
  } 
  return 0;
}

int main() {
  int a[] = {3, 2, 4, 6, 1, 5};
  selection_sort(a, 6);
  for(int i : a)
     printf("%d ", i);
}
