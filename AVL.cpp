#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
node *root=NULL;
int height(node *tmp)
{
    if(tmp==NULL)
    return -1;
    else
    return tmp->height;
}

int balance_factor(node *tmp)
{
    if(tmp==NULL)
    return 0;
    else
    {
        return height(tmp->left)-height(tmp->right);
    }
}

int balance_factort(node *tmp)
{
    if(tmp==NULL)
    return 0;
    else
    {
        return height(tmp->left)-height(tmp->right);
    }
}

void preorder(node *root)
{
    if(root)
    {
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
    }
}





node* Right_rotate(node *tmp)
{

    node* u = tmp->left;
    tmp->left = u->right;
    u->right = tmp;
    tmp->height = max(height(tmp->left), height(tmp->right))+1;
    u->height = max(height(u->left), tmp->height)+1;
    return u;
}


 node* Left_rotate(node *tmp)
 {
    node* u = tmp->right;
    tmp->right = u->left;
    u->left = tmp;
    tmp->height = max(height(tmp->left), height(tmp->right))+1;
    u->height = max(height(tmp->right), tmp->height)+1 ;
    return u;
 }


node* Right_left_rotate(node *tmp)
{
    tmp->right = Right_rotate(tmp->right);
    return Left_rotate(tmp);
}


node* Left_right_rotate(node *tmp)
{
    tmp->left = Left_rotate(tmp->left);
    return Right_rotate(tmp);
}

node* insert(node *root,int x)
{
    if(root==NULL)
    {
        root=new node();
        root->data = x;
        root->height = 0;
        root->left =root->right = NULL;
    }
    else if(x<root->data)
    {
        root->left = insert(root->left,x);
        if(balance_factor(root)==2)
        {
            if(x <root->left->data)
                root=Right_rotate(root);
            else
                root=Left_right_rotate(root);
        }
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
        if(balance_factor(root)==-2)
        {
            if(x>root->right->data)
                root=Left_rotate(root);
            else
                root=Right_left_rotate(root);
        }
    }

    root->height=max(height(root->left),height(root->right))+1;
    return root;
}

node* predecessor(node *tmp)
{
    node *tmp1=tmp;
    while(tmp)
    {
        tmp1=tmp;
        tmp=tmp->right;
    }
return tmp1;
}


node* remove(node *root,int val)
{
    if(root==NULL)
    return NULL;
    else if(root->data>val)
    {
        root->left=remove(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=remove(root->right,val);
    }
    else if(root->left && root->right)
    {
        node *tmp=predecessor(root->left);
        root->data=tmp->data;
        root->left=remove(root->left,tmp->data);
    }
    else
    {
        if(root->left==NULL)
        root=root->right;
        else
        root=root->left;
    }

    if(root==NULL)
    return NULL;

    root->height=max(height(root->left),height(root->right))+1;

//left unbalanced
    if(balance_factor(root)==2)
    {
        if(balance_factor(root->left)==1) //Left-Left
        return Right_rotate(root);
        else
        return Left_right_rotate(root); // Left-Right
    }

//right unbalanced
    if(balance_factor(root)==-2)
    {
        if(balance_factor(root->right)==-1) //Right-right
        {
            return Left_rotate(root);
        }
        else
        {
            return Right_left_rotate(root); //right-left
        }

    }
    return root;

}

int main()
{

    cout<<"\n \t ------------AVL TREE------------"<<endl;
    cout<<"       1.Insertion"<<endl;
    cout<<"       2.Traversal"<<endl;
    cout<<"       3.Deletion"<<endl;
    cout<<"\n \t --------------------------------"<<endl;
   l: cout<<"Enter ur choice (Main Menu)..."<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            cout<<"Enter the no. of element u want to insert"<<endl;
            int n;
            cin>>n;
            cout<<"Please Enter Ur Elements"<<endl;
            while(n--)
            {
                int val;
                cin>>val;
                root=insert(root,val);
            }
            cout<<"Data Sucessfully inserted"<<endl;
            break;
        }
        case 2:
        {
            cout<<"    --------- Travesral -------------"<<endl;
            cout<<"        1.Pre-Order"<<endl;
            cout<<"        2.In-Order"<<endl;
            cout<<"        3.Post-Order"<<endl;
            cout<<"    -----------------------"<<endl;
           l1: cout<<"choose ur option( Traversal Menu)..."<<endl;
            int op;
            cin>>op;
            switch(op)
            {
                case 1:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    preorder(root);
                    break;
                }
                case 2:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    inorder(root);
                    break;
                }
                case 3:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    postorder(root);
                    break;
                }

            }
            cout<<"press 1 to continue or any other key to exit"<<endl;
            int ch;
            cin>>ch;
            if(ch==1)
            goto l1;
            break;
        }
        case 3:
        {
            cout<<"Enter data which u want to delete"<<endl;
            int val;
            cin>>val;
            root=remove(root,val);
            cout<<"Data Sucessfully deleted"<<endl;
            break;
        }
        default:
        return 0;
    }
    goto l;
}
