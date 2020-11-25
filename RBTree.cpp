#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right,*parent;
    bool color;
};
node *root=NULL;

//LEFT ROTATION
void rotate_left(node *&root,node *&tmp)
{
    node *tmp_right=tmp->right;
    tmp->right=tmp_right->left;

    if (tmp->right != NULL)
        tmp->right->parent =tmp;

    tmp_right->parent = tmp->parent;

    if (tmp->parent == NULL)
        root = tmp_right;

    else if (tmp == tmp->parent->left)
        tmp->parent->left = tmp_right;

    else
        tmp->parent->right = tmp_right;

    tmp_right->left =tmp;
    tmp->parent = tmp_right;

}

///RIGHT ROTATION
void right_rotate(node *&root,node *&tmp)
{
    node *tmp_left =tmp->left;

    tmp->left =tmp_left->right;

    if (tmp->left != NULL)
        tmp->left->parent =tmp;

    tmp_left->parent =tmp->parent;

    if (tmp->parent == NULL)
        root = tmp_left;

    else if (tmp==tmp->parent->left)
        tmp->parent->left = tmp_left;

    else
        tmp->parent->right =tmp_left;

    tmp_left->right =tmp;
    tmp->parent =tmp_left;
}

//FIXING RB_TREE PROPERTY VIOLATION
void Fix_violation(node *&root,node *&tmp)
{
    node *parent_tmp=NULL;
    node *grandpa_tmp=NULL;
    while(tmp!=root && tmp->color!=false && tmp->parent->color==true)
    {
        parent_tmp=tmp->parent;
        grandpa_tmp=tmp->parent->parent;

        if(parent_tmp==grandpa_tmp->left) //pushed in left
        {
            node *uncle_tmp=grandpa_tmp->right;

            //case-1(Uncle is RED)
            if(uncle_tmp!=NULL && uncle_tmp->color==true)
            {
                grandpa_tmp->color=true;
                parent_tmp->color=false;
                uncle_tmp->color=false;
                tmp=grandpa_tmp;
            }

            else
            {
                //case-2 (Uncle is Black(left-right))
                if(tmp==parent_tmp->right)
                {
                    rotate_left(root,parent_tmp);
                    tmp=parent_tmp;
                    parent_tmp=tmp->parent;
                }

                //case-3 (Uncle is Black(right-right))
                right_rotate(root,grandpa_tmp);
                swap(parent_tmp->color,grandpa_tmp->color);
                tmp=parent_tmp;
            }

        }

        else //pushed in right
        {
            node *uncle_tmp=grandpa_tmp->left;

            //case-1 (Uncle is RED)
            if(uncle_tmp!=NULL && uncle_tmp->color==true)
            {
                grandpa_tmp->color=true;
                parent_tmp->color=false;
                uncle_tmp->color=false;
                tmp=grandpa_tmp;
            }

            else
            {
                //case-2; (Uncle is Black(right-left rotate))
                if(tmp==parent_tmp->left)
                {
                    right_rotate(root,parent_tmp);
                    tmp=parent_tmp;
                    parent_tmp=tmp->parent;
                }

                //case-3 (Uncle is Black(left rotate))
                rotate_left(root,grandpa_tmp);
                swap(parent_tmp->color,grandpa_tmp->color);
            }
        }
    }
    root->color=false;
}


//NEW NODE
node* newnode(int val)
{
    struct node *tmp=new node();
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->parent=NULL;
    tmp->color=true; //true=RED,false=BLACK
    return tmp;
}

//BINARY SEARCH TREE INSERTION
node* RB_insert(node *root,node *tmp)
{
    if(root==NULL)
    return tmp;
    else if(root->data>tmp->data)
    {
        root->left=RB_insert(root->left,tmp);
        root->left->parent=root;
    }
    else if(root->data<tmp->data)
    {
        root->right=RB_insert(root->right,tmp);
        root->right->parent=root;
    }
    return root;
}

//INSERT
node* insert()
{
    cout<<"Enter the no. of elements"<<endl;
    int n;
    cin>>n;
    while(n--)
    {
        int val;
        cin>>val;
        node *tmp=newnode(val);
        root=RB_insert(root,tmp);
        Fix_violation(root,tmp);
    }
    return root;
}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" "<<"color:";
        root->color?cout<<"Red"<<endl:cout<<"Black"<<endl;
        inorder(root->right);
    }
}


int main()
{

      cout<<"------------RB TREE-------"<<endl;
    cout<<"1.Insert "<<endl;
    cout<<"2.Traverse"<<endl;
   l: cout<<"--------------------------"<<endl;
  cout<<"Enter ur choice ...!!!"<<endl;
    int ch;
     cin>>ch;
    switch(ch)
    {
        case 1:
        {
            root=insert();
            cout<<"Data Insterted Successfully"<<endl;
            break;
        }
        case 2:
        {
            inorder(root);
            break;
        }
        default:
        break;
    }
    goto l;
    return 0;
}
