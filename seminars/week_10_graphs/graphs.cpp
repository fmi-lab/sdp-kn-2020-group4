#include<iostream>
#include<functional>
#include<map>
#include<set>
#include<exception>
#include<vector>
#include<optional>

// Weighted directed graph
template<class VertexType = int, class WeightType = int>
class Graph {
    using EdgeType = std::pair<VertexType, VertexType>;
    using NeighboursType = std::set<VertexType>;

    std::set<VertexType> vertices;
    std::map<VertexType, NeighboursType> neighs; //neighbours
    std::map<EdgeType, WeightType> weights;
    public:
    Graph() = default;
    Graph(std::vector< std::pair<EdgeType, WeightType>>); //vector of vertices and their weights
    void addVertex(const VertexType& v);
    void addEdge(const VertexType& v1,const VertexType& v2, const WeightType& weight);
    bool hasVetrex(const VertexType& v) const;
    bool hasEdge(const VertexType& v1, const VertexType& v2) const;
    WeightType& getEdge(const VertexType& v1, const VertexType& v2);
    WeightType getEdge(const VertexType& v1,const VertexType& v2) const;
    std::set<VertexType>& neighbours(const VertexType& v) const;
};

template<class VertexType, class WeightType>
void Graph<VertexType, WeightType>::addVertex(const VertexType& v)
{
    vertices.insert(v);
    neighs[v];
}

template<class VertexType, class WeightType>
void Graph<VertexType, WeightType>::addEdge(const VertexType& v1,const VertexType& v2, const WeightType& weight)
{
    vertices.insert(v1);
    vertices.insert(v2);
    neighs[v1].insert(v2);
    weights[std::make_pair(v1,v2)] = weight;
}

template<class VertexType, class WeightType>
bool Graph<VertexType, WeightType>::hasVetrex(const VertexType& v) const
{
    return vertices.count(v) == 1;
}

template<class VertexType, class WeightType>
bool Graph<VertexType, WeightType>::hasEdge(const VertexType& v1, const VertexType& v2) const
{
    return vertices.count(v1) && neighs[v1].count(v2) == 1;
}

template<class VertexType, class WeightType>
WeightType& Graph<VertexType, WeightType>::getEdge(const VertexType& v1, const VertexType& v2)
{
    if(!hasEdge(v1,v2))
    {
        throw std::invalid_argument("No edge present!");
    }

    return weights[std::make_pair(v1,v2)];
}

template<class VertexType, class WeightType>
WeightType Graph<VertexType, WeightType>::getEdge(const VertexType& v1, const VertexType& v2) const {
    if(!hasEdge(v1,v2))
    {
        throw std::invalid_argument("No edge present!");
    }

    return weights[std::make_pair(v1,v2)];
}

template<class VertexType, class WeightType>
std::set<VertexType>& Graph<VertexType, WeightType>::neighbours(const VertexType& v) const
{
    if(!hasVetrex(v))
    {
        throw std::invalid_argument("No such vertex");
    }

    return neighs[v];
}

template<class VertexType = int, class WeightType = int>
class GraphM {
    std::set<VertexType> vertices;
    std::map<VertexType, size_t> vertIndexes;
    std::vector<std::vector<std::optional<WeightType>>> neighMatrix;
    public:
    WeightType getEdge(const VertexType& v1,const VertexType& v2) const;
};

template<class VertexType, class WeightType>
WeightType GraphM<VertexType, WeightType>::getEdge(const VertexType& v1,const VertexType& v2) const {
    // ...
    std::optional<WeightType> weight = neighMatrix[vertIndexes[v1]][vertIndexes[v2]];
    if(!weight.has_value()) {
        throw std::invalid_argument("No edge present!");
    }
    return weight.value();
}