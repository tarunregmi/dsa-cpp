template <typename T>
class DynamicStack {
    private:
    T* array;
    int peak, size;

    public:
    DynamicStack(int size) {
        this->size = size;
        this->array = new T[this->size];
        this->peak = -1;
    }

    ~DynamicStack() {
        delete[] array;
    }

    bool isEmpty() {
        return (peak == -1 ? true : false);
    }

    bool isFull() {
        return (peak == size-1 ? true : false);
    }

    // return false if stack is full otherwise true
    bool push(T item) {
        if (isFull()) return false;
        peak += 1;
        array[peak] = item;
        return true;
    }

    // return false if stack is empty otherwise return popped item
    T pop() {
        if (isEmpty()) return false;
        peak -= 1;
        return array[peak];
    }

    // return top item without removing
    T top() {
        if (isEmpty()) return false;
        return array[peak];
    }
};