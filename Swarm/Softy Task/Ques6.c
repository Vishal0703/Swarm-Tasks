#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<pthread.h>


void merge(int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;


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

void mergeSort(int arr[], long long int l, long long int r)
{
    if (l < r)
    {

        long long int m = l+(r-l)/2;

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


typedef struct _data
{
  int *array;
  long long l,r;

}data;

typedef struct _sort
{
  int *array;
  long long l,m,r;

}sort;

void *merges( void *arg)
{
  data *check;
  check=(data *)arg;

  mergeSort(check->array, check->l, check->r);

  pthread_exit(0);
}

void *merger(void *arg)
{
  sort *check;
  check=(sort *)arg;

  merge(check->array, check->l, check->m, check->r);

  pthread_exit(0);
}



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



  pthread_t tid[4], tidn[2];
  data field[4];
  field[0].l=0;
  field[0].r=(n-1)/4;
  field[1].l=(n-1)/4 +1;
  field[1].r=(n-1)/2;
  field[2].l=(n-1)/2+1;
  field[2].r=3*(n-1)/4;
  field[3].l=3*(n-1)/4+1;
  field[3].r=n-1;

  for(i=0; i<4; i++)
    {
      field[i].array=arr;
      pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid[i], &attr, merges, &field[i]);
    }

 


  for(i=0; i<4; i++)
    {
      pthread_join(tid[i], NULL);
    }

  //merge(arr, 0, (n-1)/4, (n-1)/2);
  //merge(arr, (n-1)/2+1, 3*(n-1)/4, n-1);


  sort channel[2];
    channel[0].l=0;
    channel[0].m=(n-1)/4;
    channel[0].r=(n-1)/2;
    channel[1].l=(n-1)/2+1;
    channel[1].m= 3*(n-1)/4;
    channel[1].r=n-1;

  for(i=0 ;i<2; i++)
    {
      channel[i].array=arr;
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_create(&tidn[i], &attr, merger, &channel[i]);
    }

  for(i=0; i<2; i++)
    {
      pthread_join(tidn[i], NULL);
    }

  merge(arr, 0, (n-1)/2, n-1);
  en=clock();



  double m = ((double)(en -st))/CLOCKS_PER_SEC;

  //printf("\nSorted array is \n");
  // printArray(arr,n);

  printf("Time Taken: %f", m);
  return 0;
}
