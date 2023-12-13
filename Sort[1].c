#include <stdio.h>

void insertionSort(int arr[], int n) {
    /*
    Run a double for loop from i: 1->n-1 and j: i->1;
    run j loop while arr[j]<arr[j-1]{ swap }
    Best Case: o(n);
    Worst Case: O(n^2);
    */
int temp;
for (int i=1;i<n;i++){
    for(int j=i;arr[j]<arr[j-1] && j>0;j--){
        temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
    }    
}
    
    
}
void selectionSort(int arr[], int n){
    /*
    for loop: i->(0,n-1){ find min ( in index) in j->(i+1,n-1) and swap arr[j] and arr[min]}
    All case: O(n^2);
    */
    int temp, min;
    for(int i=0;i<n;i++){
        min=i;
        for( int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
void mergeSort(int arr[], int low,int high){if(low<high){
    /*
    First find L, high-low/2 +low
    mergesort two arrays split from middle.
    then make two new integers and then two new arrays.
    then combine arrays by choosing lowest from two arrays.
    Best Case: O(logn)
    Worst Case: O(nlogn)
    */
   int mid= low+(high-low)/2;
   mergeSort(arr,low,mid);
   mergeSort(arr, mid+1,high);
   int n1=mid-low+1, n2=high-mid;
   int L[n1], R[n2];
   for(int i=0;i<n1;i++){
    L[i]=arr[low+i];
   }
   for(int j=0;j<n2;j++){
    R[j]=arr[mid+j+1];
   }

   int i=0,j=0,k=low;
   while(i<n1 && j<n2){
    if(L[i]<R[j]){
        arr[k]=L[i];
        i++;
    }else{
        arr[k]=R[j];
      j++;  }    k++;
    
   }
   while(i<n1){
    arr[k]=L[i];
    i++;k++;
   }
   while(j<n2){
     arr[k]=R[j];
    j++;k++;
   }
}
}
void quickSort(int arr[], int l, int r){if(l<r){
    int i=l+1,j=r-1;
    int temp;
    int pivot=l;
    while(j>i){
        while(arr[i]<arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }
        if(i<=j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;}
       
    }
    temp=arr[l];
    arr[l]=arr[i];
    arr[i]=temp;
    quickSort(arr,l,i-1);
    quickSort(arr,i+1,r-1);
}

}
int main() {
    // int arr[100];
    // int n;
    // printf("Enter the length of array");
    // scanf("%d",&n);
    // printf("Enter the elements of the unsorted array with space between them");
    // for(int i=0;i<n;i++){
    //     scanf("%d", &arr[i]);

    // }
    int arr[] = {4,8,2,8,1,5};
    // int arr[] ={8,7,6,5,4};
    int n=6;
    

    quickSort(arr,0,n);

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
