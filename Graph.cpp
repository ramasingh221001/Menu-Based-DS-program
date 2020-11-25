#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > adj[1000];
int n,e;

//Insert
void insert()
{
    cout<<"Enter no. of vertices and edge"<<endl;
    cin>>n>>e;
    cout<<"Enter v1,v2and weight"<<endl;
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back(make_pair(w,v2));
    }
cout<<"Data inserted sucessfully"<<endl;
}
void bfs(vector<pair<int,int> > vt[],int n)
{
    queue<int> qu;
    qu.push(0);
    bool visit[n];
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    while(!qu.empty())
    {
        int v=qu.front();
        qu.pop();
        cout<<v<<" ";
        for(int i=0;i<vt[v].size();i++)
        {
            if(!visit[vt[v][i].second])
            {
                qu.push(vt[v][i].second);
                visit[vt[v][i].second]=true;
            }
        }
    }
    cout<<endl;
}


//DFS
void dfs(vector<pair<int,int> > vt[],int n)
{
    stack<int> st;
    st.push(0);
    int visit[n];
    memset(visit,0,sizeof(visit));
    visit[0]=1;
    while(!st.empty())
    {
        int v=st.top();
        cout<<v<<" ";
        st.pop();
        for(int i=0;i<vt[v].size();i++)
        {
            if(visit[vt[v][i].second]==0)
            {
            st.push(vt[v][i].second);
            visit[vt[v][i].second]=1;
            }
        }
    }
    cout<<endl;
}

typedef pair<int,int> pr;
typedef pair<int,pr> PPR;


//PRIM'S
int prims(vector<pair<int,int> > vt[],int n)
{
   priority_queue<pr,vector<pr>,greater<pr> > pq;
   bool visit[n];
   memset(visit,false,sizeof(visit));
   pq.push(make_pair(0,0));
   int minsum=0;
   pr p;
   while(!pq.empty())
   {
       p=pq.top();
       pq.pop();
       int v=p.second,w=p.first;
       if(visit[v])
       continue;

       minsum+=w;
       visit[v]=true;
       for(int i=0;i<vt[v].size();i++)
       {
           if(!visit[vt[v][i].second])
           pq.push(vt[v][i]);
       }
   }

    return minsum;
}


//KRUSKAL

int root(int set[],int x)
{
    while(x!=set[x])
    {
        x=set[x];
    }
    return x;
}

void unin(int set[],int v1,int v2)
{
    set[v1]=v2;
}


int kruskal(vector<pr> vt[],int n,int e)
{
    PPR adj[e];
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int v2=vt[i][j].second;
            int w=vt[i][j].first;
            adj[k++]=make_pair(w,make_pair(i,v2));
        }
    }

    sort(adj,e+adj);
    int minsum=0;

    //set
    int set[n];
    for(int i=0;i<n;i++)
    {
        set[i]=i;
    }

    for(int i=0;i<e;i++)
    {
        int w=adj[i].first;
        pr p=adj[i].second;
        int v1=p.first;
        int v2=p.second;

        int root1=root(set,v1);
        int root2=root(set,v2);
        if(root1!=root2)
        {
            minsum+=w;
            unin(set,root1,root2);
        }
    }
return minsum;
}

void print(int wt[],int n)
{
    cout<<"Shortest distance between:-"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<"0--->"<<i<<"\t"<<wt[i]<<endl;
    }
}

//BELLMANFORD

void bellmanford(vector<pr> vt[],int n,int e)
{
   int wt[n];
   for(int i=0;i<n;i++)
   {
       wt[i]=INT_MAX;
   }

    wt[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<vt[j].size();k++)
            {
                int w=vt[j][k].first;
                int v2=vt[j][k].second;
                if(wt[j]!=INT_MAX && (wt[j]+w)<wt[v2])
                wt[v2]=wt[j]+w;
               // cout<<wt[v2]<<" ";
            }
        }

    }

    //check for -ve cycle
    int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int w=vt[i][j].first;
            int v2=vt[i][j].second;
            if(wt[i]!=INT_MAX && (wt[i]+w)<wt[v2])
            {
                s=1;
                break;
            }
        }
        if(s==1)
        break;
    }

    if(s==1)
    cout<<"Cycle is present"<<endl;
    else
    print(wt,n);

}


void dijkstra(vector<pr> vt[],int n)
{
    priority_queue<pr,vector<pr>,greater<pr> > pq;
    bool visit[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        visit[i]=false;
        dist[i]=INT_MAX;
    }
    dist[0]=0;

    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        pr p=pq.top();
        pq.pop();
        int v=p.second,w=p.first;
        if(visit[v])
        continue;

        visit[v]=true;
        for(int i=0;i<vt[v].size();i++)
        {
            int v2=vt[v][i].second;
            int w=vt[v][i].first;
            if(!visit[v2] && dist[v]!=INT_MAX && (dist[v]+w)<dist[v2])
            {
                dist[v2]=dist[v]+w;
                pq.push(make_pair(dist[v]+w,v2));
            }
        }

    }

    print(dist,n);

}

// Articulation Point

void dfs(int u,vector<pair<int,int> > vt[],int low[],int dist[],bool visit[],int parent[])
{
    static int cur=0;
    int children=0;
    visit[u]=true;
    cur++;
    low[u]=cur;
    dist[u]=cur;
    for(int i=0;i<vt[u].size();i++)
    {
        int v=vt[u][i].second;
        if(!visit[v])
        {
            parent[v]=u;
            children++;
            dfs(v,vt,low,dist,visit,parent);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && children>1)
            cout<<u<<" ";
            if(parent[u]!=-1 && low[v]>=dist[u])
            cout<<u<<" ";
        }

        if(visit[v] && v!=parent[u])
        low[u]=min(low[u],dist[v]);
    }


}

void atpoint(vector<pair<int,int> > vt[],int n)
{
    int low[n],dist[n],parent[n];
    bool visit[n];
    for(int i=0;i<n;i++)
    {
        visit[i]=false;
        parent[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        dfs(i,vt,low,dist,visit,parent);

    }
    cout<<endl;
}

//topological Sort
typedef pair<int,int> pr;

void topsort(vector<pr> vt[],int n)
{
    int incedge[n],visit[n];
    for(int i=0;i<n;i++)
    {
        incedge[i]=0;
        visit[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int v=vt[i][j].second;
            incedge[v]++;
        }
    }

    queue<int> qu;
    for(int i=0;i<n;i++)
    {
        if(incedge[i]==0){
            qu.push(i);
            visit[i]=1;}
    }

    while(!qu.empty())
    {
        int v=qu.front();
        cout<<v<<" ";
        qu.pop();
        for(int i=0;i<vt[v].size();i++)
        {
            int v2=vt[v][i].second;
            incedge[v2]--;
        }

        for(int i=0;i<n;i++)
        {
            if(incedge[i]==0 && visit[i]==0)
            {
                qu.push(i);
                visit[i]=1;
            }
        }
    }

    //cycle
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            cout<<"Graph is cyclic";
            break;
        }
    }
cout<<endl;
}


int main()
{

    cout<<"\n ---------GRAPH -------------"<<endl;
    cout<<"  1.Insert"<<endl;
    cout<<"  2.BFS"<<endl;
    cout<<"  3.DFS"<<endl;
    cout<<"  4.Min Spanning Tree"<<endl;
    cout<<"  5.Single Source Shortest Path"<<endl;
    cout<<"  6.Articulation Point"<<endl;
    cout<<"  7.Topological Sort"<<endl;
    cout<<"\n-------------------------------"<<endl;
    l: cout<<"Enter ur choice...!!!"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            bfs(adj,n);
            break;
        }
        case 3:
        {
            dfs(adj,n);
            break;
        }
        case 4:
        {   cout<<"\n\t---------------------"<<endl;
            cout<<"\n\t 1.Prims"<<endl;
            cout<<"\n\t 2.Kruskal"<<endl;
            cout<<"\n\t--------------------"<<endl;
           l2: cout<<"\n\t Enter ur choice (MST).."<<endl;
            int ch1;
            cin>>ch1;
            switch(ch1)
            {
                case 1:
                {
                    int res=prims(adj,n);
                    cout<<"Minmum Spaning tree weight:"<<res<<endl;
                    break;
                }
                case 2:
                {
                    int res=kruskal(adj,n,e);
                    cout<<"Minimum Spanning Tree weight:"<<res<<endl;
                    break;
                }
            }

            /*cout<<"1. MST Menu"<<endl;
            int b;
            if(b==1)
            goto l2;
            else goto l; */
            break;
        }
        case 5:
        {
            cout<<"\n\t---------------------"<<endl;
            cout<<"\n \t 1.Bellman Ford"<<endl;
            cout<<"\n\t  2.Dijkstra's"<<endl;
            cout<<"\n\t---------------------"<<endl;
            cout<<"\n\t Enter ur choice.."<<endl;
            int ch;
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    bellmanford(adj,n,e);
                    break;
                }
                case 2:
                {
                    dijkstra(adj,n);
                    break;
                }
            }
            break;

        }

                case 6:
                    {
                        atpoint(adj, n);
                         break;
                    }
                case 7:
                    {
                        topsort(adj, n);
                    }

              default:
            break;
    }
    goto l;
    return 0;

}
