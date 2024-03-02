#include <iostream>
using namespace std;
#define MAX 5
struct pqueue{
    int data[MAX];
    int top=-1;
};
void enqueue(struct pqueue *st){
    if (st->top==MAX-1){
        cout<<"queue is full"<<endl;
    }else{
        st->top++;
        int num;
        cout<<"enter the number"<<endl;
        cin>>num;
        st->data[st->top]=num;
    }
    int temp;
    for (int i=0;i<=st->top;i++){
        for(int j=i+1;j<=st->top;j++){
            if (st->data[i]>st->data[j]){
                temp=st->data[i];
                st->data[i]=st->data[j];
                st->data[j]=temp;
            }
        }
    }
}
void dequeue(struct pqueue *st){
    if (st->top==-1){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<st->data[st->top]<<" has been deleted"<<endl;
        st->top-=1;
    }
}
void display(struct pqueue *st){
    if(st->top==-1){
        cout<<"queue is empty"<<endl;
    }
    else{
        for (int i=0;i<=st->top;i++){
            cout<<st->data[i]<<endl;
        }
    }
}
int main(){
    struct pqueue st;
    int ch;
    while(1){
        cout<<"choose the choice"<<endl;
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Seek 5.Quit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                enqueue(&st);
                break;
            case 2:
                dequeue(&st);
                break;
            case 3:
                display(&st);
                break;
            case 4:
                cout<<st.data[st.top]<<endl;
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"choose the valid choice"<<endl;
        }
    }
    return 0;
}