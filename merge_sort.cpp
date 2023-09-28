#include <cstdio>

/*
Recursive Merge Sort

Properties:
1. Recursive
2. Not in-place
3. Stable algorithm
    If there is a list of location points(x,y) like below
    (4, 2), (2,5), (2,3), (1,2)
    and we want to sort them with x as key. Then there are 2 elements with same key x=2. In this case, we want the relative order in the input to be maintained. Means the output should have (2,5) before (2,3).
4. Divide and Conquer type

Time Complexity
  O(nlogn)

Space Complexity
  O(n)

*/

// l = left most index of the array
// m = Relative mid point of the array
// r = Right most index of the array

int merge (int a[], int l, int m, int r)
{
  //Deduce the array subarray lengths
  int lLA = (m - l) + 1 ; //Left Array length
  int lRA = r - m;        //Right Array length

  //create temporary arrays for left and right
  int L[lLA], R[lRA];

  //Copy the content of a[] into right and left arrays according to deduced lengths

  for(int i = 0; i < lLA; ++i)
    L[i] = a[l+i];

  for(int i =0; i < lRA; ++i)
    R[i] = a[m+1+i];

  //We now have contents of a into 2 sub arrays
  //Merge the 2 sub arrays into a by sorting them

  int iL=0, iR=0, iA=l; //initial indices for all 3 arrays
  while(iL < lLA && iR < lRA)
  {
    if(L[iL] <= R[iR])
    {
      a[iA] = L[iL];
      iL++;
    }
    else
    {
      a[iA] = R[iR];
      iR++;
    }
    iA++;
  }

  //There will be left overs in either one of the subarrays that needs to be copied to a.
  while(iL < lLA)
  {
    a[iA] = L[iL];
    iA++;
    iL++;
  }

  while(iR < lRA)
  {
    a[iA] = R[iR];
    iA++;
    iR++;
  }

  return 0;

}

// l = left most index of the array
// r = Right most index of the array
int merge_sort(int a[], int l, int r)
{
  int m;
  if(l < r)
  {
    m = (l+r-1)/2;
    merge_sort(a, l, m); //Sort the left sub array
    merge_sort(a, m+1, r); // Sort the right sub array

    merge(a, l, m , r);

  }
  return 0;
}

int main() {
  int a[] = {3, 2, 4, 6, 1, 5, 10, 8, 9, 7};
  //Right most index is array length - 1
  merge_sort(a, 0, 9);
  for(int i : a)
     printf("%d ", i);
}
