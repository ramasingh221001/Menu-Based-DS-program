#include<bits/stdc++.h>
using namespace std;


struct node{
    struct node *left;
    int data;
    struct node *right;
};
node *root=NULL;

 node* insert(node *root)
{
    cout<<"Enter the no. of value u want to insert"<<endl;
    int n;
    cin>>n;
    cout<<"Enter values \n";
    while(n--)
    {
        int val;
        cin>>val;
        if(root==NULL)
        {
          node *tmp=new node();
          root=tmp;
          tmp->left=NULL;
          tmp->right=NULL;
          tmp->data=val;
        }
        else
        {
            node *tmp=root,*tmp1;
            while(tmp!=NULL)
            {
                if(tmp->data>val)
                {
                    tmp1=tmp;
                    tmp=tmp->left;
                }
                else if(tmp->data<val)
                {
                    tmp1=tmp;
                    tmp=tmp->right;
                }
                else
                break;
            }

            if(tmp==NULL)
            {
                node *tmp2=new node();
                tmp2->data=val;
                tmp2->left=NULL;
                tmp2->right=NULL;
                if(tmp1->data<val)
                tmp1->right=tmp2;
                if(tmp1->data>val)
                tmp1->left=tmp2;

            }

        }


    }
    return root;
}

//Preorder
void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//Inorder
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

//Postorder
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

//Level order
void bfs(node *root)
{
    queue<node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        node *tmp=qu.front();
        qu.pop();
        cout<<tmp->data<<" ";
        if(tmp->left!=NULL)
        qu.push(tmp->left);
        if(tmp->right!=NULL)
        qu.push(tmp->right);

    }
}


int minm(node *root)
{
    if(root->left==NULL)
    return root->data;
    else
    {
        return minm(root->left);
    }
}

int maxm(node *root)
{
    if(root->right==NULL)
    {
        return root->data;
    }
    else
    {
        return maxm(root->right);
    }

}

node* deletenode(node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deletenode(root->left, key);

    else if (key > root->data)
        root->right = deletenode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }


        node* temp=root->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

bool pairsum(node *root,int sum)
{
    int arr[100];
    memset(arr,0,sizeof(arr)); // declared arr with 0;
    queue<node*> qu;
    qu.push(root);
    arr[root->data]=1;// visited root
    while(!qu.empty())
    {
        node *tmp=qu.front();
        qu.pop();
        int rm=sum-(tmp->data);
        if(arr[rm]==1)return true;
        arr[tmp->data]=1;

        if(tmp->left)
        qu.push(tmp->left);
        if(tmp->right)
        qu.push(tmp->right);
    }
    return false;
}

void kthmin_max(node *root,int k)
{
    stack<node*> st;
    stack<int> out;
    while(1)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty())break;
        out.push(st.top()->data);
        root=st.top()->right;
        st.pop();
    }

    int size=out.size();
    int kthmin=size-k+1;
    int count=0;
    while(!out.empty())
    {
        count++;
        if(count==k)
        cout<<"k-th max="<<out.top()<<endl;
        if(count==kthmin)
        cout<<"k-th min="<<out.top()<<endl;
        out.pop();
    }

}

int floor(node *root,int k)
{
    if(root==NULL)
    return INT_MAX;
    if(root->data==k)
    return k;

    if(k<root->data)
    return floor(root->left,k);

    int fl=floor(root->right,k);
    return (fl<=k)?fl:root->data;

}

int ceil(node *root,int k)
{
    if(root==NULL)
    return -1;
    if(root->data==k)
    return k;
    if(root->data<k)
    return ceil(root->right,k);

    int cl=ceil(root->left,k);
    return (cl>=k)?cl:root->data;
}

//Descending
void descending(node *root)
{
    stack<node*> st;
    stack<int> out;
    while(1)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty())break;
        out.push(st.top()->data);
        root=st.top()->right;
        st.pop();
    }

    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
    cout<<endl;
}

int main()
{
    cout<<"-------------Binary Search Tree-------"<<endl;
    cout<<"   1.Insert Node"<<endl;
    cout<<"   2.Traverse Node"<<endl;
    cout<<"   3.Min Max"<<endl;
    cout<<"   4.Delete node"<<endl;
    cout<<"   5.Kth Min Max "<<endl;
    cout<<"   6.Pair with given sum"<<endl;
    cout<<"   7.Floor and ceil of node"<<endl;
    cout<<"   8.Printing Accending Order & Descending Order \n";
    cout<<"   Any other key to exit.."<<endl;
    cout<<"---------------------------------------\n";
  l:  cout<<"   Choose your option (Main Menu)..."<<endl;
    int op;
    cin>>op;
    switch(op)
    {
        case 1:
        {
            root=insert(root);
            break;
        }
        case 2:
        {
            cout<<"-------Traversal Menu---------- "<<endl;
            cout<<"\t1.Pre-Order"<<endl;
            cout<<"\t2.In-Order"<<endl;
            cout<<"\t3.Post-Order"<<endl;
            cout<<"\t4.Level-Order"<<endl;
            cout<<"\t5.Vertical-Order"<<endl;
            cout<<"------------------------------"<<endl;
           l2:  cout<<"Choose your option(Traversal Menu)..."<<endl;
            int op2;
            cin>>op2;
            switch(op2)
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
                    cout<<endl;
                    break;
                }
                case 4:
                {
                    bfs(root);
                    cout<<endl;
                    break;
                }

                default:
                    cout<<"press 1 -5 only"<<endl;
            }
            cout<<"press 0 to continue... and press any key to go to main menu "<<endl;
            int op;
            cin>>op;
            if(op==0)goto l2;
            goto l;
        }
        case 3:
        {
            int min=minm(root);
            int max=maxm(root);
            cout<<"\tMin= "<<min<<endl;
            cout<<"\tMax= "<<max<<endl;
            break;
        }
        case 4:
        {
            cout<<"Enter node u want to delete"<<endl;
            int val;
            cin>>val;
            root=deletenode(root,val);
            cout<<"Data Sucessfully deleted"<<endl;
            break;

        }

        case 5:
        {
            cout<<"Enter value of k.."<<endl;
            int k;
            cin>>k;
            kthmin_max(root,k);
            break;
        }
        case 6:
        {
            int sum;
            cout<<"Enter sum: "<<endl;
            cin>>sum;
            pairsum(root,sum)?cout<<"Pair with given sum is present"<<endl:cout<<"Not present"<<endl;
            break;
        }
        case 7:
        {
            cout<<"Enter node.."<<endl;
            int k;
            cin>>k;
            int fl=floor(root,k);
            int cl=ceil(root,k);
            fl==INT_MAX?cout<<"Floor=NULL"<<endl:cout<<"Floor="<<fl<<endl;
            cl==-1?cout<<"Ceil =NULL"<<endl:cout<<"Ceil ="<<cl<<endl;
            break;
        }
        case 8:
            {
                inorder(root);
                    cout<<endl;
                    descending(root);
                  cout<<endl;
                    break;


            }
        default:
        return 0;
    }
    goto l;

}
