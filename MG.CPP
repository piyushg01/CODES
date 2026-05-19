#include<iostream>
using namespace std;

void merge(int arr[] , int st , int mid , int end){
    int temp[100];
    int i = st;
    int j = mid + 1;
    int k = st;

    while(i <= mid && j<=end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = 0 ; i< end ; i++){
        arr[i] = temp[i];
    }

}

void merge_sort(int arr[] , int st , int end){
    if(st < end){
        int mid = st + (end - st)/2;
        merge_sort(arr , st , mid);
        merge_sort(arr , mid+1 , end);
        merge(arr , st , mid , end);
    } 
}

int main(){
    int n ;
    cout<<"Enter the value of n :"<<endl;
    cin>> n;

    int credits[n];
    cout<<"Enter the credits"<<endl;

    for(int i =0 ; i<n  ;i++){
        cin>>credits[i];
    }
    merge_sort(credits, 0 , n-1);
    cout<<endl;

    for(int i =0 ; i<n  ;i++){
        cout<<credits[i];
    }


}