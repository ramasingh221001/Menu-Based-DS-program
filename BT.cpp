#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    char data;
    struct node *right;
}; node *root=NULL;

//insertion
node* insert(node *root);
node* newnode(char ch);

node* newnode(char ch)
{
    node *tmp=new node();
    tmp->data=ch;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

node* insert(node *root)
{
    root=newnode('A');
    root->left=newnode('B');
    root->right=newnode('C');
    root->left->left=newnode('D');
    root->left->right=newnode('E');
    root->right->left=newnode('F');
    root->right->right=newnode('G');
    root->left->left->left=newnode('H');
    root->left->left->right=newnode('I');
    root->left->left->right->left=newnode('J');
    root->left->left->right->right=newnode('K');
    root->right->right->left=newnode('L');
    root->right->right->left->left=newnode('N');
    root->right->right->left->left->left=newnode('P');
    root->right->right->right=newnode('M');
    root->right->right->right->right=newnode('R');
    root->right->right->right->left=newnode('Q');
    root->right->right->right->left->left=newnode('S');
    root->right->right->right->left->left->right=newnode('T');
    return root;

}

//traverse
void inorder(node *root)
{
    stack<node*> st;
   while(1)
   {
       while(root)
       {
           st.push(root);
           root=root->left;
       }
       if(st.empty())break;
       root=st.top();
       st.pop();
       cout<<root->data<<" ";
       root=root->right;
   }
}

void preorder(node *root)
{
    stack<node*> st;
    while(1)
    {
       while(root)
       {
           cout<<root->data<<" ";
           st.push(root);
           root=root->left;
       }
       if(st.empty())break;
       root=st.top();
       st.pop();
       root=root->right;
    }
}

void postorder(node *root)
{
    if(!root)return ;
    stack<node*> st;
    st.push(root);
    stack<char> out;
    while(!st.empty())
    {
        node *curr=st.top();
        st.pop();
        out.push(curr->data);
        if(curr->left)
        st.push(curr->left);
        if(curr->right)
        st.push(curr->right);
    }

    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
    cout<<endl;
}


void bfs(node *root)
{
    queue<node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        node *tmp=qu.front();// return front of queue
        qu.pop();
        cout<<tmp->data<<" ";
        if(tmp->left)
        {
            qu.push(tmp->left);
        }
        if(tmp->right)
        {
            qu.push(tmp->right);
        }
    }
}


void spiral(node *root)
{
    stack<char> st;
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    st.push(root->data);
    int count=1;
    while(qu.front())
    {
        if(count%2!=0)
        {
            while(!st.empty())
            {
                node *tmp=qu.front();
                qu.pop();
                cout<<st.top()<<" ";
                st.pop();
                if(tmp->left)
                qu.push(tmp->left);
                if(tmp->right)
                qu.push(tmp->right);
            }
        }
        else
        {
            while(qu.front())
            {
                node *tmp=qu.front();
                qu.pop();
                cout<<tmp->data<<" ";
                if(tmp->left)
                {
                    qu.push(tmp->left);
                    st.push(tmp->left->data);
                }
                if(tmp->right)
                {
                    qu.push(tmp->right);
                    st.push(tmp->right->data);
                }
            }
        }
        qu.pop();
        qu.push(NULL);
        count++;
    }
    cout<<endl;
}


void vertical_order(node *root)
{
    map<int,vector<char> > mp;
    queue<pair<node*,int> > qu;
    qu.push(make_pair(root,0));
    while(!qu.empty())
    {
        pair<node*,int> pr=qu.front();
        qu.pop();
        node *tmp=pr.first;
        int level=pr.second;
        mp[level].push_back(tmp->data);
        if(tmp->left)
        {
            qu.push(make_pair(tmp->left,level-1));
        }
        if(tmp->right)
        {
            qu.push(make_pair(tmp->right,level+1));
        }
    }

    map<int,vector<char> >::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<"level="<<it->first<<": ";
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }

}

//views
void topview(node *root)
{
    queue<pair<node*,int> > qu;
    map<int,char> mp;
    qu.push(make_pair(root,0));
    map<int,char>::iterator it;
    while(!qu.empty())
    {
        pair<node*,int> tmp=qu.front();
        qu.pop();
        node *tmp1=tmp.first;
        int level=tmp.second;
        it=mp.find(level);
        if(it==mp.end())
        {
            mp[level]=tmp1->data;
        }

        if(tmp1->left)
        {
            qu.push(make_pair(tmp1->left,level-1));
        }
        if(tmp1->right)
        {
            qu.push(make_pair(tmp1->right,level+1));
        }
    }

    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->second<<" ";
    }
cout<<endl;
}


void bottomview(node *root)
{
    queue<pair<node*,int> > qu;
    map<int,char> mp;
    map<int,char>::iterator it;

    qu.push(make_pair(root,0));
    while(!qu.empty())
    {
        pair<node*,int> tmp=qu.front();
        qu.pop();
        node *tmp1=tmp.first;
        int level=tmp.second;
        mp[level]=tmp1->data;

        if(tmp1->left)
        {
            qu.push(make_pair(tmp1->left,level-1));
        }
        if(tmp1->right)
        {
            qu.push(make_pair(tmp1->right,level+1));
        }
    }

    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->second<<" ";
    }
    cout<<endl;
}


void left_view(node *root)
{
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    while(qu.front())
    {
        cout<<qu.front()->data<<" ";
        while(qu.front())
        {
            node *tmp=qu.front();
            qu.pop();
            if(tmp->left)
            qu.push(tmp->left);
            if(tmp->right)
            qu.push(tmp->right);

        }
        qu.pop();
        qu.push(NULL);

    }
    cout<<endl;
}

void right_view(node *root)
{
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    node *tmp;
    while(qu.front())
    {
        while(qu.front())
        {
            tmp=qu.front();
            qu.pop();
            if(tmp->left)
            qu.push(tmp->left);
            if(tmp->right)
            qu.push(tmp->right);
        }
        cout<<tmp->data<<" ";
        qu.pop();
        qu.push(NULL);
    }
    cout<<endl;

}

int main()
{

    cout<<"\t-------------BINARY_TREE------------"<<endl;
    cout<<"\t1.Insertion"<<endl;
    cout<<"\t2.Traverse"<<endl;
    cout<<"\t3.Different View"<<endl;
    cout<<"\t-------------------------------------\n";
    l: cout<<"\tEnter Your Choice..."<<endl;
    int ch;
    cout<<"\t";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            root=insert(root);
            cout<<"\tDefault value inserted... "<<endl;
            break;
        }
        case 2:
        {

            cout<<"\t1.Pre-Order"<<endl;
            cout<<"\t2.In-Order"<<endl;
            cout<<"\t3.Post-Order"<<endl;
            cout<<"\t4.Level-Order"<<endl;
            cout<<"\t5.Spiral"<<endl;
            cout<<"\t6.Vertical-Order"<<endl;
           l1: cout<<"\tEnter ur choice..."<<endl;
            int ch;
            cout<<"\t";
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    preorder(root);
                    cout<<endl;
                    break;
                }
                case 2:
                {
                    inorder(root);
                    cout<<endl;
                    break;
                }
                case 3:
                {
                    postorder(root);
                    break;
                }
                case 4:
                {
                    bfs(root);
                    cout<<endl;
                    break;
                }
                case 5:
                {
                    spiral(root);
                    break;
                }
                case 6:
                {
                    vertical_order(root);
                    break;
                }
                default:
                    cout<<"press 1 -4 only"<<endl;
            }
            /*cout<<"press 0 to continue.."<<endl;
            int p;
            cin>>p;
            if(p==0)*/
            goto l1;
           // break;
        }
        case 3:
        {
            cout<<"\t1.Top View "<<endl;
            cout<<"\t2.Bottom View"<<endl;
            cout<<"\t3.Left View"<<endl;
            cout<<"\t4.Right View"<<endl;
       l2:  cout<<"\tEnter ur choice.."<<endl;
             int ch;
             cout<<"\t";
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    topview(root);
                    break;
                }
                case 2:
                {
                    bottomview(root);
                    break;
                }
                case 3:
                {
                    left_view(root);
                    break;
                }
                case 4:
                {
                    right_view(root);
                    break;
                }
                default:
                    cout<<"press 1 -4 only"<<endl;
            }
            /*cout<<"press 0 to continue.."<<endl;
            int p;
            cin>>p;
            if(p==0)*/
            goto l2;
           // break;
        }
        default:
        return 0;
    }
    goto l;
}
