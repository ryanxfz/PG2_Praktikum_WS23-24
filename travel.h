#ifndef TRAVEL_H
#define TRAVEL_H
#include "Booking.h"
#include "graph.h"
#include "GlobalTypes.h"
#include <memory>
#include <vector>
#include <map>
#include <stack>

using std::vector;
using std::shared_ptr;
using std::string;

class Travel
{
private:
    long id;
    long customerId;
    vector<shared_ptr<Booking>> travelBookings;

    //fromDate and toDate used for check class
    int fromDate;
    int toDate;
    Graph<shared_ptr<Booking>,100> graph;


public:
    Travel();
    Travel(long id, long customerId);
    void addBooking(shared_ptr<Booking> booking);

    long getId() const;
    long getCustomerId() const;
    const vector<shared_ptr<Booking>> getTravelBookings() const;

    //used for the check class
    void setFromDate(const int& setFromDate);
    void setToDate(const int& setToDate);
    int getFromDate() const;
    int getToDate() const;

    //Graphen methods
    void buildGraph();
    void sortGraph(vector<VertexData> &data);
    void extracted(int &index);
    vector<shared_ptr<Booking>> topologicalSort();
    void topologicalSortUtil(int v, vector<bool> & visited, std::stack<int> &stack);

    Graph<shared_ptr<Booking>, 100> getGraph() const;
    void setGraph(const Graph<shared_ptr<Booking>, 100> &newGraph);
};

#endif // TRAVEL_H
