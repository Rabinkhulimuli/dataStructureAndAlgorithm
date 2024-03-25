#include <iostream>
using namespace std;

int temp[20];

void create_array(int arr[], int *n) {
    cout << "Enter the size of array: " << endl;
    cin >> *n;
    for (int i = 0; i < *n; i++) {
        cout << "Enter the element of array: " << endl;
        cin >> arr[i];
    }
}

void display(int arr[], int n) {
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int temp[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, k = beg;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    for (i = beg; i <= end; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort(int arr[], int beg, int end) {
    if (beg >= end) {
        return;
    }
    int mid = (beg + end) / 2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, temp, beg, mid, end);
}
int partition(int arr[],int low,int end){
    int pivot=arr[end];
    int i=low-1;
    for (int j=low;j<=end-1;j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap (arr[i+1],arr[end]);
    return i+1;
}
void quick_sort(int arr[],int low,int end){
    if (low<end){
        int pos=partition(arr,low,end);
        quick_sort(arr,low,pos-1);
        quick_sort(arr,pos+1,end);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Call max heapify on the reduced heap
    }
}

int main() {
    int arr[20], n;
    int ch;
    create_array(arr, &n);
    while (1){
        cout<<"choose one of the following choice"<<endl;
        cout<<"1.Merge 2.Quick 3.Heap 4.Exit"<<endl;
        cin>>ch;
        switch (ch){
            case 1:
                 merge_sort(arr, 0, n - 1);
                 display(arr, n);
                 break;
            case 2:
                quick_sort(arr,0,n-1);
                display(arr,n);
                break;
            case 3:
                heap_sort(arr,n);
                display(arr,n);
                break;
            case 4:
                return 0;
                break;
            default:
             cout<<"enter the valid choice"<<endl;
        }
    }
    return 0;
}
