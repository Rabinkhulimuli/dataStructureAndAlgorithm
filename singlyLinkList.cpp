#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
};
void addelement(node** head){
    node* current=*head;
    int num;
    cout<<"enter the data number"<<endl;
    cin>>num;
    node* temp=new node;
    temp->data=num;
    temp->next=nullptr;
    if (*head==nullptr){
        *head=temp;
    }else{
        while(current->next !=nullptr){
            current=current->next;
        }
        current->next=temp;
    }
}
void display(node **head){
    node* temp=*head;
    cout<<"List of nodes"<<endl;
    while(temp !=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    free(temp);
}
void begadd(node** head){
    int num;
    cout<<"enter the number"<<endl;
    cin>>num;
    node* temp=new node;
    temp->data=num;
    temp->next=*head;
    *head=temp;
}
void specified(node** head){
    node* temp=*head;
    int num;
    cout<<"enter the position to add content"<<endl;
    cin>>num;
    for(int i=1;i<num-1;i++){
        temp=temp->next;
    }
    cout<<"enter the data"<<endl;
    cin>>num;
    node* temp1=new node;
    temp1->data=num;
    temp1->next=temp->next;
    temp->next=temp1;
}
void delbeg(node** head){
    node* temp= *head;
    cout<<temp->data<<" has been deleted"<<endl;
    *head=temp->next;
    free(temp);
}
int empty(node** head){
    if (*head==nullptr){
        cout<<"node is empty"<<endl;
        return 1;
    }
    return 0;

}
void deleteE(node** head){
    node* temp=*head;
   
    if (temp->next ==nullptr){
        cout<<temp->data<<" has been deleted"<<endl;
        *head=nullptr;
        free(temp);
        return;
    }
     node* current=temp;
    while(current->next != nullptr){
            temp=current;
            current=temp->next;
    }
        temp->next=nullptr;
        cout<<current->data<<" has been deleted"<<endl;
        free(current);
}
void delspecified(node** head){
    node* temp2=*head;
    node* temp1=temp2,*temp3,*current=*head;
    if (empty(&temp2)){
        cout<<"invalid command"<<endl;
        return;
    }
    
    int num;
    cout<<"enter the position"<<endl;
    cin>>num;
    for(int i=1;i<num && num !=1;i++){
        temp1=temp2;
        if(temp1->next==nullptr){
            break;
        }
        temp2=temp2->next;
        temp3=temp2->next;
    }
    if(current->next==nullptr ||num==1 || temp1->next==nullptr){
        deleteE(&current);
        return;
    }
    cout<<temp2->data<<" has been deleted"<<endl;
    temp1->next=temp3;
    free(temp2);
}
int main(){
    node *head;
    head=nullptr;
    int ch;
    while(1){
        cout<<"enter any one of following the choice"<<endl;
        cout<<"1.Add New Element 2.Display 3.Add at Beginning 4.Specified Location"<<endl<<"5.Delete from Begining 6.Delete from End 7.Delete from specitied position 8.Exit "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                addelement(&head);
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
                if(!empty(&head)){
                    delbeg(&head);
                }
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
return 0;
}