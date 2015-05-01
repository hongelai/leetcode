#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <map>
#include <unordered_set>
#include <string.h>
#include <queue> 
#include <fstream>
#include <sstream>

using namespace std;
int min_index(int dist[V], int final[V]){
  int min = INT_MAX, min_index = -1;
  for (int i = 0; i < V; ++i)
  {
    if (!final[i] && dist[i] < min)
    {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}
vector<int> dijstra(int graph[V][V], int src){

  int dist[V];
  for (int i = 0; i < V; ++i)
  {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;

  for (int i = 0; i < V; ++i)
  {
    int min_index = min_index(dist, final);
    final[min_index]  = true;
    for (int w = 0; w < V; w++)
    {
      if (final[w] == false && graph[min_index][w] && dist[w] != INT_MAX &&  graph[min_index][w] + dist[min_index] < dist[w])
      {
        dist[w] = graph[min_index][w] + dist[min_index];
      }
    }
  }
}

int main ()
{

  // int a[] = {3,5,1,23,11,34,21};
  // vector<int> v(a,a+7);
  cout<<convertToTitle(3);
  return 0;
}
