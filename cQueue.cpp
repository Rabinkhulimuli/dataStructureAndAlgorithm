#include <iostream>
using namespace std;
#define MAX 5
struct cqueue{
    int data[MAX];
    int front;
    int rear;
};
void enqueue(struct cqueue *st){
    int num;
    if (st->front==st->rear+1 || (st->front==0 &&st->rear== MAX - 1)){
        cout<<"queue is full"<<endl;
    }else{
        if (st->front==-1) 
             st->front=0;
        cout<<"enter the number"<<endl;
        cin>>num;
        st->rear =(st->rear+1)%MAX;
        st->data[st->rear]=num;

    }
}
void dequeue(struct cqueue *st){
    if (st->front==-1){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<st->data[st->front]<<" is deleted"<<endl;
        st->front=(st->front+1)%MAX;
        if (st->front==st->rear){
            st->front=-1;
            st->rear=-1;
        }
    }
}
void display(struct cqueue *st){
    if (st->front==-1){
        cout<<"queue is empty"<<endl;
    }
    else{
        int i;
       for (i=st->front;i!=st->rear;i=(i+1)%MAX){
        cout<<st->data[i]<<endl;
       }
        cout<<st->data[i]<<endl;
    }
}
int main(){
    struct cqueue st;
    st.front=-1;
    st.rear=-1;
    int ch;
    while(1){
        cout<<"enter the choice "<<endl;
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Quit"<<endl;
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
                return 0;
                break;
            default:
                cout<<"enter the right choice"<<endl;

        }
    }
    return 0;
}