#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

int length=0;

void swap(double *x, double *y);
void quicksort(double array[]);
void quicksort_recursion(double array[], int low, int high);
int partition(double array[], int low, int high);
void comparision(double arr[]);

void merge_sort(double a[]);
void merge_sort_recursion(double a[], int l, int r);
void merge_sorted_arrays(double a[], int l, int m, int r);

int main()
{  
    FILE *fptr;
    if((fptr= fopen("input.txt","r"))==NULL){
        printf("error! file not found");
        exit(1);
    }
    fscanf(fptr,"%d",&length);
    double a[length];
    double b[length];
     for(int i=0;i<length;i++){
            fscanf(fptr,"%lf",&a[i]);
            b[i]=a[i];
        }
    fclose(fptr);
    
    //calling quicksort
    quicksort(a);
    
    //writing into quicksort.txt
    FILE *f1;
    if((f1=fopen("sd0133_quick.txt","w+"))==NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    for (int i = 0; i < length; i++){
        fprintf(f1,"%lf\n",a[i]);
    }
    printf("Succesfully written to quicksort.txt");
    fclose(f1);
    
    //printing array sorted by quicksort
    printf("\nAfter quicksort\n");
    for (int i = 0; i < length; i++)
    printf("%lf\t",a[i]);
    printf("\n");
    
    //comparing elements sorted by quicksort
    comparision(a);
    
    //calling merge sort
    merge_sort(b);
    
    //writing into mergesort.txt
    FILE *f2;
    if((f2=fopen("sd0133_merge.txt","w+"))==NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    for (int i = 0; i < length; i++){
        fprintf(f2,"%lf\n",b[i]);
    }
    printf("Succesfully written to mergesort.txt");
    fclose(f2);
    
    //printing array sorted by mergesort
    printf("\nAfter mergesort\n");
    for (int i = 0; i < length; i++)
    printf("%lf \t", b[i]);
    printf("\n");

    //comparing elements sorted by quicksort
    comparision(b);

    return 0;
}
//Comparision
void comparision(double arr[])
{
    int comparision_count=0;
    printf("comparision with condition a[i]<=a[i+1]\n");
    for(int i=0;i<length-1;i++)
    {
       
        bool c=(arr[i]<=arr[i+1])?true:false;
        printf("%d\t",c);
        comparision_count++;
    }
    printf("\nnumber of comparisions are %d\n\n",comparision_count);
}

//Swap Function
void swap(double *x, double *y)
{
  double temp = *x;
  *x = *y;
  *y = temp;
}

//Quicksort function
void quicksort(double array[])
{
  srand(time(NULL));
  quicksort_recursion(array, 0, length - 1);
}
void quicksort_recursion(double array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(array, low, high);

    quicksort_recursion(array, low, pivot_index - 1);

    quicksort_recursion(array, pivot_index + 1, high);
  }
}

int partition(double array[], int low, int high)
{
  int pivot_index = low + (rand() % (high - low));
  if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);
  int pivot_value = array[high];
  int i = low; 
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);
  return i;
}

//Mergesort
void merge_sort(double a[])
{
  merge_sort_recursion(a, 0, length - 1);
}
void merge_sort_recursion(double a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}
void merge_sorted_arrays(double a[], int l, int m, int r)
{
  
  int left_length = m - l + 1;
  int right_length = r - m;
  double temp_left[left_length];
  double temp_right[right_length];
  int i, j, k;

  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }  
}
