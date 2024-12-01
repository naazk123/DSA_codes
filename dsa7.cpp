#include <iostream>
using namespace std;
struct edge;
struct vertex
{
    string city;
    int visited;
};
struct edge
{
    string city1;
    string city2;
    int cost;
};
class Mst
{
public:
    void initialize(vertex *vertices, int v)
    {
        cout << "CITY INFO : " << endl;
        for (int i = 0; i < v; i++)
        {
            cout << "Enter the name of city " << i + 1 << " : " << endl;
            cin >> (vertices[i].city);
            vertices[i].visited = 0;
        }
    }
    int visited(vertex *vertices, int v, string city)
    {
        for (int i = 0; i < v; i++)
        {
            if (vertices[i].city == city)
                return vertices[i].visited;
        }
    }
    void setvisited(vertex *vertices, int v, string city)
    {
        for (int i = 0; i < v; i++)
        {
            if (vertices[i].city == city)
                vertices[i].visited = 1;
        }
    }
    string neighbor(string city1, string city2, edge *selected, int edgesInTree)
    {
        int flag = 0;
        for (int i = 0; i < edgesInTree; i++)
        {
            if (selected[i].city1 == city1 || selected[i].city2 == city1)
            {
                if (selected[i].city1 == city1 && selected[i].city2 != city2)
                {
                    return selected[i].city2;
                    flag = 1;
                }
                else if (selected[i].city2 == city1 &&
                         selected[i].city1 != city2)
                {
                    return selected[i].city1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            return "done";
    }
    void collect(edge *edges, int e)
    {
        cout << "LEASELINE INFO : " << endl;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter the name of city 1 : " << endl;
            cin >> edges[i].city1;
            cout << "Enter the name of city 2 : " << endl;
            cin >> edges[i].city2;
            cout << "Enter the cost of lease line : " << endl;
            cin >> edges[i].cost;
        }
    }
    void sort(edge *edges, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (edges[j].cost > edges[j + 1].cost)
                {
                    string c1 = edges[j].city1;
                    string c2 = edges[j].city2;
                    int c = edges[j].cost;
                    edges[j].city1 = edges[j + 1].city1;
                    edges[j].city2 = edges[j + 1].city2;
                    edges[j].cost = edges[j + 1].cost;
                    edges[j + 1].city1 = c1;
                    edges[j + 1].city2 = c2;
                    edges[j + 1].cost = c;
                }
            }
        }
    }
    void select(vertex *vertices, int v, edge *edges, int e)
    {
        edge *selected = new edge[v - 1];
        int edgesInTree = 0;
        int c = 0;
        for (int i = 0; i < e; i++)
        {
            if (edgesInTree < v - 1)
            {
                if (visited(vertices, v, edges[i].city1) == 0 ||
                    visited(vertices, v, edges[i].city2) == 0)
                {
                    selected[c].city1 = edges[i].city1;
                    selected[c].city2 = edges[i].city2;
                    selected[c].cost = edges[i].cost;
                    setvisited(vertices, v, edges[i].city1);
                    setvisited(vertices, v, edges[i].city2);
                    c++;
                    edgesInTree++;
                }
                else
                {
                    string t1 = edges[i].city1;
                    string t2 = edges[i].city2;
                    string n1 = neighbor(t1, t2, selected, edgesInTree);
                    cout << "1 : " << n1 << endl;
                    string n2 = neighbor(t2, t1, selected, edgesInTree);
                    cout << "2 : " << n1 << endl;
                    while (n1 != n2 && n1 != "done" && n2 != "done")
                    {
                        string temp = n1;
                        string temp2 = n2;
                        n1 = neighbor(t1, n1, selected, edgesInTree);
                        n2 = neighbor(t2, n2, selected, edgesInTree);
                        t1 = temp;
                        t2 = temp2;
                    }
                    if (n1 == "done" || n2 == "done")
                    {
                        selected[c].city1 = edges[i].city1;
                        selected[c].city2 = edges[i].city2;
                        selected[c].cost = edges[i].cost;
                        setvisited(vertices, v, edges[i].city1);
                        setvisited(vertices, v, edges[i].city2);
                        c++;
                        edgesInTree++;
                    }
                }
            }
            else
                break;
        }
        for (int i = 0; i < edgesInTree; i++)
            cout << "Edge included : E[" << i << "] : " << selected[i].city1 << " -> " << selected[i].city2 << " = " << selected[i].cost << endl;
    }
};
int main()
{
    Mst mst;
    int v;
    cout << "Enter the number of cities : " << endl;
    cin >> v;
    struct vertex *vertices = new vertex[v];
    cout << "Enter the number of lease lines : " << endl;
    int e;
    cin >> e;
    struct edge *edges = new edge[e];
    mst.initialize(vertices, v);
    mst.collect(edges, e);
    mst.sort(edges, e);
    mst.select(vertices, v, edges, e);
    return 0;
}