#define size 3

template <typename T>
class StaticStack {
    private:
    T array[size];
    int peak;

    public:
    StaticStack() {
        peak = -1;
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