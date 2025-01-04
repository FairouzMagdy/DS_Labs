#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* previous;
    int id;
    string name;
};

class Stack{
    Node* tos;

    public:
    Stack() {
        tos = NULL;
    }

    Stack(Stack& s) {
        tos = NULL;
        Node* current = s.tos;

        Stack temp;
        while (current != NULL) {
            temp.push(current->id, current->name);
            current = current->previous;
        }

        current = temp.tos;
        while (current != NULL) {
            push(current->id, current->name);
            current = current->previous;
        }
    }


    ~Stack() {
        while(tos != NULL) {
            Node* current = tos;
            tos = tos->previous;
            delete current;
        }
    }

    void push(int id, string name) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->name = name;
        newNode->previous = NULL;

        if(tos == NULL)
            tos = newNode;
        else {
            newNode->previous = tos;
            tos = newNode;
        }
    }

    int pop(Node& poppedNode ) {
        if (tos == NULL) {
            cout << "Empty Stack" << endl;
            return 0;
        }
        poppedNode.id = tos->id;
        poppedNode.name = tos->name;
        poppedNode.previous = NULL;

        Node* temp = tos;
        tos = tos->previous;
        delete temp;
        return 1;
    }

    void peek() {
        if(tos != NULL)
            cout << tos->id << " " << tos->name <<endl;
        else
            cout << "Stack is empty\n";
    }


    int isEmpty() {
        return tos == NULL;
    }

    int isFull() {
        Node* n = new Node();
        if (n == NULL) return 1;
        delete n;
        return 0;
    }

    Stack& operator=(Stack& s) {
        if(this == &s) return *this;

        while(tos != NULL) {
            Node* current = tos;
            tos = tos->previous;
            delete current;
        }

        Node* current = s.tos;
        Stack temp;
        while(current != NULL) {
            temp.push(current->id, current->name);
            current = current->previous;
        }
        current = temp.tos;
        while(current != NULL) {
            push(current->id, current->name);
            current = current->previous;
        }

        return *this;
    }

    // Stack operator+(const Stack& s) {
    //     Stack res;
    //     Node* current = tos;
    //     while(current != NULL) {
    //         res.push(current->id, current->name);
    //         current = current->previous;
    //     }

    //     current = s.tos;
    //     while(current != NULL) {
    //         res.push(current->id, current->name);
    //         current = current->previous;
    //     }
    //     return res;
    // }

    void display() {
        Node* current = tos;
        while(current != NULL) {
            cout << current->id << " " << current->name<< endl;
            current = current->previous;
        }
    }
};

int main() {
    Stack s1, s2;
    s1.push(10,"a");
    s1.push(20, "b");
    s1.push(30,"c");

    s2.push(5,"d");
    s2.push(8,"e");
    s2.push(15,"f");

    s2 = s1;
    cout<<"********** s1 ************\n";
    s1.display();

    cout<<"********** s2 ************\n";
    s2.display();

    Stack s3 = s1;
    cout<<"********** s3 ***********\n";
    s3.display();

    return 0;
}
