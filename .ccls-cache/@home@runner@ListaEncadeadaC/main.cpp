#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }

    void insert(int value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* current = head;
        if (pos == 0) {
            head = current->next;
            delete current;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node* toRemove = current->next;
            current->next = toRemove->next;
            delete toRemove;
        }

        size--;
    }

    int& operator[](int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            exit(1);
        }

        Node* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }

        return current->data;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Teste da função isEmpty()
    if (list.isEmpty()) {
        cout << "Lista vazia? Sim" << endl;
    } else {
        cout << "Lista vazia? Não" << endl;
    }

    // Teste da função getSize()
    cout << "Size: " << list.getSize() << endl; // Deve imprimir "Size: 0"

    // Teste da função insert()
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    list.insert(40, 1);
    list.print(); // Deve imprimir "10 40 20 30"

    // Teste da função remove()
    list.remove(1);
    list.print(); // Deve imprimir "10 20 30"

    // Teste do operador []
    cout << list[1] << endl; // Deve imprimir "20"
    list[2] = 50;
    list.print(); // Deve imprimir "10 20 50"

    return 0;
}

