#include <iostream>
using namespace std;
struct Node{
    int date;
    Node* next;

    Node(){
        date = 0;
        next = NULL;
    }
    Node(int data){
        this->date = data;
        next =  NULL;
    }
};

class LinkedList{
    Node* Head;
    int sz;
public:
    LinkedList(){
        Head = NULL;
        sz = 0;
    }
    
    // find the list is empty or not
    bool isEmpty(){
        if(Head == NULL)
            return true;
        return false;
    }
    
    // get the size of list
    int getSize(){
        return sz;
    }
    // fun to print all elements in list
    void print(){
        if(isEmpty()){
            cout<<"No elements to print\n";
            return;
        }
        Node* copyHead = Head;
        while(copyHead->next != NULL){
            cout << copyHead->date << ' ';
            copyHead = copyHead->next;
        }
        cout << copyHead->date << "\n";
    }
    // insert element at the end of linked list
    void insertBack(int data){
        Node* newNode = new Node(data);
        sz++;
        if(Head == NULL){
            Head = newNode;
            return;
        }
        Node* copyHead = Head;
        while(copyHead->next != NULL){
            copyHead = copyHead->next;
        }
        copyHead->next = newNode;
    }
    // insert node in the front of linked list
    void insertFront(int data){
        Node* newNode = new Node(data);
        sz++;
        if(Head == NULL){
            Head = newNode;
            return;
        }
        newNode->next = Head;
        Head = newNode;
    }
    // insert In order
    void insertByOrder(int order, int data){
        if(order < 0  || order > sz){
            cout << "Out of Bound\n";
            return;
        }
        Node* newNode = new Node(data);
        if(Head == NULL) {
            Head = newNode;
            sz++;
            return;
        }
        if(order == 0){
            insertFront(data);
            return;
        }
        if(order == sz){
            insertBack(data);
            return;
        }
        int cnt = 0;
        Node* copyHead = Head;
        while (cnt + 1 < order) {
            copyHead = copyHead->next;
            cnt++;
        }
        newNode->next = copyHead->next;
        copyHead->next = newNode;
        sz++;
    }
    void removeBack(){
        if(isEmpty()){
            cout << "No nodes to remove\n";
            return;
        }
        if(Head->next == NULL){
            Node* deletedNode = Head;
            Head = NULL;
            free(deletedNode);
            sz--;
            return;
        }
        Node* copyHead = Head;
        while (copyHead->next->next !=NULL) {
            copyHead = copyHead->next;
        }
        Node* deletedNode = copyHead->next;
        free(deletedNode);
        copyHead->next = NULL;
        sz--;
    }
    
    void removeFront(){
        if(isEmpty()){
            cout << "No elemenest to remove\n";
            return;
        }
        if(Head->next == NULL){
            Node* deletedNode = Head;
            Head = NULL;
            free(deletedNode);
            sz--;
            return;
        }
        Node* deletedNode = Head;
        Head = Head->next;
        free(deletedNode);
        sz--;
    }
    
    void removeByoreder(int order){
        if(isEmpty()){
            cout << "No elements to remove\n";
            return;
        }
        if(order >= sz || order < 0){
            cout << "Out of bound\n";
            return;
        }
        if(order == 0){
            removeFront();
            return;
        }
        if(order == sz - 1){
            removeBack();
            return;
        }
        int cnt = 0;
        Node* copyHead = Head;
        while(cnt + 1 < order){
            copyHead = copyHead->next;
            cnt++;
        }
        Node* deletedNode = copyHead->next;
        copyHead->next = deletedNode->next;
        free(deletedNode);
        sz--;
    }
};
int main(){
    LinkedList list;
    if(list.isEmpty()){
        cout << "list is empty()\n";
    }else {
        cout << "list is not empty()\n";
    }
    cout << "Size: " << list.getSize() << '\n';
    list.print();
    
    list.insertBack(5);
    if(list.isEmpty()){
        cout << "list is empty()\n";
    }else {
        cout << "list is not empty()\n";
    }
    cout << "Size: " << list.getSize() << '\n';
    list.print();
    list.insertBack(10);
    list.insertBack(11);
    list.insertBack(14);
    cout << "Size: " << list.getSize() << '\n';
    list.print();
    list.insertFront(9);
    list.print();
    list.removeBack();
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeFront();
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeByoreder(-1);
    list.removeByoreder(3);
    list.removeByoreder(4);
    list.removeByoreder(0);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeByoreder(list.getSize() - 1);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeFront();
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.insertBack(10);
    list.insertBack(14);
    list.insertBack(20);
    list.insertBack(12);
    list.insertBack(4);
    list.insertBack(1);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeByoreder(2);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.removeByoreder(3);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.insertByOrder(0, 14);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.insertByOrder(5, 6);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    list.insertByOrder(2,8);
    list.print();
    cout << "Size: " << list.getSize() << '\n';
    return 0;
}


