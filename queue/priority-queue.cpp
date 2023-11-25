#include <iostream>
#define size 5

template <typename T>
class PriorityQueue {
    private:
    T array[size];
    int front, rear;

    public:
    PriorityQueue() {
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
            std::cout << "Queue Overflow: cannot enqueue, queue is full." << std::endl;
        } else {
            rear++;
            array[rear] = item;
        }
    }

    // 
    void dequeue(char c = 'A') {
        if (isEmpty()) std::cout << "Queue Underflow: cannot dequeue, queue is empty." << std::endl;
        else {
            int i;
            int dequeIndex = front;
            T dequeElement = array[front];

            if (c == 'A') { // ascending priority
                for (i=front+1; i <= rear; i++) {
                    if (dequeElement > array[i]) {
                        dequeElement = array[i];
                        dequeIndex = i;
                    }
                }
            } else if (c == 'D') { // descending priority
                for (i=front+1; i <= rear; i++) {
                    if (dequeElement < array[i]) {
                        dequeElement = array[i];
                        dequeIndex = i;
                    }
                }
            } else return;

            for (i=dequeIndex; i < rear; i++) array[i] = array[i+1];
            
            rear--;
        }
    }

    void display() {
        if (isEmpty()) std::cout << "Queue is empty." << std::endl;
        else {
            std::cout << "Queue items: ";
            for (int i=front; i <= rear; i++) std::cout << array[i] << ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
    PriorityQueue <int> pq;

    pq.enqueue(32);
    pq.enqueue(45);
    pq.enqueue(12);
    pq.enqueue(67);
    pq.enqueue(10);
    pq.display();
    pq.dequeue();
    pq.dequeue();
    pq.display();

    return 0;
}