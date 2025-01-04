#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[], int size) {
    for(int i=0; i<size - 1; i++) {
        int min_idx = i;
        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void bubble_sort(int arr[], int size) {
    int swapped = 0;

    for(int i = 1; i < size; i++) {
        for(int j=0; j < size - i; j++) {
            if(arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
            swapped = 1;
        }
        if(!swapped) break;
    }
}

void insertion_sort(int arr[], int size) {
    int current_value, pos;
    for(int i = 1; i < size; i++) {
        current_value = arr[i];
        pos = i;
        while(pos > 0 && arr[pos - 1] > current_value) {
            arr[pos] = arr[pos - 1];
            pos = pos - 1;
        }
        arr[pos] = current_value;
    }
}
int main(){
    int arr[5] = {10, 5, 6, 3, 15};
    int arr2[5] = {10, 5, 6, 3, 15};
    int arr3[5] = {10, 5, 6, 3, 15};
    selection_sort(arr, 5);
    bubble_sort(arr2, 5);
    insertion_sort(arr3, 5 );
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    for(int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;
    
    for(int i = 0; i < 5; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}