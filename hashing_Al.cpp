#include <iostream>
using namespace std;
struct chain{
    int data;
    chain* next;
};
void insert_hash(chain *arr[],int n){
    int temp,index;
    cout<<"enter the number to insert"<<endl;
    cin>>temp;
    index=temp%n;
    chain *tempC=new chain;
    tempC->data=temp;
    tempC->next=nullptr;
    if(arr[index] != nullptr){
        chain* newChain=new chain;
        newChain=arr[index];
        cout<<"value collided"<<endl;
        while(newChain->next!=nullptr){
            newChain=newChain->next;
        }
        newChain->next=tempC;
    }
    else{
        arr[index]=tempC;
    }
    cout<<"data inserted "<<arr[index]->data<<endl;
}
void display(chain *arr[],int n){
    cout<<"displaying inserted value"<<endl;
    chain* temp=new chain;
    
    for(int i=0;i<n;i++){
       if (arr[i] != nullptr){

             cout<<arr[i]->data<<endl;
             temp=arr[i];
             cout<<"------------"<<endl;
            while(temp->next !=nullptr){

                temp=temp->next;
                cout<<temp->data<<endl;
            }
         cout<<"------------"<<endl;
       }
    }
}
void search_hash(chain* arr[],int n){
    int temp,index;
    cout<<"enter the element to search for"<<endl;
    cin>>temp;
    index=temp%n;
    if(arr[index]==nullptr){
        cout<<"Item not found"<<endl;
        return;
    }
    chain* tempC=arr[index];
    while(tempC !=nullptr){
        if(tempC->data==temp){
            cout<<"item found"<<endl;
            return;
        }
        tempC=tempC->next;
    }
    if(tempC==nullptr)
    cout<<"item not found"<<endl;
}
void delete_hash(chain* arr[],int n){
    int num,index;
    cout<<"which number is to delete"<<endl;
    cin>>num;
    index=num % n;
    if(arr[index]==nullptr){
        cout<<"there is no such item"<<endl;
        return;
    }
    chain* newChain=arr[index],*tempChain;
    if (newChain->next==nullptr){
         cout<<num<<" has been deleted"<<endl;
         arr[index]=nullptr;
         free(newChain);
         return;
    }
    while(newChain !=nullptr){
        tempChain=newChain;
        newChain=newChain->next;
        if (newChain->data==num){
            cout<<num<<" has been deleted"<<endl;
            tempChain->next=newChain->next;
            free(newChain);
            return;
        }
       
    }
    cout<<"item hasnt been inserted"<<endl;

}
int main(){
    chain *arr[10]={nullptr};
    int n=10;
    int ch,num;
    while(1){
        cout<<"choose one of the following choice"<<endl;
        cout<<"1.Insert 2.Display 3.Delete 4.Search 5.Exit"<<endl;
        cin>>ch;
         switch(ch){
            case 1:
                 insert_hash(arr,n);
                break;
            case 2:
                display(arr,n);
                break;
            case 3:
                delete_hash(arr,n);
                break;
            case 4:
                search_hash(arr,n);
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"choose the right choice"<<endl;
                break;
    }
    }
    return 0;
}