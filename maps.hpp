
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;
class Graph{
    private:
        vector < vector<float> > graph;
        int n;
    public:
        //Construct a adjacency matrix of size N initialised to infinite weights
        Graph(int N);
        //Read Size
        int getSize() const;

        //Print Graph

        void print() const;

        //Modify an edge value from i -> j with value w, option to change j-> at same time by setting twoWay to true
        void changeEdge(float w, int i, int j, bool twoWay);

        //Read weight from i ->j
        float getValue(int i, int j) const;

        //Initialise n/2 randomly weighted edge connections between store and random houses
        void storeHouseInitialisation();

        //Initialise "Ring Road" around houses
        void ringRoadInitialisation();

        //Initialise k * n random cross connections between houses

        void crossRoadInitialisation(float k);

        Graph randomWalk();

        vector<pair<vector<int>, float > > dijkstraWithPath(int source) const;
};


class Pipeline{
    private:
        vector<vector<int> > orders;
        int nOrders;
        int maxBaskets;
        int minBaskets;
        int nNodes;
    
    public:
        //Constructor
        Pipeline(int nNodes, int min, int max);

        //Initialise Orders
        void createOrders();

        //read only functions
        //Order numbers will go from 1 -> n orders, These are linked to the positions in orders container.
        vector<int> getOrder(int orderNum) const;
        vector<vector<int> > getAllOrders() const;
        int getNumberOrders() const;
        int getMaxBaskets() const;
        int getMinBaskets() const;
        void printOrders() const;

        void removeOrder(int house);
        void reduceOrder(int house);

};

class DeliveryPlanner{
    private:
        Graph & graph;
        Pipeline & pipeline;
        vector<pair<vector<int>, float> > shortestPaths;

    public:
        DeliveryPlanner(Graph & g, Pipeline & pipeline);
        //Returns a vector of route/currentcapacity pairs

        vector< vector<int> > generatePlan();

        int findTargetHouse();

};







