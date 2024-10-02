#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>

using namespace std;
class Node
{
public:
    char data;
    Node* prev;
    Node* next;
    Node() :next(nullptr) {}
    Node(char c) :data(c), prev(nullptr), next(nullptr) {}
};
class Notepad
{
private:
    Node* head;
    Node* cursor;
    int size;
    int cursorposition;
public:
    Notepad() {
        head = cursor = new Node('|');
        size = 0;
        cursorposition = 0;
    }
    void insertChar(char ch) {
        Node* newNode = new Node(ch);
        if (size == 0) {
            head = newNode;
            newNode->next = cursor;
            cursor->prev = head;
            size++;
            cursorposition++;
        }
        else {

            newNode->next = cursor;
            newNode->prev = cursor->prev;
            if (newNode->prev != nullptr)
            {
                newNode->prev->next = newNode;
            }
            else
            {
                head = newNode;
            }
            cursor->prev = newNode;
            size++;
            cursorposition++;
        }

    }

    void moveLeft() {
        if (cursor->prev != nullptr) {
            cursor->data = cursor->prev->data;
            cursor = cursor->prev;
            cursor->data = '|';
            cursorposition--;

        }
    }

    void moveRight() {
        if (cursor->next != nullptr) {
            cursor->data = cursor->next->data;
            cursor = cursor->next;
            cursor->data = '|';
            cursorposition++;
        }
    }

    void moveUp() {
        int count = 0;
        Node* temp = cursor->prev;
        while (temp != nullptr && temp->data != '\n') {
            temp = temp->prev;
            count++;
        }

        if (temp == nullptr) {
            return;
        }
        temp = temp->prev;

        if (temp == nullptr) {
            return;
        }

        while (temp->prev != nullptr && temp->data != '\n') {
            temp = temp->prev;
        }

        if (temp->data == '\n')
        {
            temp = temp->next;
        }

        for (int i = 0; i < count; i++)
        {
            if (temp->data == '\n')
            {
                break;
            }
            temp = temp->next;
        }

        while (cursor != temp)
        {
            moveLeft();
        }
    }

    void moveDown() {
        int count = 0;
        Node* temp = cursor->prev;
        while (temp != nullptr && temp->data != '\n') {
            temp = temp->prev;
            count++;
        }
        if (cursor->next == nullptr)
        {
            return;
        }
        temp = cursor;
        while (temp->next != nullptr && temp->data != '\n')
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            return;
        }
        temp = temp->next;
        for (int i = 0; i < count; i++)
        {
            if (temp->next == nullptr || temp->data == '\n')
            {
                break;
            }
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            temp = temp->prev;
        }
        while (cursor != temp)
        {
            moveRight();
        }
    }

    void display() {
        system("cls");
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;

        }
        cout << endl << endl << endl << endl << endl << "\t\tCoursor Position :" << cursorposition << endl;
    }

    void deleteWordBefore() {
        Node* temp = cursor;
        if (cursor->prev == nullptr || cursor->prev == head) {
            return;
        }

        while (temp != head && temp->data != ' ')
        {
            deleteBefore();
            if (cursor->prev == nullptr)
            {
                break;
            }
            temp = cursor->prev;
        }
    }

    void deleteWordAfter() {
        Node* temp = cursor;
        if (cursor->next == nullptr) {
            return;
        }

        while (temp->data != ' ')
        {
            deleteAfter();
            if (cursor->next == nullptr)
            {
                break;
            }
            temp = cursor->next;
        }
    }

    void deleteBefore() {

        if (cursor->prev != nullptr && cursor->prev != head)
        {
            Node* del = cursor->prev;
            cursor->prev = del->prev;
            del->prev->next = cursor;
            delete del;
            size--;
            cursorposition--;
        }
        if (cursor->prev == head)
        {
            head = cursor;
            delete cursor->prev;
            cursor->prev = nullptr;
            size--;
            cursorposition--;
        }
    }

    void deleteAfter() {
        if (cursor->next != nullptr)
        {
            Node* del = cursor->next;
            cursor->next = del->next;
            if (del->next != nullptr) {
                del->next->prev = cursor;
            }
            delete del;
            size--;
        }
    }

    void savefile(string name) {
        ofstream file{ name + ".txt" };
        if (file.is_open())
        {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == '|');
                else {
                    file << temp->data;

                }
                temp = temp->next;
            }
            file.close();
            cout << "File saved successfully!" << endl;
        }
        else {
            cout << "error in opening file\n";
        }
    }

    void loadfile(string name) {
        ifstream file(name + ".txt");
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                insertChar(ch);
            }
            file.close();
            cout << "File loaded successfully!" << endl;
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }
    ~Notepad() {
        Node* temp = head->next;
        while (temp != nullptr)
        {
            delete temp->prev;
            temp = temp->next;
        }
        delete temp;
    }
};

int main() {
    Notepad n;
    char key;
    string filename;
    bool namealrgiven = 0;
    while (true) {
        n.display();
        key = _getch();  // Get a character or special key

        if (key == 27) {// ESC key to exit
            if (!namealrgiven)
            {
                char select;
                cout << "do u want to save ur file (y/n)";
                cin >> select;
                if (select == 'y' || select == 'Y')
                {
                    cout << "Enter filename to save: ";
                    cin >> filename;
                    n.savefile(filename);
                    continue;
                }
            }
            break;
        }
        if (key == 19) {  // Ctrl + S for saving
            if (!namealrgiven)
            {
                cout << "Enter filename to save: ";
                cin >> filename;
                namealrgiven = 1;
            }
            n.savefile(filename);
            continue;
        }
        if (key == 12) {  // Ctrl + L for loading
            if (!namealrgiven)
            {
                cout << "Enter filename to load: ";
                cin >> filename;
                namealrgiven = 1;
            }
            n.loadfile(filename);
            continue;
        }
        else if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) {
            if (key == 127) // Ctrl + Backspace
            {
                n.deleteWordBefore();
                continue;
            }
            if (key == -32) // Ctrl + Delete
            {
                n.deleteWordAfter();
                continue;
            }
        }
        else if (key == -32) {  // Special keys (arrow keys)
            key = _getch();
            if (key == 75) {  // Left arrow key
                n.moveLeft();
                continue;
            }
            else if (key == 72) // Up arrow key
            {
                n.moveUp();
                continue;
            }
            else if (key == 80) // Up down key
            {
                n.moveDown();
                continue;
            }
            else if (key == 77) {  // Right arrow key
                n.moveRight();
                continue;
            }
            else if (key == 83) {  // Delete key
                n.deleteAfter();
                continue;
            }
        }
        else if (key == 8) {  // Backspace key
            n.deleteBefore();
            continue;
        }
        else if (key == 13) { // Next Line
            n.insertChar('\n');
            continue;
        }
        else {
            n.insertChar(key);  // Any other character
        }
    }
}