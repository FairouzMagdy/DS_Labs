#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Node {
    int id;
    string name;
    int age;
    Node* next;
    Node* previous;
};

class LinkedList {
    Node* head;
    Node* tail;
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    LinkedList(LinkedList& ll) {
        head = NULL;
        tail = NULL;

        Node* temp = ll.head;
        while(temp != NULL) {
            append(temp->id, temp->name, temp->age);
            temp = temp->next;
        }
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = NULL;
    }
    void append(int _id, string _name, int _age) {
        if (searchByIdPrv(_id) != NULL) {
            cout << "Duplicate id." << endl;
            return;
        }
        Node* temp = new Node();
        temp->id = _id;
        temp->name = _name;
        temp->age = _age;
        temp->previous = NULL;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->previous = tail;
            tail=temp;

        }
    }
    Node* searchByIdPrv(int id) {
        Node* temp = head;
        while(temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    Node* searchByNamePrv(string name) {
        Node* temp = head;
        while(temp != NULL) {
            if (temp->name == name)
                return temp;

            temp = temp->next;
        }
         return NULL;
    }

    Node searchById(int id) {
        Node res;
        res.id = -1;
        res.next = NULL;
        res.previous = NULL;
        Node* temp = searchByIdPrv(id);
        if (temp) {
            res.id = temp->id;
            res.name = temp->name;
            res.age = temp->age;
        }
        return res;
    }

    Node searchByName(string name) {
        Node res;
        res.id = -1;
        res.next = NULL;
        res.previous = NULL;
        Node* temp = searchByNamePrv(name);
        if(temp) {
            res.id = temp->id;
            res.name = temp->name;
            res.age = temp->age;
        }
        return res;
    }

    void insertAfter(int afterId, int newId, string name, int age) {
        if (searchByIdPrv(newId) != NULL) {
            cout << "Duplicate id." << endl;
            return;
        }

        if(head == NULL) {
            cout << "Can Not insert after " << afterId << "List is empty." << endl;
            return;
        }

        if(head==tail) {
            if(head->id == afterId)
                append(newId, name, age);
            else
                cout << "Node with id " << afterId << " not found" << endl;

            return;
        }

        Node* temp = searchByIdPrv(afterId);
        if (temp == NULL) {
                return;
        }


        Node* newNode = new Node();
        newNode->id = newId;
        newNode->name = name;
        newNode->age = age;
        newNode->next = NULL;
        newNode->previous = NULL;

        if (temp->next)
            temp->next->previous = newNode;


        newNode->next = temp->next;
        temp->next = newNode;
        newNode->previous = temp;

        if (temp == tail)
            tail = newNode;
    }

    void deleteById(int id) {
        Node* temp = searchByIdPrv(id);
        if (temp == NULL) return;

        if (head == tail) {
            head = tail = NULL;
            delete temp;
        } else if(temp == head) {
            head = head->next;
            head->previous = NULL;
            delete temp;
        } else if (temp == tail) {
            tail = tail->previous;
            tail->next = NULL;
            delete temp;
        } else {
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
            delete temp;
        }
    }

    void deleteByName(string name) {
        Node* temp = searchByNamePrv(name);
        if (temp == NULL) return;

        if (head == tail) {
            head = tail = NULL;
            delete temp;
        } else if(temp == head) {
            head = head->next;
            head->previous = NULL;
            delete temp;
        } else if (temp == tail) {
            tail = tail->previous;
            tail->next = NULL;
            delete temp;
        } else {
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
            delete temp;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "Employee: " << temp->id << " Name: " << temp->name << " Age: " << temp->age <<endl;
            temp = temp->next;
        }
    }
    int getCount() {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

void gotoxy(int column, int line);
void textattr(int i);

void drawLineHorizontal(int col, int row, int hLength);
void drawLineVertical(int col, int row, int vLength);
void draw_rectangle(int col, int row, int vLength, int hLength, int color);
void display_menu(char menu[][20], int size, int row, int col, int s);
void displayEmp(Node res);

int main() {
    int s=0,  flag=0;
    char ch;

    int main_row = 10, main_col=10;

    char menu[9][20] = {"New", "Display", "Search By Id",
    "Search By Name","Delete By Id", "Delete BY Name", "Insert", "Count", "Exit"};
    LinkedList ll;

    int id, afterId, age;
    string name;
    Node res;

    do {
        system("cls");

        draw_rectangle(main_row - 2, main_col - 2, 13, 20, 0x70);
        display_menu(menu, 9, main_row, main_col, s);

        ch = _getch();

        switch(ch) {
            case -32: // extended
                ch = _getch();
                switch(ch) {
                    case 71: //home
                       s=0;
                        break;     
                    case 80: //down
                        s++;
                        if (s>8) s=0;
                        break;
                    case 79: //end
                        s=8;
                        flag=1;
                        system("cls");
                        cout << "End Program";
                        break;
                    case 72: //up
                        s--;
                        if (s<0) s=8;
                        break;
                }
                break;
            case 13: // enter
                switch(s) {
                    case 0:
                        system("cls");
                            cout<<"Enter id, name, age of the employee: ";
                            cin>>id>>name>>age;
                            ll.append(id, name, age);
                            break;
                        case 1:
                            system("cls");
                            ll.display();
                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;
                        case 2:
                            system("cls");
                            cout << "Enter ID: ";
                            cin >> id;
                            res = ll.searchById(id);
                            displayEmp(res);

                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;
                        case 3:
                            system("cls");
                            cout << "Enter Name: ";
                            cin>>name;
                            res = ll.searchByName(name);
                            displayEmp(res);

                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;
                        case 4:
                            system("cls");
                            cout << "Enter ID: ";
                            cin >> id;
                            ll.deleteById(id);
                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;

                        case 5:
                            system("cls");
                            cout << "Enter Name: ";
                            cin>>name;
                            ll.deleteByName(name);
                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;
                        case 6:
                            system("cls");
                            cout << "Enter id to insert after: ";
                            cin>>afterId;
                            cout<<"Enter id, name, age of the employee: ";
                            cin>>id>>name>>age;
                            ll.insertAfter(afterId, id, name, age);
                            break;
                        case 7:
                            system("cls");
                            cout << "Number of employees: " <<ll.getCount();
                            cout << "Press any key to return..." << endl;
                            _getch();
                            break;
                        case 8:
                            flag = 1;
                            system("cls");
                            cout << "End Program";
                            break;
                    }
                    break;
                case 27: // escape
                    flag = 1;
                    break;
            }
    }while(!flag);


    return 0;
}

void gotoxy(int column, int line){
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void drawLineHorizontal(int col, int row, int hLength) {
    gotoxy(col, row);
    for(int i=0; i<hLength; i++) {
        cout<<" ";
    }
}

void drawLineVertical(int col, int row, int vLength) {
    for(int i=0; i<vLength; i++) {
        gotoxy(col, row + i);
        cout<<" ";
    }
}

void draw_rectangle(int col, int row, int vLength, int hLength, int color) {
    textattr(color);
    drawLineHorizontal(col, row, hLength);
    drawLineHorizontal(col, row + vLength, hLength);
    drawLineVertical(col, row, vLength);
    drawLineVertical(col + hLength - 1, row, vLength);
    textattr(0x07);
}

void display_menu(char menu[][20], int size, int row, int col, int s) {
    for(int i=0; i<size; i++) {
        if(i == s)
            textattr(0x04);
        gotoxy(row, col + i);
        cout << menu[i];
        textattr(0x07);
    }
}

void displayEmp(Node res) {
    if (res.id != -1) {
    cout << "Employee: " << res.id << " Name: " << res.name << " Age: " << res.age <<endl;
    } else {
        cout << "Employee not found" <<endl;
    }
}
