#include <cstdio>

/*
Bubble sort technique

For an input,

[3, 2, 4, 6, 1, 5],

for each pass, each element is compared to the next element and if found greater/less, the element is swapped. This way at the end of each pass the greatest element is always at the highest/lowest index of that pass. Considered one of the slowest.

So, at the end of first pass, the largest element in the array is bubbled up to the highest index of the array. 

When n/2 th pass is complete, one half of the array is sorted and the other half is unsorted. This means for solutions that require partial sorted output from a given input, this could be useful. Like from a array only the greatest 3 numbers are needed, then the result is ready after 3 passes of the input.

In-place sorting.

Time Complexity:

O(n^2)

(n-1) * (n-1) * c
This will be a polynomial Like
cn^2 - 2cn + 1

The highest order is the n^2 and hence the time complexity is o(n^2)


*/

int bubble_sort(int input[], int n)
{
  //loop till n-2 since the idea is to compare with the next element.
  //We dont want to access the array out of bound
  //We need to take care of not making redundant passes if the list is already sorted. So we will have a flag to understand if a swap was performed.
  //At the end of each pass, the last element is already in its place.
  //So the last element is required in the list for next pass.

  bool isSorted = false;
  int lastUnsorted = n-1; 


  while (!isSorted) //This loop will run n-1 times
  {
    isSorted = true;
    for(int i=0; i < lastUnsorted; ++i) //This loop runs n-1 times
    {
      //the following lines has constant time c
      if (input[i] > input[i+1])
      {
        int temp = input[i+1];
        input[i+1] = input[i];
        input[i] = temp;
        isSorted = false;
      }
    }
    lastUnsorted--;
  }
  return 0;
}

int main() {
  int a[] = {3, 2, 4, 6, 1, 5};
  bubble_sort(a, 6);
  for(int i : a)
     printf("%d ", i);
}
