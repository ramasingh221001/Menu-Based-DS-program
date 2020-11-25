#include<bits/stdc++.h>
using namespace std;
struct node
{
	int row;
	int col;
	int val;
}st[100],trans[100];


//PRINT
void print(int n)
{

    cout<<"     ROW COL VAL  "<<endl;
	for(int i=0;i<n+1;i++)
    {
    	cout<<"      "<<st[i].row<<"   "<<st[i].col<<"   "<<st[i].val<<endl;
    }
}


//SIMPLE TRANSPOSE
struct node** simple_transpose(int n,int row,int col)
{
	struct node **tmp=(struct node**)malloc((n+1)*sizeof(*tmp));
	tmp[0]=(struct node*)malloc(sizeof(**tmp));
	tmp[0]->row=col;
	tmp[0]->col=row;
	tmp[0]->val=n;
	int count=1;

	for(int i=0;i<col;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(st[j].col==i)
			{
				tmp[count]=(struct node*)malloc(sizeof(**tmp));
				tmp[count]->row=st[j].col;
				tmp[count]->col=st[j].row;
				tmp[count]->val=st[j].val;
				count++;
			}
		}
	}

	return tmp;
}


//FAST TRANSPOSE
void  fast_transpose(int n,int row,int col)
{
	int count[col];
	memset(count,0,sizeof(count));
	for(int i=1;i<=n;i++)
	{
		count[st[i].col]++;
	}
	int start_p[col];
	start_p[0]=1;
	for(int i=1;i<col;i++)
	{
		start_p[i]=start_p[i-1]+count[i-1];
	}

    trans[0].row=st[0].col;
    trans[0].col=st[0].row;
    trans[0].val=st[0].val;

	for(int i=1;i<=n;i++)
	{
		int p=start_p[st[i].col];
		trans[p].row=st[i].col;
		trans[p].col=st[i].row;
		trans[p].val=st[i].val;
		start_p[st[i].col]++;

	}
	cout<<"** Transpose of given matrix **"<<endl;
    cout<<"      ROW COL VAL "<<endl;
	for(int i=0;i<=n;i++)
    {
    	cout<<"       "<<trans[i].row<<"  "<<trans[i].col<<"  "<<trans[i].val<<endl;
    }

}


//ADDITION

void add_op(struct node st1[],struct node st2[])
{
	int i=1,j=1,k=1;
	st[0].row=st1[0].row;
	st[0].col=st1[0].col;
	st[0].val=0;

	while(i<=st1[0].val && j<=st2[0].val)
	{
		if(st1[i].row==st2[j].row)
		{
			if(st1[i].col<st2[j].col)
			{
				st[k].row=st1[i].row;
				st[k].col=st1[i].col;
				st[k].val=st1[i].val;
				i++;
			}
			else if(st1[i].col==st2[j].col)
			{
				st[k].row=st1[i].row;
				st[k].col=st1[i].col;
				st[k].val=st1[i].val+st2[j].val;
				i++,j++;
			}
			else
			{
				st[k].row=st2[j].row;
				st[k].col=st2[j].col;
				st[k].val=st2[j].val;
				j++;
			}
			k++;
		}
		else if(st1[i].row<st2[j].row)
		{
			st[k].row=st1[i].row;
			st[k].col=st1[i].col;
			st[k].val=st1[i].val;
			i++,k++;
		}
		else
		{
			st[k].row=st2[j].row;
			st[k].col=st2[j].col;
			st[k].val=st2[j].val;
			j++,k++;
		}
	}

	if(i>st1[0].val)
	{
		while(j<=st2[0].val)
		{
			st[k].row=st2[j].row;
			st[k].col=st2[j].col;
			st[k].val=st2[j].val;
			j++,k++;
		}
	}
	else
	{
		while(i<=st1[0].val)
		{
			st[k].row=st1[i].row;
			st[k].col=st1[i].col;
			st[k].val=st1[i].val;
			i++,k++;

		}
	}
	st[0].val=k-1;
	cout<<"** Matrix after addition **"<<endl;
	print(k-1);
}

void add_input()
{
	int el1,el2;
	cout<<"Enter details for 1st matrix..."<<endl;
	cout<<"No. of non-zero element: "<<endl;
	cin>>el1;
	struct node st1[el1+1];
	cout<<"No. of rows:"<<endl;
	cin>>st1[0].row;
	cout<<"No. of column: "<<endl;
	cin>>st1[0].col;
	st1[0].val=el1;
	cout<<"Enter row,column and value: "<<endl;
	for(int i=1;i<=el1;i++)
	{
		cin>>st1[i].row>>st1[i].col>>st1[i].val;
	}

	cout<<"Enter details for 2nd matrix..."<<endl;
	cout<<"No. of non-zero element: "<<endl;
	cin>>el2;
	struct node st2[el2+1];
	cout<<"No. of rows:"<<endl;
	cin>>st2[0].row;
	cout<<"No. of column: "<<endl;
	cin>>st2[0].col;
	st2[0].val=el2;
	cout<<"Enter row,column and value: "<<endl;
	for(int i=1;i<=el2;i++)
	{
		cin>>st2[i].row>>st2[i].col>>st2[i].val;
	}

	if(st1[0].row!=st2[0].row || st1[0].col!=st2[0].col)
	{
		cout<<"Addition not applicable"<<endl;
	}
	else
	{
		add_op(st1,st2);
	}

}


//MULTIPLICATION
void multiplication(struct node st1[])
{
	fast_transpose(st[0].val,st[0].row,st[0].col);
	int row=st1[0].row;
	int col=trans[0].row;
	st[0].row=row;
	st[0].col=col;
	int cur=1,cura,curb,sum;

	for(cura=1;cura<=st1[0].val; )
	{
		int r=st1[cura].row;
		for(curb=1;curb<=trans[0].val; )
		{
			int tmpa=cura,tmpb=curb,sum=0,c=trans[curb].row;
			while(tmpa<=st1[0].val && tmpb<=trans[0].val && st1[tmpa].row==r && trans[tmpb].row==c)
			{
				if(st1[tmpa].col==trans[tmpb].col)
				{
					sum+=(st1[tmpa].val * trans[tmpb].val);
					tmpa++,tmpb++;
				}
				else if(st1[tmpa].col<trans[tmpb].col)
				{
					tmpa++;
				}
				else
				{
					tmpb++;
				}
			}

			if(sum!=0)
			{
				st[cur].row=r;
				st[cur].col=c;
				st[cur].val=sum;
				cur++;
			}

			while(curb<=trans[0].val && trans[curb].row==c)
			{
				curb++;
			}

		}
		while(cura<=st1[0].val && st1[cura].row==r)
			{
				cura++;
			}

	}
	st[0].val=cur-1;
	cout<<"** Matrix after multiplication **"<<endl;
	print(cur-1);

}



void mul_input()
{
	int el1,el2;
	cout<<"Enter details for 1st matrix..."<<endl;
	cout<<"No. of non-zero element: "<<endl;
	cin>>el1;
	struct node st1[el1+1];
	cout<<"No. of rows:"<<endl;
	cin>>st1[0].row;
	cout<<"No. of column: "<<endl;
	cin>>st1[0].col;
	st1[0].val=el1;
	cout<<"Enter row,column and value: "<<endl;
	for(int i=1;i<=el1;i++)
	{
		cin>>st1[i].row>>st1[i].col>>st1[i].val;
	}

	cout<<"Enter details for 2nd matrix..."<<endl;
	cout<<"No. of non-zero element: "<<endl;
	cin>>el2;
	//struct node st2[el2+1];
	cout<<"No. of rows:"<<endl;
	cin>>st[0].row;
	cout<<"No. of column: "<<endl;
	cin>>st[0].col;
	st[0].val=el2;
	cout<<"Enter row,column and value: "<<endl;
	for(int i=1;i<=el2;i++)
	{
		cin>>st[i].row>>st[i].col>>st[i].val;
	}

	if(st1[0].row!=st[0].col)
		cout<<"Multiplication not applicable"<<endl;
	else
		multiplication(st1);
}




//INSERT
void insert()
{
	int col,row,n;
	cout<<"Enter no. of Row: "<<endl;
    cin>>row;
    cout<<"Enter the no. of Column: "<<endl;
    cin>>col;
    cout<<"Enter the no. of non-zero element"<<endl;
    cin>>n;
    st[0].row=row;
    st[0].col=col;
    st[0].val=n;
    cout<<"Enter row,column and value: "<<endl;
    for(int i=1;i<n+1;i++)
    {
    	cin>>st[i].row>>st[i].col>>st[i].val;
    }
    cout<<"Data sucessfully inserted.."<<endl;
}


int main()
{

    l:
	cout<<"\t ------------MENU--------"<<endl;
	cout<<"   PRESS 1. INSERT ELEMENT"<<endl;
	cout<<"   PRESS 2. SIMPLE TRANSPOSE"<<endl;
	cout<<"   PRESS 3. FAST TRANSPOSE"<<endl;
	cout<<"   PRESS 4. ADDITION"<<endl;
	cout<<"   PRESS 5. MULTIPLICATION"<<endl;
	cout<<"   PRESS ANY OTHER KEY TO EXIT...."<<endl;
	int op2;
	cin>>op2;
	switch(op2)
	{
		case 1:
		{
			insert();
			break;
		}
		case 2:
		{
			struct node **tmp=simple_transpose(st[0].val,st[0].row,st[0].col);
			cout<<"** Transposeof given matrix ** "<<endl;
			cout<<"      ROW COL VAL "<<endl;
	        for(int i=0;i<=tmp[0]->val;i++)
            {
    	       cout<<"       "<<tmp[i]->row<<"   "<<tmp[i]->col<<"   "<<tmp[i]->val<<endl;
            }
            break;
		}
		case 3:
		{
			fast_transpose(st[0].val,st[0].row,st[0].col);
			break;
		}
		case 4:
		{
			add_input();
			break;
		}
		case 5:
		{
			mul_input();
			break;
		}
		default:
		return 0;

	}
	cout<<"Press 1 to coinue.. or 0 to exit.."<<endl;
	int op3;
	cin>>op3;
	if(op3==1)
	goto l;

    return 0;
}
