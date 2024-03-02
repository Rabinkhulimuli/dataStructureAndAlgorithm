#include <iostream>
using namespace std;
struct Qnode{
    int data;
    Qnode* next;
};
void Push(Qnode** head){
    int num;
    cout<<"enter the number"<<endl;
    cin>>num;
    Qnode* temp=new Qnode;
    temp->data=num;
    temp->next=nullptr;
    if (*head ==nullptr){
        *head=temp;
        return;
    }
    Qnode* current=*head;
    while(current->next != nullptr){
        current=current->next;
    }
    current->next=temp;
}
void Pop(Qnode** head){
    if(*head==nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Qnode* temp=*head;
    if (temp->next==nullptr){
        cout<<temp->data<<" has been deleted"<<endl;
        *head=nullptr;
        free(temp);
        return;
    }
    Qnode* temp1=temp;
    while(temp->next != nullptr){
        temp1=temp;
        temp=temp->next;
    }
   temp1->next=nullptr;
    cout<<temp->data<<" has been deleted"<<endl;
    free(temp);
   
}
void Display(Qnode** head){
    if(*head==nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Qnode* current=*head;
    cout<<"List of items"<<endl;
    while(current != nullptr){
        cout<<current->data<<endl;
        current=current->next;
    }
}
int main(){
    Qnode* head;
    int ch;
    head=nullptr;
    while(1){
        cout<<"choose the option below"<<endl;
        cout<<"1.Push 2.Pop 3.Display 4.Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                Push(&head);
                break;
            case 2:
                Pop(&head);
                break;
            case 3:
                Display(&head);
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