#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "../IGraph.h"
#include "../ListGraph.h"
#include "../MatrixGraph.h"

int main()
{
	std::shared_ptr<IGraph> a = std::make_shared<MatrixGraph>();
	a->AddEdge(1, 8);
	a->AddEdge(1, 2);
	a->AddEdge(2, 3);
	a->AddEdge(3, 4);
	a->AddEdge(4, 5);
	a->AddEdge(5, 6);
	a->AddEdge(5, 7);
	a->AddEdge(6, 7);
	a->showGraph();
	printf("vertices count: %i\n", a->VerticesCount());

	std::shared_ptr<IGraph> b = std::make_shared<ListGraph>(a);
	b->showGraph();
	printf("vertices count: %i\n\n", b->VerticesCount());
	b->AddEdge(8, 9);
	b->AddEdge(4, 8);
	b->showGraph();
	printf("vertices count: %i\n\n", b->VerticesCount());

	std::vector<bool> temp;
	b->GetPrevVertices(6, temp);
	b->GetPrevVertices(7, temp);
	b->GetPrevVertices(3, temp);
	a.reset();
	b.reset();

	return 0;
}