#include <cstdio>
#include <iostream>
#include <chrono> 
using namespace std::chrono; 

/*
Quick Sort Technique

1. Divide & Conquer
2. Not Stable
3. In-Place
4. Recursive

Time complexity 
O(nlogn) - Average case



*/

//l = left index
//r = right index
void swap(int a[], int l, int r)
{
  int temp = a[l];
  a[l] = a[r];
  a[r] = temp;
}

//st - starting index of the array or sub array
//end - end index
// return the pivot element.
//This functions will partition the array by selecting a pivot //element. The end index element is selected as the pivot element. All //elements less than pivot will be left of pivot and all elements //greater than pivot will be arranged right of pivot
int partition (int a[], int st, int end)
{

  int pivot = a[end]; // Take the element in the end index as pivot

  int pIndex = st; //pIndex is the place, the pivot will finally reside

  for(int i = st; i < end; ++i)
  {
    if(a[i] <= pivot)
    {
      swap(a, i, pIndex);
      pIndex++;
    }
  }
  swap(a, pIndex, end);
  return pIndex;
}

int rangeRandomAlg2 (int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}

int randomised_partition(int a[], int st, int end)
{
  //biased towards lower order, but ok for this case
  int pIndex = (rand()%((end-st) + 1)) + st; 

  //Non biased version.
  //int pIndex = rangeRandomAlg2(st, end);
  
  //printf("random index - %d\n", pIndex);
  swap(a, pIndex, end); //swap the enc index and the new random pivot

  return(partition(a,st,end));


}
void quick_sort(int a[], int st, int end)
{
  if(st < end)
  {
   int pivot = randomised_partition (a, st, end);
   //int pivot = partition(a, st ,end);
    quick_sort(a, st, pivot-1);
    quick_sort(a, pivot+1, end);
  }
}

//Samples     Randomised Partition     Non-randomised partition
// 100000     24976023ns             38073154ns
// 10000       1790470ns              2123028ns
// 1000         141128ns               172254ns
// 100           11458ns                12838ns
//  10            1603ns                 2197ns
//  1              616ns                  673ns


int main() {
  //int a[] = {3, 2, 4, 6, 1, 5, 10, 8, 9, 7};
  //Right most index is array length - 1
  int a[100000];
  srand (time(NULL));
  for(int i=0; i<100000; i++)
  {
    a[i] = rand()%(100000) + 1;
  }
  auto start = high_resolution_clock::now(); 
  quick_sort(a, 0, 100000-1);
  auto stop = high_resolution_clock::now();
  // Subtract stop and start timepoints and 
// cast it to required unit. Predefined units 
// are nanoseconds, microseconds, milliseconds, 
// seconds, minutes, hours. Use duration_cast() 
// function. 
auto duration = duration_cast<nanoseconds>(stop - start); 
  
// To get the value of duration use the count() 
// member function on the duration object 
std::cout << "\nTime Taken - "<< duration.count() << std::endl; 
  //for(int i : a)
  //  printf("%d ", i);
}
