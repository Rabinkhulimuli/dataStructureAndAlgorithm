#include <iostream>
using namespace std;
struct Dnode{
    int data;
    Dnode* prev;
    Dnode* next;
};
int empty(Dnode** head){
    if(*head==nullptr){
        cout<<"list is empty"<<endl;
        return 1;
    }
    return 0;
}
void AddNewList(Dnode** head){
    int num;
    cout<<"enter the number "<<endl;
    cin>>num;
    Dnode* temp1=new Dnode;
    temp1->data=num;
    temp1->prev=nullptr;
    temp1->next=nullptr;
    if(*head==nullptr){
        *head=temp1;
    }else{
        Dnode* temp=*head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=temp1;
        temp1->prev=temp;
    }
}
void display(Dnode** head){
    Dnode* temp=*head;
    if (empty(&temp)){
        return;
    }
    cout<<"Node lists "<<endl;
    while(temp !=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void begadd(Dnode** head){
    if (*head==nullptr){
        AddNewList(head);
        return;
    }
    Dnode* current=*head;
    int num;
    cout<<"enter the number "<<endl;
    cin>>num;
    Dnode* temp=new Dnode;
    temp->data=num;
    temp->prev=nullptr;
    temp->next=current;
    current->prev=temp;
    *head=temp;
}
void specified(Dnode** head){
    Dnode* current=*head;
    int num;
    cout<<"enter the position "<<endl;
    cin>>num;
     if(num==1){
        begadd(head);
        return;
    }
    for(int i=1;i<num-1 && num !=1;i++){
         if (current->next==nullptr){
            break;
        }
        current=current->next;
       
    }
   
    cout<<"Enter the data to Insert"<<endl;
    cin>>num;
    Dnode* temp=new Dnode;
    temp->data=num;
    temp->prev=current;
    temp->next=current->next;
    current->next=temp;
}
void delbeg(Dnode** head){
    if (empty(head)){
        return;
    }
    Dnode* current=*head;
    if(current->next==nullptr){
        cout<<current->data<<" has been deleted"<<endl;
        *head=nullptr;
        free(current);
        return;
    }
    Dnode* temp=current->next;
    cout<<current->data<<" has been deleted"<<endl;
    temp->prev=nullptr;
    *head=temp;
    free(current);
}
void deleteE(Dnode** head){
     if (empty(head)){
        return;
    }
    Dnode* current=*head;
    Dnode* temp;
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
void delspecified(Dnode** head){
    if (empty(head)){
        return;
    }
    Dnode* current=*head,*temp1,*temp2;
    if (current->next==nullptr){
        *head==nullptr;
        cout<<"there is only one item "<<current->data<<" has been deleted"<<endl;
        free(current);
        return;
    }
    int num;
    cout<<"enter the position"<<endl;
    cin>>num;
    for (int i=1;i<num;i++){
        if(current->next==nullptr){
            cout<<"position is the last position or out of bound"<<endl;
            break;
        }
        current=current->next;
    }
    cout<<current->data<<" has been deleted"<<endl;
    temp1=current->prev;
    temp2=current->next;
    temp1->next=temp2;
    if(temp2 !=nullptr){
        temp2->prev=temp1;
    }
    free(current);
    
}
int main(){
    Dnode* head;
    head=nullptr;
    int ch;
    while(1){
        cout<<"Enter any one of the following choice"<<endl;
        cout<<"1.Insert New Element 2.Display 3.Insert at Beginning 4.Insert at Specified Location"<<endl
        <<"5.Delete from Begining 6.Delete from End 7.Delete from specitied position "
        <<"8.Exit "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                AddNewList(&head);
                break;
            case 2:
                display(&head);
                break;
            case 3:
                begadd(&head);
                break;
            case 4:
                specified(&head);
                break;
            case 5:
                delbeg(&head);
                break;
            case 6:
                if(!empty(&head)){
                    deleteE(&head);
                }
                break;
            case 7:
                delspecified(&head);
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
