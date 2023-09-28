#include <cstdio>
#include <cstring>


/*Bubble Sort*/
#define STR_LEN 64
void sort_array(char a[], int aLen)
{
  int outer, inner, temp;

  for (outer=0; outer<aLen; outer++)
  {
    for(inner=outer+1; inner<aLen; inner++)
    {
      if(a[outer] > a[inner])
      {
        temp = a[outer];
        a[outer] = a[inner];
        a[inner] = temp;
      }
    }
  }
}


int main (int argc , char **argv)
{
  char str[STR_LEN];
  int len;
  printf("Enter a string - ");
  fgets(str, STR_LEN,stdin);
  len = strlen(str);
  printf("\n\n");

  sort_array(str, len);

  puts("sorted string - ");
  printf("%s", str);

  return 0;
}
