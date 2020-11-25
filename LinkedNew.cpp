#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
node *head=NULL;

void input()
{
    cout<<"Enter no .of elemant u want to insert"<<endl;
    int n;
    cin>>n;
    cout<<"Enter values.."<<endl;
    struct node *tmp1;
    while(n--)
    {
        int val;
        cin>>val;
        if(head==NULL)
        {
            struct node *tmp=new node();
            head=tmp;
            tmp->next=NULL;
            tmp->data=val;

        }
        else
        {
            tmp1=head;
            while(tmp1->next!=NULL)
            {
                tmp1=tmp1->next;
            }
            struct node *tmp=new node();
            tmp1->next=tmp;
            tmp->next=NULL;
            tmp->data=val;

        }

    }
}
void print(node *head)
{
    node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

// Detect Loop
bool loop(node *head)
{
    node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 0;
        }
    }
    return 1;
}

// Reverse Node
node* reverse(node *head)
{
    node *prev=NULL,*tmp=head,*curr=NULL;
    while(tmp!=NULL)
    {
        curr=tmp->next;
        tmp->next=prev;
        prev=tmp;
        tmp=curr;
    }
    return prev;

}
//  Delete Last Occurances
node* deletelast(node *head)
{
   int arr[100];
   memset(arr,0,sizeof(arr));
   node *tmp=head,*start=head,*tmp1=head;
   while(tmp!=NULL)
   {
       arr[tmp->data]++;
       tmp=tmp->next;
   }

   tmp=head;
   while(tmp!=NULL)
   {
       if(arr[tmp->data]==1)
       {
           if(tmp==start)
           {
               tmp=tmp->next;
               start=tmp;
               tmp1=tmp;
           }
           else
           {
               tmp=tmp->next;
               tmp1->next=tmp;
           }
       }
       else
       {
           arr[tmp->data]--;
           tmp1=tmp;
           tmp=tmp->next;
       }
   }
   return start;
}
// mid Elements
node* mid1(node *head)
{
    if(head->next==NULL)
    return head;
    else
    {
        node *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

}

node* evenend(node *head)
{
    node *oddst=NULL,*evenst=NULL,*evtmp=NULL,*odtmp=NULL;
    node *tmp=head;
    int count=1;
    while(tmp!=NULL)
    {
        if(count%2==0)
        {
            if(evenst==NULL)
            {
                evenst=tmp;
                evtmp=tmp;
            }
            else
            {
                evtmp->next=tmp;
                evtmp=tmp;
            }

        }
        else
        {
            if(oddst==NULL)
            {
                oddst=tmp;
                odtmp=tmp;
            }
            else
            {
                odtmp->next=tmp;
                odtmp=tmp;
            }

        }
        tmp=tmp->next;
        count++;
    }
    odtmp->next=evenst;
    evtmp->next=NULL;
    return oddst;
}

// Nth from Last
int nthlast(node *head,int n)
{
    node *slow=head,*fast=head;
    while(n--)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
return slow->data;
}
// Duplicate Elements

node* rmduplicate(node *head)
{
    int arr[100];
    memset(arr,0,sizeof(arr));
    node *tmp=head,*tmp1=head,*start=head;
    while(tmp!=NULL)
    {
        arr[tmp->data]++;
        tmp=tmp->next;
    }

    tmp=head;
    while(tmp!=NULL)
    {
        if(arr[tmp->data]>1)
       {
           if(tmp==start)
           {
               tmp=tmp->next;
               start=tmp;
               tmp1=tmp;
           }
           else
           {
               tmp=tmp->next;
               tmp1->next=tmp;
           }
       }
       else
       {
           tmp1=tmp;
           tmp=tmp->next;
       }

    }
    return start;
}
//
bool binarysearch(node *root,int val)
{
    node *start=root,*end=NULL;
        do{
            node *slow=start,*fast=start,*tmp=start;
            while(fast!=end && fast->next!=end)
            {
                tmp=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            if(slow==NULL)
            return false;

            if(slow->data<val)
            start=slow->next;
            else if(slow->data>val)
            end=slow;
            else
            return true;

            /*if(start==end && start->data==val)
            return true;*/

        }while(start!=end || end==NULL);
        return false;
}
//Swap Node
node* swap(node *head,int a,int b)
{
    node *tmpa=NULL,*tmpb=NULL,*ap=NULL,*bp=NULL,*tmp=head,*tmp1=head;
    while(tmp!=NULL)
    {
        if(tmp->data==a)
        {
            tmpa=tmp1;
            ap=tmp;
        }
        else if(tmp->data==b)
        {
            tmpb=tmp1;
            bp=tmp;
        }
        else
        {
            tmp1=tmp;
        }
        tmp=tmp->next;
    }

    if(ap==NULL || bp==NULL)
    return head;
    else
    {
        if(ap==head)
        {
            node *tmp=ap->next;
            tmpb->next=ap;
            ap->next=bp->next;
            bp->next=tmp;
            head=bp;
        }
        else
        {
            tmpa->next=bp;
            node *tmp=bp->next;
            bp->next=ap->next;
            tmpb->next=ap;
            ap->next=tmp;
        }

    }

    return head;

}

int main()
{

    cout<<"\t --------LINKED LIST OPERATION------"<<endl;
    cout<<"    1.Insert Element"<<endl;
    cout<<"    2.Reverse the List"<<endl;
    cout<<"    3.Detect Loop "<<endl;
    cout<<"    4.Delete Last Occurance"<<endl;
    cout<<"    5.Display List "<<endl;
    cout<<"    6.Find Mid Element"<<endl;
    cout<<"    7.Odd In Beginning & Even in End"<<endl;
    cout<<"    8.Remove Duplicate"<<endl;
    cout<<"    9.Nth Element From the Last"<<endl;
    cout<<"    10.Binary Search"<<endl;
    cout<<"    11.Swap two Nodes"<<endl;
    cout<<"    Any Other Key to EXIT..."<<endl;
    cout<<"\t ---------------------------------"<<endl;
   l: cout<<" Enter Your Choice..!!!"<<endl;
     int op;
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
            head=reverse(head);
            cout<<"Reversed data are: "<<endl;
            print(head);
            break;
        }
        case 3:
        {
            loop(head)?cout<<"No loop is present!!!"<<endl:cout<<"Loop is present"<<endl;
            break;
        }
        case 4:
        {
            head=deletelast(head);
            cout<<"Data after deletion: "<<endl;
            print(head);
            break;
        }
        case 5:
        {
            print(head);
            break;
        }
       case 6:
        {
            node *mid=mid1(head);
            cout<<"Mid element is:"<<mid->data<<endl;
            break;
        }
        case 7:
        {
            head=evenend(head);
            break;
        }
        case 8:
        {
            head=rmduplicate(head);
            cout<<"Duplicate Removed Successfully\n";
            break;
        }
        case 9:
        {
            int n;
            cout<<"Enter position:"<<endl;
            cin>>n;
            int res=nthlast(head,n);
            cout<<"Value at position "<<n<<" is "<<res<<endl;
            break;
        }
        case 10:
        {
            int val;
            cout<<"Enter value u want to search"<<endl;
            cin>>val;
            binarysearch(head,val)?cout<<"Value found"<<endl:cout<<"Value not found"<<endl;
            break;
        }
        case 11:
        {
            int a,b;
            cout<<"Enter two value which u want to swap"<<endl;
            cin>>a>>b;
            head=swap(head,a,b);
            cout<<"Node is Sucessfully swapped....."<<endl;
            break;
        }
        default:
        return 0;
    }
    goto l;

}
