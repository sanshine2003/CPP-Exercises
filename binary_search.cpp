#include <cstdio>

using namespace std;


int binary_search(int a[], int n, int input)
{
  int st = 0, end = n-1; 
  int mid;
  
  while (st <= end)
  {
    mid = (st + end)/2;
    printf("mid : %d, end : %d\n", mid, end);
    if(a[mid] == input)
      return mid;

    if (input < a[mid])
      end = mid - 1;
    else
      st = mid + 1;
  }

  return -1;

}

int bs_first_occurence(int a[], int n, int input)
{
  int st = 0, end = n-1; 
  int mid, first = -1;
  
  while (st <= end)
  {
    mid = (st + end)/2;
    printf("st: %d, mid : %d, end : %d\n",st, mid, end);
    if(a[mid] == input)
    {
      first = mid;
      end = mid - 1;
    }
    else if (input < a[mid])
      end = mid - 1;
    else
      st = mid + 1;
  }

  return first;

}

int bs_last_occurence(int a[], int n, int input)
{
  int st = 0, end = n-1; 
  int mid, last = -1;
  
  while (st <= end)
  {
    mid = (st + end)/2;
    printf("st: %d, mid : %d, end : %d\n",st, mid, end);
    if(a[mid] == input)
    {
      last = mid;
      st = mid + 1;
    }
    else if (input < a[mid])
      end = mid - 1;
    else
      st = mid + 1;
  }

  return last;
}

int find_count_in_sorted_array(int a[], int n, int input)
{
  int first = bs_first_occurence(a, n, input);
  int last = bs_last_occurence(a, n , input);
  return (last - first + 1);
}

int main ()
{
  int a[] = {2, 4, 4, 5, 5, 11, 12, 14, 14, 15, 18};
  int i = bs_first_occurence(a, 11, 14);
  int j = bs_last_occurence(a,11,14);
  if(i >= 0 && j >= 0)
    printf("Binary Search: Found at first index %d and last index %d\n", i,j);
  else
    printf("Binary Search: Not Found\n");
  
  int count = find_count_in_sorted_array(a, 11, 5);
  if(count > 0) 
    printf("Number exist %d times", count);
  else
    printf("Number is not found");

  return 0;

}
