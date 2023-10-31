#include <iostream>


void removeEnd(int arr[], int length);
void removeMiddle(int arr[], int i, int length); 

int main(){

    // initialize myArray
    int myArray[] = {1,3,5};

    // access an arbitrary element, where i is the index of the desired value
    int first = myArray[0]; // O(1)

    std::cout << first << "\n";

    int length = sizeof(myArray) / sizeof(myArray[0]);
    // Traversing through array O(n)
    for (int i=0; i<length; i++){
        std::cout << myArray[i];
    }
    
    std::cout << "\n";

    return 0;
}

void removeEnd(int arr[], int length){
    if (length > 0){
        // Overwrite last element with some default value.
        // We would also consider the length to be decreased by 1.
        arr[length-1] = 0; 
    }

}

void removeMiddle(int arr[], int i, int length){

    for (int idx=i+1; length; i++){
        arr[idx-1] = arr[idx]; // decrement each index (shifting each item by one to the left)
    }
}

// Insert n into arr at the next open position.
// Length is the number of 'real' values in arr, and capacity
// is the size (aka memory allocated for the fixed size array).
void insertEnd(int arr[], int n, int length, int capacity) {
    if (length < capacity) {
        arr[length] = n;
    }
}

// Insert n into index i after shifting elements to the right.
// Assuming i is a valid index and arr is not full.
void insertMiddle(int arr[], int i, int n, int length) {
    // Shift starting from the end to i.
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }
    // Insert at i
    arr[i] = n;
}

