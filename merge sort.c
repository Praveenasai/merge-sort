#include<stdio.h>
void merge(int a[], int low, int mid, int high){
    int i=low, j=mid+1;
    int b[high];
    int k=0;
    while(i<=mid && j<=high){
        if(a[i]<a[j]) {
            b[k++]=a[i++];
        }
        else {
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=high){
        b[k++]=a[j++];
    }
    for(int i=low, k=0; i<=high; i++, k++){
        a[i]=b[k];
    }
}
void mergesort(int a[], int low, int high) {
    if(low<high) {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int n=6;
    int a[6]={6,7,4,5,2,8};
    mergesort(a,0,n-1);
    printf("sorted array");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}