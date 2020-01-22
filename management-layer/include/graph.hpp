/*
 * graph.hpp
 */

namespace management {
  struct Edge {
    int src;
    int dest;
    int weight;
  };

  template <typename T>
  class Graph {
    // element i of edge_vect represent the outgoing edges
    // of i-esim node
    std::vector<std::vector<Edge>> edge_vect;
    // Each element of data_vect represent one node. Each node is
    // identified from it's index in this vector
    std::vector<T*> data_vect;
    std::size_t num_nodes;

  public:
    Graph(void);
    
    /*
     * add a new node in the graph.
     * Returns:
     *   positive integer representing the ID of the node if succesful
     *   negative integer if an error occurred
     */
    int add(T* t_data);
    /*
     * add a new edge between two existing nodes
     * Returns:
     *   0 if succesful
     *   -1 otherwise
     */
    int add_edge(int t_src, int t_dest);
    /*
     * remove the node identified by t_id index in the data_vect
     * and all edges related to him.
     * ISSUE: how do you remove incoming edges ???
     * Returns:
     *   0 if succesful
     *   -1 otherwise
     */
    int remove(int t_id);

    /*
     * remove the edge going from t_src node to t_dest node.
     * Returns:
     *   0 if succesful
     *   -1 otherwise
     */
    int remove_edge(int t_src, int t_dest);

    /*
     * Returns the list of available nodes
     */
    std::vector<int> nodes(void) const;

    /*
     * Returns:
     *   0 if t_id exists
     *   -1 otherwise
     */
    int find(int t_id) const;
    
    // TODO    
  };
}
