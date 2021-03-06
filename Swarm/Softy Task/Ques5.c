#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


      int *L, *R;
  L=(int *)malloc(n1*sizeof(int));
  R=(int *)malloc(n2*sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
      free(L);
      free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/*void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d\n", A[i]);
    printf("\n");
}*/

int main()
{
  int *arr;
  int n,i;
  scanf("%d", &n);
  arr=(int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);

  clock_t st, en;

  st=clock();
  mergeSort(arr, 0, n - 1);
  en=clock();

  double m = ((double)(en -st))/CLOCKS_PER_SEC;

  //printf("\nSorted array is \n");
  //printArray(arr,n);

  printf("Time Taken: %f", m);
  return 0;
}
