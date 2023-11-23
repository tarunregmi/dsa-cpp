#include <iostream>

template <typename T>
class AutoStack {
    private:
    T* array;
    int size, rate, peak;

    public:
    AutoStack() {
        size = 5;
        rate = 5;
        peak = -1;
        array = new T[size];
    }

    ~AutoStack() {
        delete[] array;
    }

    bool isEmpty() {
        return peak == -1 ? true : false;
    }

    bool isFull() {
        return peak == size-1 ? true : false;
    }

    void push(T item) {
        if (isFull()) {
            // if the stack is full, increase its size by <rate>
            size += rate;
            T* newArray = new T[size];

            // copy items from the old array to the new array
            for (int i=0; i <= peak; i++) newArray[i] = array[i];

            delete[] array;
            array = newArray;
        }
        peak++;
        array[peak] = item;
    }

    T pop() {
        if (isEmpty()) std::cout << "Stack Underflow: cannot pop, stack is empty." << std::endl;
        else {
            peak--;
            return array[peak+1];
        }
    }

    T top() {
        if (isEmpty()) std::cout << "stack is empty." << std::endl;
        else return array[peak];
    }
};