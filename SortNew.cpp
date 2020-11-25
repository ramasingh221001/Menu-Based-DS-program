#include<iostream>
using namespace std;

int create(int a[])
{
    int n;
    cout<<"\t Enter Number of Elements You Want to Sort\t"<<endl;
    cout<<"\t";
    cin>>n;
    cout<<"\t Now, Enter the Elements You Want to Sort\t"<<endl;
     for (int i=0;i<n;i++)
     {
         cout<<"\t";
        cin>>a[i];
     }
     return n;
}
// Display Elements
int display(int a[],int n)
{
    for (int i=0;i<n;i++)
        cout<<"\t     "<<a[i];
}

// Bubble Sort
int bubbleSort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
          {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
          }
      }
  }
}

// Selection sort
int selectionSort(int a[], int n)
{
    int temp;
for (int i = 0; i < (n - 1); i++)
  {
    int pos= i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[pos] > a[j])
        pos = j;
    }
    if (pos != i)
    {
      temp= a[i];
      a[i] = a[pos];
      a[pos] = temp;
    }
  }

}

//Insertion sort
void insertionSort(int a[],int n)
{
    int i,j,min;
    for(i=1;i<n;i++)
    {
        min=a[i];
        j=i-1;
        while(min<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=min;
    }
}

// Merge Algorithm
int merge(int a[],int i1,int j1, int i2,int j2)
{
int temp[50];
int i,j,k;
i=i1;
j=i2;
k=0;
while(i<=j1&&j<=j2)
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1)
temp[k++]=a[i++];
while(j<=j2)
temp[k++]=a[j++];
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}

// Merge Sort
 int mergeSort(int a[],int i, int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergeSort(a,i,mid);
mergeSort(a,mid+1,j);
merge(a,i,mid,mid+1,j);
}
}

// partiotion algorithm
int partition(int a[],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
do
{
do
{
i++;
}while(a[i]<v&&i<=u);
do
{
j--;
}while(a[j]>v);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}
// Quick sort
int quickSort(int a[],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);
quickSort(a,l,j-1);
quickSort(a,j+1,u);
}
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int a[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (a[i]/exp)%10 ]++;
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
// Radix Sort
int radixsort(int a[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(a, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(a, n, exp);
}
//shell short
int shellSort(int a[], int n)
{
    for (int h = n/2; h > 0; h /= 2)
    {

        for (int i = h; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= h && a[j- h] > temp; j -= h)
                a[j] = a[j - h];

            //  put temp (the original a[i]) in its correct location
            a[j] = temp;
        }
    }
}



int main()
{

    int a[50],n;
    cout<<"\n \t ---------  WELCOME   -----------"<<endl;
   /* cout<<"\t Enter Number of Elements You Want to Sort\t"<<endl;
    cout<<"\t";
    cin>>n;
    cout<<"\t Now, Enter the Elements You Want to Sort\t"<<endl;
     for (int i=0;i<n;i++)
     {
         cout<<"\t";
        cin>>a[i];
     }
     */
     cout<<"\t  -----------------------------"<<endl;
    cout<<"\t 1. Bubble sort"<<endl;
    cout<<"\t 2. Selection Sort"<<endl;
    cout<<"\t 3. Insertion Sort"<<endl;
    cout<<"\t 4. Merge sort"<<endl;
    cout<<"\t 5. Quick sort"<<endl;
    cout<<"\t 6. Radix sort"<<endl;
    cout<<"\t 7. Shell sort"<<endl;
    cout<<"\t 8. create"<<endl;
    cout<<"\t 9. Display Array"<<endl;
    cout<<"\t 10. Exit"<<endl;
    cout<<"\t -----------------------------"<<endl;
   l: cout<<" \n \t   Enter Your Choice: \t ";
       int ch;
      cin>>ch;
   switch(ch)
    {
    case 1:
        bubbleSort(a,n);
        cout<<"\t   After Bubble sort Elements are : "<<endl;
        display(a,n);
        break;
    case 2:
        selectionSort(a,n);
         cout<<"\t    After Selection sort Elements are :\t"<<endl;
         display(a,n);
        break;
    case 3:
        insertionSort(a,n);
        cout<<"\t    After Insertion sort Elements are :\t "<<endl;
display(a,n);
        break;
    case 4:
        mergeSort(a,1,n);
        cout<<"\t    After Merge Sort:\t"<<endl;
        display(a,n);
        break;
    case 5:
        quickSort(a,1,n);
        cout<<"\t    After Quick Sort:\t"<<endl;
        display(a,n);
        break;
    case 6:
        radixsort(a,n);
        cout<<"\t    After Radix Sort:\t"<<endl;
        display(a,n);
        break;
    case 7:
        shellSort(a,n);
        cout<<"\t    After shell Sort:\t"<<endl;
        display(a,n);
        break;
    case 8:
        n=create(a);
        break;
    case 9:
        display(a,n);
        break;
    default:
         return 0;
    }
   goto l;

}
