// Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <cstdio>
#include <stack>
using namespace std;
 
class Graph
{
    long long int V;    // No. of vertices
    list<long long int> *adj;    // An array of adjacency lists
    void fillOrder(long long int v, bool visited[], stack<long long int> &Stack);
     void DFSUtil(long long int v, bool visited[]);
public:
    Graph(long long int V);
    void addEdge(long long int v,long long int w);
     long long printSCCs();
 
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};
 
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list<long long int>[V];
}
 
// A recursive function to print DFS starting from v
void Graph::DFSUtil(long long int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 	//cout<<v<<" ";
    // Recur for all the vertices adjacent to this vertex
    list<long long int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph Graph::getTranspose()
{
    Graph g(V);
    for (long long int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<long long int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(long long int v, long long int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::fillOrder(long long int v, bool visited[], stack<long long int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<long long int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
 
    // All vertices reachable from v are processed by now, push v to Stack
    Stack.push(v);
}
 
// The main function that finds and prints all strongly connected components
long long Graph::printSCCs()
{
    stack<long long int> Stack;
    long long int count = 0; 
    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(long long i = 0; i < V; i++)
        visited[i] = false;
 
    // Fill vertices in stack according to their finishing times
    for(long long i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
 
    // Create a reversed graph
    Graph gr = getTranspose();
 
    // Mark all the vertices as not visited (For second DFS)
    for(long long i = 0; i < V; i++)
        visited[i] = false;
 
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        long long v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            count++;
        }
    }
    return count;
}
int main()
{
    long long int t,n,a,b,e;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        scanf("%lld",&e);
        
        if(e == 0) {
            printf("%lld\n",n);
            continue;
        }

        Graph g(n);
        for(long long i = 0; i < e; i++) {
            scanf("%lld %lld",&a,&b);
            g.addEdge(a, b);
            g.addEdge(b,a);
        }
        printf("%lld\n",g.printSCCs());
    }
    return 0;
}
