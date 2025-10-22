#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    for(int i=0; i<n-1;i++){
        int min=i;
        for(int j=i+1,j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
            swap_int(&arr[i],&arr[min])
        }
    }
}

void insertion_sort(int *arr, int n)
{
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void bubble_sort(int *arr, int n)
{
    for(int i=1; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                swap_int(&arr[j],&arr[j-1]);
            }
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    int x = l;
    int y = m;
    int z = l;

    while(x<=m && y<=r){
        if(arr[x] <= arr[y]){
            tmp[z]=arr[x];
            x++;
            z++;
        }
        else{
            tmp[z]=arr[y];
            z++;
            y++;
        }
    }
    while(x<=m){
        tmp[z]=arr[x];
        x++;
        z++;
    }
    while(y<=r){
        tmp[z]=arr[y];
        z++;
        y++;
    }
    copy_array(tmp,arr,r-l);
    
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if(l-r<=1){return;}
    int m=(r-l)/2;
    l=mergesort_rec(&arr(0:m-1),tmp,l,m-1);
    r=mergesort_rec(&arr(m:n-1),tmp,m,r);
    merge(arr,tmp,l,m,r);
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}
int partition(int *arr, int l, int r)
{
    int pivot =arr[r];
    int i=l-1;
    for(int j=l; j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap_int(&arr[i],&arr[j]);
        }
    }
    swap_int(&arr[i+1],&arr[r]);
    return i+1;
}

void quick_sort_rec(int *arr, int l, int r)
{
    if (l<r){
        int p=partition(arr,l,r);
        quick_sort_rec(arr,l,p-1);
        quick_sort_rec(arr,p+1,r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}