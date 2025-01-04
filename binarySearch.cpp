#include <iostream>
using namespace std;

int binary_search_loop(int arr[], int first, int last, int target) {
    int mid;
    
    while(first <= last) {
        mid = (first + last) / 2;
        if (arr[mid] == target) 
            return mid;
        else if (target > arr[mid])
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int binary_search_recursive(int arr[], int first, int last, int target) {
    if (first > last) 
        return -1;

    int mid = (first + last) / 2;
    if(arr[mid] == target) return mid;
    else if (target > arr[mid]) return binary_search_recursive(arr, mid+1, last, target);
    else return binary_search_recursive(arr, first, mid-1, target);
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << binary_search_loop(arr, 0, 4, 3) << endl;
    cout << binary_search_recursive(arr, 0, 4, 3) << endl;
    return 0;
}