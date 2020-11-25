#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int front,rear,size;

int push(int val,int queue[])
{
    if((rear+1)%size==front)
    {
        return 0;
    }
    else
    {
        if(rear==-1 && front==-1)
        {
            front++;
        }
        rear=(rear+1)%size;
        queue[rear]=val;
        return 1;
    }

}

int pop()
{
    if(front==-1)
    return 0;
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }
    return 1;
}

void input()
{
    cout<<"Enter size of queue"<<endl;
    cin>>size;
    int queue[size];
    rear=-1,front=-1;

    cout<<"-------------QUEUE-------- "<<endl;
    cout<<"      PRESS 1.ENQUEUE "<<endl;
    cout<<"      PRESS 2.DEQUEUE"<<endl;
    cout<<"      PRESS 3.PEEK "<<endl;
    cout<<"CHOOSE YOUR OPTION....."<<endl;
   l1:
    int op;
    cin>>op;
    switch(op)
    {
        case 1:
        {
            cout<<"Enter value which u want to Enter: "<<endl;
            int val;
            cin>>val;
            push(val,queue)?cout<<"Data sucessfully pushed"<<endl:cout<<"Queue overflow"<<endl;
            break;
        }
        case 2:
        {
            pop()?cout<<"Data Sucessfully poped"<<endl:cout<<"Queue Underflow"<<endl;
            break;
        }
        case 3:
        {
            cout<<"Data at top:"<<queue[front]<<endl;
            break;
        }
    }
    cout<<"Press 0 to continue or 1 to goto main menu"<<endl;
    int op2;
    cin>>op2;
    if(op2==0)
    goto l1;
}
bool search(char queue[],int slot,int ch)
{
    for(int i=0;i<slot;i++)
    {
        if(queue[i]==ch)
        return true;
    }
    return false;

}


int page_fault(string str)
{
    cout<<"Enter slot size:"<<endl;
    int slot;
    cin>>slot;
    char queue[slot];
    memset(queue,'e',slot);
    int rear=-1,front=-1,pagefault=1;
    for(int i=0;i<str.size();i++)
    {
        if(front==-1 && rear==-1)

        {
            front++,rear++;
            queue[rear]=str[i];
        }
        else
        {
            bool res=search(queue,slot,str[i]);
            if(!res)
            {
                rear=(rear+1)%slot;
                if(queue[rear]=='e')
                queue[rear]=str[i];
                else
                {
                    cout<<"Poped page: "<<queue[front]<<endl;
                    front=(front+1)%slot;
                    queue[rear]=str[i];
                }
                pagefault++;

            }

        }

    }
    return pagefault;
}




void push1(int val)
{
    cout<<"Enter values..."<<endl;
    while(val--)
    {
        int n;
        cin>>n;
        q.push(n);

    }
}

//REVERVSE
void reverse()
{
    stack<int> st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

//PARTREVERSE
void partrev(int n)
{
    stack<int> st1;
    queue<int> q1;
    //int size=q.size();
    while(n--)
    {
        st1.push(q.front());
        q.pop();
    }

    while(!st1.empty())
    {
        q1.push(st1.top());
        st1.pop();
    }

    while(!q.empty())
    {
       q1.push(q.front());
       q.pop();
    }

    while(!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
    }


}

//INPUT AND CALLING
void revinp()
{

    cout<<"1. ENQUEUE"<<endl;
    cout<<"2. DEQUEUE"<<endl;
    cout<<"3. PEEK"<<endl;
    cout<<"4. REVERSE"<<endl;
    cout<<"5. REVERSE PART"<<endl;
    cout<<"choose option...."<<endl;
     l1: int op;
    cin>>op;
    switch(op)
    {
        case 1:
        {
            cout<<"Enter no. of value u want to Enque: "<<endl;
            int val;
            cin>>val;
            push1(val);
            cout<<"Data Enqued sucessfully"<<endl;
            break;

        }
        case 2:
        {
            if(!q.empty())
            {
            cout<<"Dequed data:"<<q.front()<<endl;
            q.pop();
            }
            else
            cout<<"Queue Underflow......."<<endl;
            break;
        }
        case 3:
        {/* code */
            cout<<"Data at front is: "<<q.front()<<endl;
            break;

        }
        case 4:
        {
            reverse();
            cout<<"Queue Reversed sucessfully.."<<endl;
            break;
        }
        case 5:
        {
            int n;
            cout<<"Enter no. of elemant which u want to reverse: "<<endl;
            cin>>n;
            partrev(n);
            cout<<"Reversed Sucessfully..."<<endl;
            break;

        }
    }
    cout<<"press 0 to continue or any key to goto main menu"<<endl;
    int op2;
    cin>>op2;
    if(op2==0)
    goto l1;

}
int main()
{

    cout<<"\n \t----------OPERATION ON QUEUE-----"<<endl;
    cout<<"     PRESS 1.CIRCULAR QUEUE"<<endl;
    cout<<"     PRESS 2.PAGE FAULT IN MM"<<endl;
    cout<<"     PRESS 3.REVERSE QUEUE"<<endl;
    cout<<"     ANY OTHER KEY TO EXIT..."<<endl;
    cout<<"     CHOOSE UR OPTION.........."<<endl;
    l: int op;
    cin>>op;
    switch(op)
    {
        case 1:
        {
            input();
            break;
        }
        case 2:
        {
            cout<<"Enter reference string: "<<endl;
            string str;
            cin>>str;
            int res;
            res=page_fault(str);
            cout<<"No. of pagefaults: "<<res<<endl;
            break;
        }
        case 3:
        {
            revinp();
            break;
        }
        default:
        return 0;
    }
    goto l;
    return 0;

}
