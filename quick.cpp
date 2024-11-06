#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int partitionDeterministic(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortDeterministic(int arr[], int low, int high) {
    if (low<high) {
        int pIdx = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pIdx-1);
        quickSortDeterministic(arr, pIdx+1, high);
    }
}

int partitionRandomized(int arr[], int low, int high) {
    int pIdx = low + rand() % (high-low+1);
    swap(arr[pIdx], arr[high]);

    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortRandomized(int arr[], int low, int high) {
    if (low<high) {
        int pIdx = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pIdx-1);
        quickSortRandomized(arr, pIdx+1, high);
    }
}

int main() {
    int n;
    cout<<"Enter the numer of elements in array: ";
    cin>>n;
    int arr[n];
    int arr2[n];
    cout<<"Enter Elements : "<<endl;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        arr2[i] = arr[i];
    }

    cout<<"Original array : "<<endl;
    printArray(arr, n);

    quickSortDeterministic(arr,0,n-1);
    
    cout<<"Sorted array (Deterministic) : "<<endl;
    printArray(arr, n);

    cout<<"Original array : "<<endl;
    printArray(arr2, n);

    quickSortRandomized(arr2,0,n-1);
    
    cout<<"Sorted array (Randomized) : "<<endl;
    printArray(arr2, n);

    return 0;
}

/*
Enter the numer of elements in array: 6
Enter Elements : 
6
3
9
8
2
5
Original array : 
6       3       9       8       2       5
Sorted array (Deterministic) : 
2       3       5       6       8       9
Original array : 
6       3       9       8       2       5
Sorted array (Randomized) : 
2       3       5       6       8       9
*/