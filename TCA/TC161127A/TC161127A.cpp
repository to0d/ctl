#include <lt_help/lt.h>

int findShortPath_dijkstra(vector<vector<int>>& graph, int from, int to, vector<int>& path) {
    int size = graph.size();
    if( from == to || size <= 1)
        return 0;

    vector<int> index_queue, weigth_to, edge_to;
    for(int i = 0; i < size ; ++i)
    {   int v = graph[from][i];
        if( v == -1 )
            v = INT_MAX;
        weigth_to.push_back(v);
        edge_to.push_back(from); 
        if( i != from )
            index_queue.push_back(i);
    }

    vector<int> rst;
    while( !index_queue.empty())
    {   int qsize = index_queue.size();
        // bubble sort, find the shortest node
        for(int i = 1; i < qsize; ++i)
        {   if( weigth_to[index_queue[i-1]] < weigth_to[index_queue[i]])
            {   int v = index_queue[i-1];
                index_queue[i-1] = index_queue[i];
                index_queue[i] = v;
            }
        }
        
        int pos = index_queue.back(); 
        index_queue.pop_back();

        int v = weigth_to[pos];
        if( v == INT_MAX )
            break;
        
        if( pos == to )
        {   path.clear();
            for(int k = to;  k != from; k = edge_to[k])
                path.push_back(k);
            path.push_back(from);
            std::reverse(path.begin(), path.end());
            return v;
        }
        
        for(int i = 0; i < qsize; ++i)
        {   int t = index_queue[i];
            int k = graph[pos][t];
            if( k > 0 &&( weigth_to[t] > ( v + k )) )
            {   weigth_to[t] = v + k;
                edge_to[t] = pos;
            }
        }
    }
    
    return -1;
}

void test(vector<vector<int>> graph, int from, int to)
{
    cout << "input: from=" << from << ", to=" << to << ", graph=";
    outputVector(graph);
    vector<int> path;
    int r = findShortPath_dijkstra(graph, from, to, path);
    cout << "; output: r=" << r << ", path";
    outputVector(path);
    cout << ";" << endl;
}

int main( void )
{   
    test(
        {
            {  0 ,100,  10,  30,  -1, }, 
            {  -1,  0,  -1,  -1,  -1, }, 
            {  -1, -1,   0,  -1,  20, }, 
            {  -1, 10,  -1,   0,   8, }, 
            {  -1,  5,  -1,  -1,   0, }, 
        }, 0, 1
    );

    return 0;
}

