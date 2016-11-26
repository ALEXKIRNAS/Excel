#pragma once
#include <cliext\vector>
#include <cliext\set>
#include <cliext\map>
#include "Table.h"
#include "Parser.h"

using cliext::vector;
using cliext::set;
using cliext::map;
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

	/*  Return`s list of table cells that used in formula
	 */
	void getListOfCells(String^ str, unsigned int height, unsigned int width, vector <unsigned __int64>^ res) {

		for (int i = 0, size = str->Length; i < size; i++)
			if (str[i] != L'$') continue;
			else {
				unsigned int y = getY(str, ++i, width);
				unsigned int x = getX(str, ++i, height);

				res->push_back(x * 1ll * height  + y);
			}

			return;
	}

	/*  Make topological sort of cells that depend from current cell
	*/
	void topologicalSort(unsigned int row, unsigned int column, Table^ table, vector <unsigned __int64>^ res, set <unsigned __int64>^ circles) {
		unsigned int height = table->getHeight();

		// Set of visited cells
		map <unsigned __int64, char>^ visited = gcnew map <unsigned __int64, char>;

		dfs(row * 1ll * height + column, res, visited, circles, height);

		return;
	}

	/*  Release dfs algorithm for topological sort
	*/
	void Graph::dfs(unsigned __int64 v, vector <unsigned __int64>^ res, map <unsigned __int64, char>^ visit, set <unsigned __int64>^ circles, unsigned int& height) {
		// Setting cell state as in process
		visit[v] = 1;

		unsigned int x = v / height;
		unsigned int y = v % height;

		// Flag that shows statet of processing cell
		register char flag;

		for (auto iter = graph[x]->at(y)->begin(), end = graph[x]->at(y)->end(); iter != end; iter++) {
			flag = visit[*iter];

			switch (flag) {
				case 0: dfs(*iter, res, visit, circles, height); continue;
				case 1: circles->insert(*iter);  continue;
				case 2: continue;
			}
		}

		// Setting cell state as processed
		visit[v] = 2;

		// Pushing current cell in order 
		res->push_back(v);
	}

	/*  Conver Y_index of table cell to digit
	*/
	int Graph::getY(String^ str, int& index, unsigned int max) {

		unsigned int res = 0;
		unsigned int i = index;
		while (i < str->Length && str[i] != '$') i++;

		if (i == str->Length) throw "#Bad link";
		if (i - index > 7) throw "#Index out of range";

		while (str[index] != '$')
			if (isalpha(str[index]) && toupper(str[index]) == str[index]) res = res * 26 + str[index++] - 'A' + 1;
			else throw "#Bad link";

			if (res > max) throw "#Bad link";
			return res;
	}

	/*  Conver X_index of table cell to digit
	*/
	int Graph::getX(String^ str, int& index, unsigned int max) {
		int res = 0;
		int i = index;
		while (i < str->Length && isdigit(str[i])) i++;

		if (i - index > 8) throw "#Index out of range";

		while (index < str->Length && isdigit(str[index])) res = res * 10 + str[index++] - '0';

		if (res - 1 == -1 || res > max) throw "#Bad link";
		return res - 1;
	}

public:
	
	Graph(unsigned int height, unsigned int width) {
		graph.resize(height);

		for (size_t i = 0; i < height; i++) {
			graph[i] = gcnew vector < set <unsigned __int64>^ >;
			graph[i]->resize(width);

			for (size_t z = 0; z < width; z++)
				graph[i]->at(z) = gcnew set <unsigned __int64>;
		}
	}

	/*  Analiz changes in current cell of table and recalculete values
	 *	in dependent cells
	 */
	void changeGraph(Table^ table, DataGridView^ view, unsigned int row, unsigned int column, bool isWasFormula) {

		// Getting all indexs of all cells that used in old and new formula 
		vector <unsigned __int64>^ oldList = gcnew vector <unsigned __int64>;
		if(isWasFormula)
			getListOfCells(table[row][column]->getValue(), table->getHeight(), table->getWidth(), oldList);

		vector <unsigned __int64>^ newList = gcnew vector <unsigned __int64>;
		if(table[row][column]->getIsFormula())
			getListOfCells(view->Rows[row]->Cells[column]->Value->ToString(), table->getHeight(), table->getWidth(), newList);

		// Delete old depends
		for (int i = 0, size = oldList->size(); i < size; i++)
			graph[oldList[i] / table->getHeight()]->at(oldList[i] % table->getHeight())->erase(row*table->getHeight() + column);

		// Adding new depends
		for (int i = 0, size = newList->size(); i < size; i++)
			graph[newList[i] / table->getHeight()]->at(newList[i] % table->getHeight())->insert(row*table->getHeight() + column);

		// Getting dependent cells in topological order
		vector <unsigned __int64>^ order = gcnew vector <unsigned __int64>;

		// Adding cells where start and end circle
		set <unsigned __int64>^ circles = gcnew set <unsigned __int64>;

		topologicalSort(row, column, table, order, circles);

		// Recalculation of dependent cells
		for (int i = order->size() - 1; i >= 0; i--) {
				unsigned int x = order[i] / table->getHeight();
				unsigned int y = order[i] % table->getHeight();

				// If we have a circle in this point
				if (circles->find(order[i]) != circles->end()) {
					view->Rows[x]->Cells[y]->Value = Convert::ToString(L"#Unable to calculate");
					table[x][y]->setIsFormula(false);
					continue;
				}

				// We already caclculate value of this (start) cell
				if (i == order->size() - 1) continue;

				wchar_t* input = toStdWstring(table[x][y]->getValue());

				try {
					table[x][y]->setResult(Parser::parse(input, table));
					table[x][y]->setIsFormula(true);
					view->Rows[x]->Cells[y]->Value = Convert::ToString(table[x][y]->getResult());
				}
				catch (char* str) {
					String^ temp = gcnew String(str);
					view->Rows[x]->Cells[y]->Value = temp;
					table[x][y]->setIsFormula(false);
				}
				catch (int value) {
					table[x][y]->setIsFormula(false);
				}
			}
	}

	/*  Convert System::String to std::wstring
	*/
	wchar_t* toStdWstring(String^ str) {
		wchar_t* s = new wchar_t[str->Length + 1];
		array <wchar_t>^ temp = str->ToCharArray();

		for (size_t i = 0; i < str->Length; i++)
			s[i] = temp[i];

		s[str->Length] = 0;
		return s;
	}
};