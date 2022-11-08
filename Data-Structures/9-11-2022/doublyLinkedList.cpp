#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


class list{
    private:
        Node* head;
        Node* tail;
        int count;
    public:
        list();
        int Count();
        Node* Move(int index);
        void push_front(int value);
        void push_back(int value);
        void insert(int index, int value);
        void pop_front();
        void pop_back();
        void deleteAtIndex(int index);
        void printList();
};

list::list(){
    head = NULL;
    tail = NULL;
    count = 0;
}

int list::Count(){
    return count;
}

Node* list::Move(int index){
    Node* node = head;
    for(int i = 0; i < index; i++){
        node = node->next;
    }
    return node;
}

void list::push_front(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(count == 0){
        head = tail = newNode;
    } else{
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

void list::push_back(int value){
    Node* newNode = new Node;
    if(count == 0){
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = value;
        head = tail = newNode;
        count++;
    }else{
        newNode->next = NULL;
        newNode->data = value;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        count++;
    }
}

void list::insert(int index, int value){
    if(index == 0){
        push_front(value);
    } else if(index == count){
        push_back(value);
    }else{
        Node* nodePrev = Move(index-1);
        Node* nodeCurr = Move(index);
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nodeCurr;
        newNode->prev = nodePrev;
        nodePrev->next = newNode;
        nodeCurr->prev = newNode;
        count++;
    }
}

void list::pop_front(){
    Node* newNode = new Node;
    newNode = head;
    head = head->next;
    head->prev = NULL;
    delete newNode;
    count--;
}

void list::pop_back(){
    Node* newNode = tail;
    tail = newNode->prev;
    delete newNode;
    tail->next = NULL;
    count--;
}

void list::deleteAtIndex(int index){
    if(count == 0){
        return;
    }
    Node* nodeCurr = Move(index);
    Node* nodePrev = nodeCurr->prev;
    Node* nodeNext = nodeCurr->next;
    if(index == 0){
        pop_front();
    } else if(index == count - 1){
        pop_back();
    } else{
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
    delete nodeCurr;
    count--;
}  
void list::printList(){
    Node* newNode = head;
    for(int i = 0; i < count; i++){
        cout << newNode->data<< " ";
        newNode = newNode->next;
    }
    cout << endl;
}
int main(){
    list node;
    node.push_front(5);
    node.push_front(7);
    node.push_front(9);

    node.push_back(10);
    node.push_back(2);
    node.push_back(5);
    node.push_back(7);

    node.insert(3, 20);

    node.printList();

    node.pop_front();

    node.deleteAtIndex(2);

    node.pop_back();

    node.printList();
}
