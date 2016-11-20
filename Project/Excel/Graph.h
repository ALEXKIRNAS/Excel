#pragma once
#include <cliext\vector>
#include <cliext\set>
#include "Table.h"

using cliext::vector;
using cliext::set;
using namespace System::Windows::Forms;
using System::String;

/* Class for representation information in form of graph
 *
 * If some two vertex connected by oriented edge then 
 * one of them depend from other (in formula). Orientation
 * show who depend.
 *
 */
public ref class Graph {
private:
	
	vector < vector<set <unsigned __int64> ^> ^> graph; // Array that contain graph in list form

	vector <unsigned __int64> getListOfCells(String^ str, unsigned int height, unsigned int width);
	vector <unsigned __int64> topologicalSort(unsigned int row, unsigned int column, unsigned int height, unsigned int width);
	bool dfs(unsigned __int64 v, vector <unsigned __int64>% res, set <unsigned __int64>% visit, unsigned int& height, unsigned int& width);

	unsigned int getY(String^ str, int& index, unsigned int max);
	unsigned int getX(String^ str, int& index, unsigned int max);

public:
	
	Graph(unsigned int height, unsigned int width);
	void changeGraph(DataGridView^ view, Table^ table, unsigned int row, unsigned int column);
	wchar_t* toStdWstring(String^ str); 

};