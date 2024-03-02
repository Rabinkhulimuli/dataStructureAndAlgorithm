#include <iostream>
using namespace std;
struct Qnode{
    int data;
    Qnode* next;
};
void Enqueue(Qnode** front){
    int num;
    cout<<"enter the number"<<endl;
    cin>>num;
    Qnode* temp=new Qnode;
    temp->data=num;
    temp->next=nullptr;
    if (*front ==nullptr){
        *front=temp;
        return;
    }
    Qnode* current=*front;
    while(current->next != nullptr){
        current=current->next;
    }
    current->next=temp;
}
void Dequeue(Qnode** front){
    if(*front==nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Qnode* current=*front;
    Qnode* temp=current->next;
    cout<<current->data<<" has been deleted"<<endl;
    *front=temp;
    free(current);
}
void Display(Qnode** front){
    if(*front==nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Qnode* current=*front;
    while(current != nullptr){
        cout<<current->data<<endl;
        current=current->next;
    }
}
int main(){
    Qnode* front;
    int ch;
    front=nullptr;
    while(1){
        cout<<"choose the option below"<<endl;
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                Enqueue(&front);
                break;
            case 2:
                Dequeue(&front);
                break;
            case 3:
                Display(&front);
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"choose the correct option"<<endl;
                break;
        }
    }
    return 0;
}