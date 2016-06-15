#ifndef _GRAPH_H
#define _GRAPH_H_

#include "dynArray.h"
#include "SLinkedList.h"
#include "Queue.h"


typedef unsigned int uint;
using namespace std;
template <class TYPE>


class Graph{

	struct vertex{

		TYPE data;
		Vector<vertex*> edges;

		vertex(const TYPE& data) : data(data){}


		bool AddEdge(vertex* destination)
		{
			if (std::find(edges.begin(), edges.end(), destination) != edges.end())
				return false;

			edges.push_back(destination);
			return true;
		}
		bool pepitojuanito(const vertex* dst, Vector<const vertex*>& visited_nodes) const
		{
			
			if (dst == this)
				return true;

			
			visited_nodes.push_back(this);

			
		/*	for (const List<vertex*>::node* item = links.front_node(); item; item = item->next())
			{
				if (visited_nodes.find(item->data) == visited_nodes.size())
				{
					if (item->data->pepitojuanito(dst, visited_nodes) == true)
						return true;
				}
			}

		*/
			for (int i = 0; i < edges.size(); i++)
			if (std::find(visited_nodes.begin(), visited_nodes.end(), edges[i]) != edges.end())
				edges[i]->pepitojuanito(dst, visited_nodes);
			
			return false;
		}
	};

public:

	Vector<vertex*> vertices;

	Graph(){}
	~Graph(){}


public:

	vertex* push(const TYPE& data)
	{
		vertex new_vertex = new vertex(data);
		vertices.push_back(new_vertex);
		return new_vertex;
	}

	uint size() const
	{
		return vertices.size();
	}

	bool empty() const
	{
		return vertices.empty();
	}

	void clear()
	{
		vertices.clear();
	}

	bool is_reachable(const vertex* src, const vertex* dst) const
	{
		
		Vector<const vertex*> visited_nodes(size());

		return src->pepitojuanito(dst, visited_nodes);
	
	}
	
};



#endif