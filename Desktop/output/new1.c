#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct array{
    int total_size;
    int used_size;
    int *arr;
}array;
void create_arr(array* ptr){         
   printf("Enter the total size:-");
   scanf("%d",&ptr->total_size);
   printf("Enter the used size:-");
   scanf("%d",&ptr->used_size);
   ptr->arr=(int*)malloc(ptr->total_size*sizeof(int));
}

void set_arr(array* ptr){
    for (int i = 0 ; i < ptr->used_size; i++){
        printf("Enter the element of index %d : ",i);
        scanf("%d",&ptr->arr[i]);
    }
}

void show_arr(array* ptr){
    for (int  i = 0; i < ptr->used_size; i++)
    {
        printf("Element of index %d : %d \n",i,ptr->arr[i]);
    }
    
}

void insert_arr(array* ptr){
    ptr->used_size++;
    int len=ptr->used_size;
    int index , value;
    printf("Enter the index:-");
    scanf("%d",&index);
    printf("Enter the value:-");
    scanf("%d",&value);
    for(int i= len-1;i>= index ; i--){
        ptr->arr[i+1]=ptr->arr[i];
    }
    ptr->arr[index]=value;
}

void delete_arr(array* ptr){
    int index;
    printf("Enter the index:-");
    scanf("%d",&index);
    for(int i=index;i<ptr->used_size;i++){
       ptr->arr[i]=ptr->arr[i+1];
    }
    ptr->used_size--;   
}

void update_arr(array* ptr){
    int index , value;
    printf("Enter the index:-");
    scanf("%d",&index);
    printf("Enter the value:-");
    scanf("%d",&value);
    ptr->arr[index]=value;
}

int linsearch(array* ptr){
    int element ;
    printf("Enter the element:-");
    scanf("%d",&element);
    for (int i = 0;i<ptr->used_size; i++){
        if(ptr->arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binsearch(array* ptr){
    int element;
    printf("Enter the  element:-");
    scanf("%d",&element);
    int len=ptr->used_size;
    int low,mid,high;
    low=ptr->arr[0];
    high=ptr->arr[len-1];
    mid=(low+high)/2;
    while(low<=high){
        if(ptr->arr[mid]==element){
            return mid;
        }
        if(mid < element){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

void bubblesort_arr(array* ptr){
    int n =ptr->used_size;
    int temp;

    for(int i = 0 ; i < n -1 ; i++){
        printf("Working on pass number %d \n",i+1);
        for (int j = 0 ; j < n-i-1 ; j++){
            if (ptr->arr[j] > ptr->arr[j+1]){       
              temp=ptr->arr[j];
            ptr->arr[j]=ptr->arr[j+1];
            ptr->arr[j+1]=temp;
            }
        }  
}
}

void insertionSort_arr(array* ptr){
    int n=ptr->used_size;
    int temp , j;
    for (int i = 1; i<= n-1 ; i++)
    {
        temp = ptr->arr[i];
         j=i-1;
         while (j >= 0 && ptr->arr[j] > temp )
         {
            ptr->arr[j+1]=ptr->arr[j];
            j--;
         }
         ptr->arr[j+1]=temp; 

    }
    

}

void selectionsort_arr(array* ptr){
    int n=ptr->used_size;
    int temp , indexofmin;
    for (int i = 0; i < n-1; i++){
      indexofmin = i;
      for(int j = i+1 ; j < n ; j++){
        if(ptr->arr[j] < ptr->arr[indexofmin]){
            indexofmin=j;
        }
      }
      temp=ptr->arr[i];
      ptr->arr[i]=ptr->arr[indexofmin];
      ptr->arr[indexofmin]=temp;
    }

}
int partition(array *ptr, int low, int high) {
    int pivot = ptr->arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do {
        while (i <= high && ptr->arr[i] <= pivot) {
            i++;
        }
        while (j >= low && ptr->arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = ptr->arr[i];
            ptr->arr[i] = ptr->arr[j];
            ptr->arr[j] = temp;
        }
    } while (i < j);

    temp = ptr->arr[low];
    ptr->arr[low] = ptr->arr[j];
    ptr->arr[j] = temp;

    return j;  // Partition index
}

void quickSort_arr(array *ptr, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(ptr, low, high);
        quickSort_arr(ptr, low, partitionIndex - 1);
        quickSort_arr(ptr, partitionIndex + 1, high);
    }
}

void merge(array *ptr, int low, int mid, int high){
    int i , j , k ;
    int B[ptr->used_size];
    i = low;
    k = low;
    j = mid+1;
    while (i <= mid && j <= high)
    {
        if (ptr->arr[i] < ptr->arr[j]){
            B[k] = ptr->arr[i];
            i++;
            k++;
        }else{
            B[k] = ptr->arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        B[k] = ptr->arr[i];
        i++;
        k++;
    }
    while (j <= high){
        B[k] = ptr->arr[j];
        j++;
        k++;
    } 
    
     for (int i = low; i <= high; i++)
    {
        ptr->arr[i] = B[i];
    }
}
void mergesort_arr(array * ptr ,int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergesort_arr(ptr,low,mid);
        mergesort_arr(ptr,mid+1,high);
        merge(ptr,low,mid,high);
}
}
int maximumOf_arr(array *ptr, int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max < ptr->arr[i]) {
            max = ptr->arr[i];
        }
    }
    return max;
}

void countsort_arr(array *ptr, int n) {
    int i, j;
    int max = maximumOf_arr(ptr, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    // initialize count array
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // count occurrences
    for (i = 0; i < n; i++) {
        count[ptr->arr[i]]++;
    }

    // place back sorted values
    i = 0;
    j = 0;
    while (i <= max) {
        if (count[i] > 0) {
            ptr->arr[j] = i;
            count[i]--;
            j++;
        } else {
            i++;
        }
    }

    free(count); // ✅ free memory
}
int main() {
    array marks; 
    create_arr(&marks);
    set_arr(&marks);
    show_arr(&marks);
    //insert_arr(&marks);
    //show_arr(&marks);
   // delete_arr(&marks);
  // update_arr(&marks);
   // show_arr(&marks);

   /*    
   int lin=linsearch(&marks);
   if (lin == -1){
    printf("Element not found");
   }else{
    printf("Element found of index %d ",lin);
   }
    */

   /*
   int bin=binsearch(&marks);
   if (bin == -1){
    printf("Element not found");
   }else{
    printf("Element found of index %d ",bin);
   }
*/
  
  /*
   bubblesort_arr(&marks);
   show_arr(&marks);
   */

/*
selectionsort_arr(&marks);
   show_arr(&marks);
*/

/*
   quickSort_arr(&marks , 0 , marks.used_size-1);
   show_arr(&marks);
   */
  /*
 mergesort_arr(&marks,0,marks.used_size-1);
   show_arr(&marks);
*/

countsort_arr(&marks,marks.used_size);
   show_arr(&marks);
    

    return 0;
}
