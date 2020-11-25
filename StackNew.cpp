#include<bits/stdc++.h>
using namespace std;
int TOP=-1;
//push
void push1(int stack[])
{
      int n;
      cout << "Enter the no of elements : ";
      cin >> n;

      if(TOP==n-1){
        cout<<"\t  Overflow" <<endl;}
      else
      {
       cout<< "\t  Enter the elements"<<endl;
       int item;
       while(n--)
       {
        cin>>item;
        TOP=TOP+1;
        stack[TOP]=item;
      // size--;
       }
      }
      //cout << "at";
}
//display
 int display(int stack[],int size )
{

        if(TOP==-1)
        {
                cout<<"\t  Stack is Empty:"<<endl;
        }
        else
        {
        cout<<"\t  The stack elements are:\n" <<endl;
        for(size=TOP;size>=0;size--)
        {
                cout<<"\n"<<stack[size]<<endl;
        }
        }
        return size;
}
//pop
void pop(int stack[])
{
    int item;
      if(TOP==-1)
        cout<<"\t  underflow"<<endl;
      else
        {
            item=stack[TOP];
            TOP=TOP-1;
            cout<<"\t Item deleted"<<item<<endl;
        }
}
//priority
int priority(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else
    return 1;
}
// string infix to postfix
string inf_post(string str)
{
    stack<char> st;
    string output;
    for(int i=0;i<str.size();i++)
    {
      if(str[i]=='^' || str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-')
        {
            if(!st.empty() && priority(st.top())>=priority(str[i]))
            {
                while(!st.empty() && st.top()!='(' && priority(st.top())>=priority(str[i]))
                {
                    output+=st.top();
                    st.pop();
                }
            }
            st.push(str[i]);
        }
        else if(str[i]==')' || str[i]=='(')
        {
            if(str[i]==')')
            {
            while(st.top()!='(')
            {
                output+=st.top();
                st.pop();
            }
            st.pop();
            }
            else
            {
                st.push(str[i]);
            }

        }
        else
        {
            output+=str[i];
        }
    }
    while(!st.empty())
    {
        output+=st.top();
        st.pop();
    }
    return output;

}

int operate(int a,int b,char c)
{
    if(c=='^')return a^b;
    else if(c=='*')return a*b;
    else if(c=='/')return a/b;
    else if(c=='+')return a+b;
    else return a-b;


}

int evaluate(string str)
{
    stack<int> st;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='^' || str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-')
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int val=operate(b,a,str[i]);
            st.push(val);
        }
        else
        {
            st.push(str[i]-'0');
        }

    }
    return st.top();
}

int next_greater(int arr[],int n)
{ int a[100];
    for(int i=0;i<n;i++)
     a[i]= arr[i];
	stack<int> st;
	st.push(0);
	for(int i=1;i<n;i++)
	{
		if(arr[st.top()]<arr[i])
		{
			while(!st.empty() && arr[st.top()]<arr[i])
			{
				arr[st.top()]=arr[i];
				st.pop();
			}

		}
		st.push(i);
	}

	if(!st.empty())
	{
		while(!st.empty())
		{
			arr[st.top()]=-1;
			st.pop();
		}
	}
    // print */
    cout<<"Next Greater Element is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"---> "<<arr[i]<<endl;
	}
	cout<<endl;
}

int main()
{
    int stack[10],n;
    string res;
    cout<<"\t----------------STACK OPPERATION--------"<<endl;
    cout<<"\t 1. PUSH "<<endl;
    cout<<"\t 2. POP "<<endl;
    cout<<"\t 3. DISPLAY"<<endl;
    cout<<"\t 4. INFIX TO POSTFIX"<<endl;
    cout<<"\t 5. POSTFIX EVALUATION"<<endl;
    cout<<"\t 6. NEXT GREATER ELEMENT"<<endl;
    cout<<"\t -----------------------------"<<endl;
   l: cout<<" \n \t   Enter Your Choice: \t ";
     int ch;
      cin>>ch;
      
      switch(ch)
      {
      case 1:
      {
               //cout << "Enter the no of elements : ";
              // cin >> n;
               push1(stack);
               cout << "t";
               break;
      }
      case 2:
      {
               pop(stack);
               break;
      }
      case 3:
      {
               display(stack,n);
               break;
      }
      case 4:
          {
               cout<<"\t Enter Expression: \t";
               cout<<"\t    ";
               string str;
               cin>>str;
               res=inf_post(str);
               cout<<"\t Postfix Expression: "<<res<<endl;
               break;
            }
      case 5:
      {
               int res1 ;
               res1 = evaluate(res);
               cout<<"\t    The Result is: "<<res1<<endl;
               break;
      }
      case 6:
      {
              int num;
              cout<<"\t   Enter the no. of elements: "<<endl;
              cin>>num;
              int arr[num];
	          cout<<"\t   Enter elements: "<<endl;
	          for(int i=0;i<num;i++)
		          cin>>arr[i];
              next_greater(arr,num);
               break;

      }
    }
    goto l;
    return 0;
}
