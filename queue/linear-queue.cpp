#include <iostream>
#define size 5

template <typename T>
class LinearQueue {
    private:
    T array[size];
    int front, rear;
    
    public:
    LinearQueue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        if (rear < front) return true;
        else return false;
    }

    bool isFull() {
        if (rear == size-1) return true;
        else return false;
    }

    void enqueue(T item) {
        if (isFull()) {
            std::cout << "Linear Queue Overflow: cannot enqueue, queue is full." << std::endl;
        } else {
            rear++;
            array[rear] = item;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Linear Queue Underflow: cannot dequeue, queue is empty." << std::endl;
        } else {
            front++;
        }
    }

    T frontItem() {
        if (isEmpty()) std::cout << "Linear Queue is empty." << std::endl;
        else {
            return array[front];
        }
    }
};

int main() {
    LinearQueue <int> lq;

    lq.dequeue();
    lq.enqueue(20);
    lq.enqueue(30);
    lq.dequeue();
    lq.enqueue(45);

    return 0;
}