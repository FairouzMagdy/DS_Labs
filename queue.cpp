#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int _data) : data(_data), next(NULL)   {}
};

class Queue {
    Node* front;
    Node* rear;
    public:
    Queue() {
        front = rear = NULL;
    }
    ~Queue() {
        while(front != NULL) {
            Node* current = front;
            front = front->next;
            delete current;
        }
    }
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue(Node& node) {
        if (front == NULL) 
            return 0;
        
        node.data = front->data;

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return 1;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout<<endl;
    }

};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    Node dequeuedNode(0);
    if (q.dequeue(dequeuedNode)) {
        cout  << dequeuedNode.data << endl;
    }

    q.display();
    return 0;
}