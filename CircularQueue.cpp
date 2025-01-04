#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;
    public:
    Queue(int _size=5) {
        size = _size;
        arr = new int[size];
        front = rear = -1;
    }
    Queue(Queue& q) {
        size = q.size;
        arr = new int[size];
        front = q.front;
        rear = q.rear;

        if (rear>=front) {
            for(int i=front; i<rear; i++) {
                arr[i] = q.arr[i];
            } 
        } else {
                for (int i = front; i < size; i++) {
                    arr[i] = q.arr[i];
                }
                for (int i = 0; i <= rear; i++) {
                    arr[i] = q.arr[i];
                }
        }
    }

    Queue& operator=(Queue& q) {
        if (this == &q) return *this;
        
        delete[] arr;
        size = q.size;
        arr = new int[size];
        front = q.front;
        rear = q.rear;

        if (rear>=front) {
            for(int i=front; i<rear; i++) {
                arr[i] = q.arr[i];
            } 
        } else {
                for (int i = front; i < size; i++) {
                    arr[i] = q.arr[i];
                }
                for (int i = 0; i <= rear; i++) {
                    arr[i] = q.arr[i];
                }
        }
        return *this;
    }
    ~Queue() {
        delete[] arr;
    }
    int isFull() {
        return (front == 0 && rear == size - 1) || front == rear + 1;
    }
    int isEmpty() {
        return front == -1;
    }
    void enqueue(int data) {
        if(isFull())  return;

        if(rear == -1) 
            front = rear = 0;
        else if(rear == size - 1)
            rear = 0;
        else {
            rear++; 
        }
        arr[rear] = data;
    }
    int dequeue(int& d) {
        if(front == -1) return 0;
        d = arr[front];

        if(front == rear) 
            front = rear = -1;
        else if(front == size - 1) 
            front = 0;
        else 
            front++;
        return 1;
        
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};
int main(){
     Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    int x=0;
    if (q.dequeue(x) == 1) 
        cout << "Dequeued: " << x << endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    Queue q2 = q;
    q2.display();
    return 0;
}