#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>

/**
 * Class to represent generic graphs
 */
class Graph {
        private:
                /**
                 * adjacency list as the graph representation
                 */
                vector< vector<int> > adjacencyList;

        public:
                /**
                 * Constructor
                 */
                Graph(vector< vector<int> > list);

                /**
                 * Copy Constructor
                 */
                Graph(const Graph &rhs);

                /**
                 * Assignment Operator
                 */
                Graph& operator=(const Graph &rhs);


                /* Other public functions */

                /**
                 * Topological sort
                 */
                vector<int> toplogicalSort();
};

#endif /* __GRAPH_H__ */
