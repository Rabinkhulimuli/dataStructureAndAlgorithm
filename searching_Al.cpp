#include<iostream>
using namespace std;

void create_array(int arr[], int *n) {
    cout << "Enter the size of array: ";
    cin >> *n;
    for(int i = 0; i < *n; i++) {
        cout << "Enter the element of array: ";
        cin >> arr[i];
    }
}

void linear_search(int arr[], int num, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            cout << "Item found" << endl;
            return;
        }
    }
    cout << "Item not found" << endl;
}

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void binary_search(int arr[], int num, int beg, int end) {
    if (beg > end) {
        cout << "Item not found" << endl;
        return;
    }
    int mid = (beg + end) / 2;
    if (arr[mid] == num) {
        cout << "Item found" << endl;
        return;
    }
    if (num < arr[mid]) {
        binary_search(arr, num, beg, mid - 1);
    } else {
        binary_search(arr, num, mid + 1, end);
    }
}

int main() {
    int arr[20], n;
    create_array(arr, &n);
    int ch, num;
    while (true) {
        cout << "Choose one of the following options:" << endl;
        cout << "1. Linear search" << endl;
        cout << "2. Binary search" << endl;
        cout << "3. Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the number to be searched: ";
                cin >> num;
                linear_search(arr, num, n);
                break;
            case 2:
                shell_sort(arr, n);
                cout << "Enter the number to be searched: ";
                cin >> num;
                binary_search(arr, num, 0, n - 1);
                break;
            case 3:
                return 0;
            default:
                cout << "Choose the right choice" << endl;
                break;
        }
    }
    return 0;
}
