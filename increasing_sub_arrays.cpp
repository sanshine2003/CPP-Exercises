/*
Count the number of strictly increasing sub-arrays in an array.

Sub-array minimum size is 2
Array elements must be consecutive to be a sub-array and inherently maintains the order of the elements

input
a[] - {1,2,4,4,5}
output
{1,2,4}, {1,2}, {2,4}, {4,5}

*/



#include <cstdio>

#define MAX_SUB_ARRAY_SIZE 3

void print_sub_array(int a[], int start, int end)
{
  for (int i = start; i < end; i++)
  {
    printf ("%d,", a[i]);
  }
  printf("%d\n", a[end]);
}


void print_sub_arrays(int a[], int len)
{
  int i, j;


  for(i = 0; i < len; i++ )
  {
    for(j=i; j<len; j++)
    {
      if((j - i) >= (MAX_SUB_ARRAY_SIZE-1))
        print_sub_array(a, i, j);
    }
  }
}

int getCount(int a[], int aLen)
{
  int count = 0;

  int len = 1, pf = 0, i, pr_st=0;

  for( i = 1; i < aLen; i++)
  {
    if(a[i] > a[i-1])
    {
      count += len;
      len++;
      if(pf == 0)
         pr_st = i -1;
      pf = 1;
    }
    else
    {
      if(pf ==1)
      {
        printf("printing all sub-arrays between %d and %d\n", a[pr_st], a[i]);
        print_sub_arrays(&a[pr_st], i - pr_st);
        pf = 0;
      }
      len = 1;
    }
  }

  if(pf ==1)
  {
    print_sub_arrays(&a[pr_st], i - pr_st);
    pf = 1;
  }

  return count;
}

int main(int argc, char **argv)
{
  int a[] = {1,2,2,1,3,4,5,6,7};

  int res = getCount(a, 9);

  printf("Number of strictly increasing arrays - %d", res);

  return 0;
}
