#include <cstdio>

/*
Circular rotated sorted Arrays.
No duplicates - Pre condition
Pivot element has both previous and next element greater than itself. Pivot is the point in which the array is rotated. And the pivot_index=number of rotations
*/


int find_rotate_count(int a[], int n)
{
  int low = 0, high = n -1;

  while(low <= high)
  {
   
    if(a[low] <= a[high])
    {
      //Array is already sorted and not rotated at this point. Return //low
      return low;
    }
    int mid = (low + high) / 2;
    int prev = (mid + n - 1) % n; //modulo n will ensure rotation
    int next = (mid + 1) % n;
    if(a[mid] <= a[prev] && a[mid] <= a[next]) //This is  the pivot
      return mid;

    if(a[mid] >= a[low]) //Everything left of mid is sorted. Discard
      low = mid + 1;
    else if (a[high] >= a[mid] ) //Everything right of mid is sorted.
      high = mid - 1;
  }
  return -1;
}

int main ()
{
  int a[] = {14,15,18,2, 3, 4, 5, 6, 11, 12, 13};
  
  int count = find_rotate_count(a, 11);
  if(count >= 0) 
    printf("Array rotated %d times\n", count);
  else
    printf("Invalid Input\n");

  return 0;

}
