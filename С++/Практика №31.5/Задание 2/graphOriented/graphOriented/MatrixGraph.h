#pragma once
#include "IGraph.h"

class MatrixGraph : public IGraph
{
	std::vector<std::vector<bool>> graph;

public:
	void showGraph() override
	{
		for (int i = 0; i <= graph.size(); i++)
			printf((i == 0 ? "  " : "%i "), i);
		std::cout << std::endl;
		for (size_t row = 0; row < graph.size(); row++)
		{
			printf("%i ", ((int)row + 1));
			for (size_t col = 0; col < graph[row].size(); col++)
				printf("%i ", (graph[row][col] ? 1 : 0));
			std::cout << std::endl;
		}
	}
	void resize(int newSize) override
	{
		graph.resize(newSize, std::vector<bool>(newSize, 0));
		for (int i = 0; i < graph.size(); i++)
			graph[i].resize(newSize, 0);
	}
	// Метод принимает вершины начала и конца ребра и добавляет ребро
	void AddEdge(int from, int to) override
	{
		if (from < to) {
			if (graph.empty() || graph.size() < from || graph.size() < to)
				resize(from > to ? from : to);
			if (!graph[from - 1][to - 1])
				graph[from - 1][to - 1] = 1;
		}
	}
	// Метод должен считать текущее количество вершин
	int VerticesCount() const override
	{
		return (int)graph.size();
	}
	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
	void GetNextVertices(int vertex, std::vector<bool>& vertices) const override
	{
		vertices = graph[vertex];
	}
	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
	void GetPrevVertices(int vertex, std::vector<bool>& vertices) const override
	{
		vertices.resize(graph.size());
		for (int i = 0; i < (int)graph.size(); i++)
			vertices[i] = graph[i][vertex];
		printf("%i: ", vertex);
		for (int i = 0; i < (int)graph.size(); i++)
			if (graph[i][vertex - 1])
				std::cout << (i + 1) << " ";
		std::cout << std::endl;
	}
	void copyGraph(const IGraph& oth) {
		resize(oth.VerticesCount());
		for (int i = 0; i < oth.VerticesCount(); i++)
			oth.GetNextVertices(i, graph[i]);
	}
	MatrixGraph() {}
	MatrixGraph(IGraph* oth)
	{
		copyGraph(*oth);
	}
	MatrixGraph(std::shared_ptr<IGraph> oth)
	{
		copyGraph(*oth);
	}
	~MatrixGraph() {}
};