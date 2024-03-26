#include<iostream>
using namespace std;
void create_array(int arr[],int *n){
    cout<<"enter the size of array"<<endl;
    cin>>*n;
    for(int i=0;i<*n;i++){
    cout <<"enter the element of array"<<endl;
    cin>>arr[i];
    }
}
void linear_search(int arr[],int num,int n){
    int i;
    for (i=0;i<n;i++){
        if (arr[i]==num){
            cout<<"item found"<<endl;
            break;
        }
    }
    if (i>=6){
        cout<<"items not found"<<endl;
    }
}
void shell_sort(int arr[],int n){
    int temp,i,j,gap;
    for (gap=n/2; gap>0;gap /=2){
        for(i=gap;i <n;i++){
            temp =arr[i];
            for (j=gap;j >=gap&&arr[j-gap]> temp; gap -=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
void binary_search(int arr[],int num,int beg,int end){
    if(beg > end){
        cout<<"items not found"<<endl;
        return;
    }
    int mid= (beg+end)/2;
    if(arr[mid]==num){
        cout<<"item found"<<endl;
        return;
    }
    if (num < arr[mid]){
        binary_search(arr,num,beg,mid-1);
    }
    if (num > arr[mid]){
        binary_search(arr,num,mid+1,end);
    }
}
int main(){
    int arr[10],n;
    create_array(arr,&n);
    int ch,num;
    while(1){
        cout<<"choose one of the following choice"<<endl;
        cout<<"1.linear search 2. Binary search 3.Exit"<<endl;
        cin>>ch;
        cout<<"enter the number to be searched"<<endl;
        cin>>num;
         switch(ch){
            case 1:
                linear_search(arr,num,n);
                break;
            case 2:
                shell_sort(arr,n);
                binary_search(arr,num,0,n-1);
                break;
            case 3:
                return 0;
                break;
            default:
                cout<<"choose the right choice"<<endl;
                break;
    }
    }
    return 0;
}