class DynamicArray {
private:
    int* arr;
    int capacity;
    int length;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->arr = new int[capacity];
    }

    //return element 
    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(length == capacity){
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        if (length > 0) {
            length--;
            return arr[length];
        }
        return -1;

    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity]; // Create new larger array
        
        // Copy elements from old array to new array
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        
        delete[] arr; // Delete the old array memory
        arr = newArr; // Update pointe

    }

    int getSize() {
        return length;

    }

    int getCapacity() {
        return capacity;
    }
};
