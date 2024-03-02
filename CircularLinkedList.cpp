#include <iostream>
using namespace std;
struct Cnode{
    int data;
    Cnode* prev;
    Cnode* next;
};
int empty(Cnode** head){
    if(*head==nullptr){
        cout<<"list is empty"<<endl;
        return 1;
    }
    return 0;
}
void AddNewList(Cnode** head,Cnode** tail){
    int num;
    cout<<"enter the number "<<endl;
    cin>>num;
    Cnode* temp1=new Cnode;
    temp1->data=num;
    temp1->prev=nullptr;
    temp1->next=nullptr;
    if(*head==nullptr){
        *head=temp1;
        *tail=temp1;
    }else{
        Cnode* temp=*head;
        while(temp !=*tail){
            temp=temp->next;
        }
        temp->next=temp1;
        temp1->prev=temp;
        temp1->next=*head;
        (*tail)->next=temp1;
    }
}
void display(Cnode** head,Cnode** tail){
    Cnode* temp=*head;
    if (empty(&temp)){
        return;
    }
    cout<<"Node lists "<<endl;
    cout<<temp->data<<endl;
    while(temp !=*tail){
        temp=temp->next;
        cout<<temp->data<<endl;
    }
}
void begadd(Cnode** head,Cnode** tail){
    if (*head==nullptr){
        AddNewList(head,tail);
        return;
    }
    Cnode* current=*head;
    int num;
    cout<<"enter the number "<<endl;
    cin>>num;
    Cnode* temp=new Cnode;
    temp->data=num;
    temp->prev=nullptr;
    temp->next=current;
    current->prev=temp;
    *head=temp;
}
void delbeg(Cnode** head,Cnode** tail){
    if (empty(head)){
        return;
    }
    Cnode* current=*head;
    if(current->next==nullptr){
        cout<<current->data<<" has been deleted"<<endl;
        *head=nullptr;
        free(current);
        return;
    }
    Cnode* temp=current->next;
    cout<<current->data<<" has been deleted"<<endl;
    temp->prev=nullptr;
    *head=temp;
    free(current);
}
void deleteE(Cnode** head,Cnode** tail){
     if (empty(head)){
        return;
    }
    Cnode* current=*head;
    Cnode* temp;
    if(current->next==nullptr){
        cout<<current->data<<" has been deleted"<<endl;
        *head=nullptr;
        free(current);
        return;
    }
    while(current->next !=nullptr){
        temp=current;
        current=current->next;
    }
    cout<<current->data<<" has been deleted"<<endl;
    temp->next=nullptr;
    free(current);
}

int main(){
    Cnode* head,*tail;
    head=nullptr;
    tail=nullptr;
    int ch;
    while(1){
        cout<<"Enter any one of the following choice"<<endl;
        cout<<"1.Insert New Element 2.Display 3.Insert at Beginning 4.Insert at Specified Location"<<endl
        <<"5.Delete from Begining 6.Delete from End 7.Delete from specitied position "
        <<"8.Exit "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                AddNewList(&head,&tail);
                break;
            case 2:
                display(&head,&tail);
                break;
            case 3:
                begadd(&head,&tail);
                break;
            case 5:
                delbeg(&head,&tail);
                break;
            case 6:
                if(!empty(&head)){
                    deleteE(&head,&tail);
                }
                break;
            case 8:
                return 0;
                break;
            default:
                cout<<"choose the correct answer"<<endl;
                break;
        }
    }
}
