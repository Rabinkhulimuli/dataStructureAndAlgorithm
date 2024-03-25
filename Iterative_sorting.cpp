#include <iostream>
using namespace std;
void create_array(int arr[],int *n){
    cout<<"enter the size of array"<<endl;
    cin>>*n;
    for(int i=0;i<*n;i++){
    cout <<"enter the element of array"<<endl;
    cin>>arr[i];
    }

}
void display(int arr[], int n) {
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int arr[],int n){
        for (int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        display(arr,n);
    }

void sellection_sort(int arr[],int n){
    int min_index;
    
    for (int i=0;i<n-1;i++){
        min_index=i;
        bool change=false;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                change=true;
                min_index=j;
            }
        }
        if(change){
            swap(arr[i],arr[min_index]);
        }

    }
    display(arr,n);
}
void insertion_sort(int arr[],int n){
    int i,j,key;
    for (i=1;i<n;i++){
        j=i-1;
        key=arr[i];
        while(j >=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    display(arr,n);
}
void shell_sort(int arr[],int n){
    int temp;
    for(int gap =n/2;gap> 0; gap /=2){
         for (int i=gap;i < n; i++){
            temp =arr[i];
            int j;
            for (j=i; j>=gap && arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
         }
    }
    display(arr,n);
}

int main(){

    int arr[10],n;
    create_array(arr,&n);
    int ch;
    while(1){
        cout<<"choose one of the following choice"<<endl;
        cout<<"1. Bubble Sort  2.Sellection Sort 3.Insertion Sort 4.Shell Sort 5.Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                bubble_sort(arr,n);
                break;
            case 2:
                sellection_sort(arr,n);
                break;
            case 3:
                insertion_sort(arr,n);
                break;
            case 4:
                shell_sort(arr,n);
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"choose the right choice"<<endl;
        }
    }
    
    return 0;
}