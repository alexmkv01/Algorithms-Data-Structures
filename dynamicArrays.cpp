#include <iostream>

class DynamicArray {

    public:
        // attributes
        int* arr; // pointer to an array
        int length; // number of actual elements
        int capacity; // total available capacity

        // constructor
        DynamicArray(int capacity) {
            // will initialize an empty array with a capacity of capacity, where capacity > 0.
            this->capacity = capacity;
            this->length = 0;
            this->arr = new int[capacity]; 
        }

        // deconstructor
        ~DynamicArray() {
            delete[] arr;
        }

        // ----------------------------------- METHODS ----------------------------------- 
        int get(int i) {
            // will return the element at index i. Assume that index i is valid.
            return arr[i];
        }
        void set(int i, int n) {
            // will set the element at index i to n. Assume that index i is valid.
            arr[i] = n;
            length += 1;
        }
        void pushback(int n) {
            // will push the element n to the end of the array.
            if (length == capacity){
                resize();
            }
            arr[length] = n;
            length++;
        }
        int popback() {
            // will pop and return the element at the end of the array. Assume that the array is non-empty.
            if (length > 0){
                length --;
            }
            return arr[length];
        }
        void resize() {
            // double the capacity
            capacity *= 2;
            int *newArr = new int[capacity];

            // copy the existing elements
            for (int i=0; i<length; i++){
                newArr[i] = arr[i];
            }

            // remove previous array
            delete[] arr;
            // new arr with the elements copied over and doubled capacity
            arr = newArr;
    
        }
        int getSize() {
            return length;
        }
        int getCapacity() {
            return capacity;
        }
};

int main(){

    DynamicArray myArr(1);
    
    int first = myArr.get(0);
    myArr.pushback(10);
    myArr.pushback(-3);
    myArr.pushback(7);
    myArr.pushback(5);
    myArr.pushback(13);

    std::cout << myArr.getSize() << "\n";
    std::cout << myArr.getCapacity() << "\n";

    return 0;
}
