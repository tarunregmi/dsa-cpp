#include <iostream>
#define size 7

template <typename T>
class CircularQueue {
    private:
    T array[size];
    int front, rear;

    public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((rear+1) % size == front) return true;
        else return false;
    }

    bool isEmpty() {
        if (front == -1) return true;
        else return false;
    }

    void enqueue(T item) {
        if(isFull()) {
            std::cout << "Circular Queue Overflow: Cannot enqueue, queue is full." << std::endl;
        } else {
            if (isEmpty()) front = 0;
            rear = (rear+1) % size;
            array[rear] = item;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Circular Queue Underflow: Cannot dequeu, queue is empty." << std::endl;
        } else {
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front+1) % size;
            }
        }
    }

    T frontItem() {
        if (isEmpty()) {
            std::cout << "Circular Queue is empty." << std::endl;
        } else {
            return array[front];
        }
    }
};

int main() {
    CircularQueue <char> cq;

    cq.enqueue('A');
    cq.enqueue('B');
    cq.enqueue('C');

    std::cout << cq.frontItem() << std::endl;
    cq.dequeue();
    std::cout << cq.frontItem() << std::endl;

    return 0;
}