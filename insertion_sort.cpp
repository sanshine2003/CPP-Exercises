#include <cstdio>

/*
Insertion Sorting Technique

Input array is divided into sorted and unsorted part. Initially the sorted part consist of only one element at index 0. For each pass, take the first element in the unsorted part and insert it in its appropriate position in the sorted part. The element that is taken out for insertion will create a hole and the sorted part will grow by shifting all the elements greater than the element to be inserted to the right.  

Not the best alogrithm in terms of time complexity, but still better than Bubble and Selection. This is mainly because other than the reverse ordered list (6,5,4,3,2,1) where the complexity is highest, for other type of inputs, the number of iterations needed will be much less compared to Bubble and Selection

Time Complexity Analysis
Best Case:
  For a completely sorted list,
  (n-1) (c1 + c3)
  This will result in an + b
  The complexity will be the highest order in the polynomial, and hence O(n)


Worst Case:
  For a reverse sorted list like (6,5,4,3,2,1),
  = (n-1)(c1+c3) * ((1+2+3+4+...+n-1))c2
  = (n-1)(c1+c3) * (n(n-1)/2)c2
  = an^2 + bn + c where a, b and c are in terms of c1, c2 and c3
   the highest order in the polynomial is n^2 and hence the complexity is O(n^2)


Average case:
  = (n-1)(c1+c3) * (n/2)c2
  = an^2 + bn + c
  = O(n^2)
*/

int insertion_sort (int input[], int n)
{
  //i always represent the unsorted boundary index.
  
  for(int i = 1; i < n; ++i)
  {
    //The following 2 statements take a constant time c1 and will be //run (n-1)*c1 times
    int hole = i;
    int val = input[hole];

    //The loop will be run (n-1) * n(n+1)/2 * c2 for a reverse sorted //list. For the best case of sorted list, This loop will be never //executed. For the average case the loop will be executed (n-1) * //n/2 * c2.
    while(hole > 0 && input[hole-1] > val)
    {//The 2 statements below will take constant time c2
      input[hole] = input[hole-1]; //right shift by 1
      hole = hole - 1;
    }
    //This is constant time c3
    input[hole] = val; //insert the value

  }
  return 0;
}

int main() {
  int a[] = {3, 2, 4, 6, 1, 5};
  insertion_sort(a, 6);
  for(int i : a)
     printf("%d ", i);
}

