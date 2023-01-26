#pragma once

class IGraph
{
public:
	// Метод принимает вершины начала и конца ребра и добавляет ребро
	virtual void AddEdge(int from, int to) = 0;
	// Метод должен считать текущее количество вершин
	virtual int VerticesCount() const = 0;
	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
	virtual void GetNextVertices(int vertex, std::vector<bool>& vertices) const = 0;
	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
	virtual void GetPrevVertices(int vertex, std::vector<bool>& vertices) const = 0;

	virtual void showGraph() = 0;
	virtual void resize(int newSize) = 0;

	IGraph() {};
	IGraph(IGraph* _oth) {};
	virtual ~IGraph() {}
};