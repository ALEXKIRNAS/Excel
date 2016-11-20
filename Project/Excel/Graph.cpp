#include "Graph.h"
#include "Parser.h"

#define CIRCLE_REFERENCE 18446744073709551615ll

Graph::Graph(unsigned int height, unsigned int width) {
	graph.resize(height);
	
	for (int i = 0; i < height; i++) {
		graph[i] = gcnew vector < set <unsigned __int64>^ >;
		graph[i]->resize(width);

		for (int z = 0; z < width; z++)
			graph[i]->at(z) = gcnew set <unsigned __int64>;
	}

}


/*  Analiz changes in current cell of table and recalculete values
 *	in dependent cells
 */
void Graph::changeGraph(DataGridView^ view, Table^ table, unsigned int row, unsigned int column) {
	
	// Getting all indexs of all cells that used in old and new formula 
	vector <unsigned __int64> oldList = getListOfCells(table[row][column]->getValue(), table->getHeight(), table->getWidth());
	vector <unsigned __int64> newList = getListOfCells(view->Rows[row]->Cells[column]->Value->ToString(), table->getHeight(), table->getWidth());

	// Delete old depends
	for (int i = 0, size = oldList.size(); i < size; i++)
		graph[oldList[i] / table->getHeight()]->at(oldList[i] % table->getHeight())->erase(row*column);

	// Adding new depends
	for (int i = 0, size = newList.size(); i < size; i++)
		graph[newList[i] / table->getHeight()]->at(newList[i] % table->getHeight())->insert(row*column);

	// Getting dependent cells in topological order
	vector <unsigned __int64> order = topologicalSort(row, column, table->getHeight(), table->getWidth());

	// Recalculation of dependent cells
	if (order.back() == CIRCLE_REFERENCE) 
		for (int i = 0, size = order.size(); i < size; i++) {
			unsigned int x = order[i] / table->getHeight();
			unsigned int y = order[i] % table->getHeight();
			view->Rows[x]->Cells[y]->Value = Convert::ToString(L"#Circle reference");
			table[x][y]->setIsFormula(false);
		}

	else 
		for (int i = 0, size = order.size(); i < size; i++) {
			unsigned int x = order[i] / table->getHeight();
			unsigned int y = order[i] % table->getHeight();
			wchar_t* input = toStdWstring(table[x][y]->getValue());

			table[x][y]->setResult(Parser::parse(input, table));
			view->Rows[x]->Cells[y]->Value = Convert::ToString(table[x][y]->getResult());
		}
}

/*  Convert System::String to std::wstring
 */
wchar_t* Graph::toStdWstring(String^ str) {
	wchar_t* s = new wchar_t[str->Length + 1];
	array <wchar_t>^ temp = str->ToCharArray();

	for (size_t i = 0; i < str->Length; i++)
		s[i] = temp[i];

	s[str->Length] = 0;
	return s;
}

/*  Return`s list of table cells that used in formula
 */
vector <unsigned __int64> Graph::getListOfCells(String^ str, unsigned int height, unsigned int width) {
	vector <unsigned __int64> res;

	for (int i = 0, size = str->Length; i < size; i++)
		if (str[i] != L'$') continue;
		else {
			unsigned int y = getY(str, ++i, width);
			unsigned int x = getX(str, ++i, height);

			res.push_back(x * 1ll * height  * y);
		}

	return res;
}

/*  Conver Y_index of table cell to digit
*/
unsigned int Graph::getY(String^ str, int& index, unsigned int max) {
	unsigned int res = 0;
	int i = index;
	while (str[i] != '$') i++;

	if (i - index > 7) throw "#Index out of range";

	while (str[index] != '$') res = res * 26 + str[index++] - 'A';

	if(res + 1 > max) throw "#Index out of range";
	else return res + 1;
}

/*  Conver X_index of table cell to digit
*/
unsigned int Graph::getX(String^ str, int& index, unsigned int max) {
	unsigned int res = 0;

	int i = index;
	while (isdigit(str[i])) i++;

	if (i - index > 8) throw "#Index out of range";

	while (isdigit(str[index])) res = res * 10 + str[index++] - '0';


	if (res - 1 > max) throw "#Index out of range";
	else return res - 1;
}

/*  Make topological sort of cells that depend from current cell
 */
vector <unsigned __int64> Graph::topologicalSort(unsigned int row, unsigned int column, unsigned int height, unsigned int width) {

	// Set of visited cells
	set <unsigned __int64> visited;

	// Topological sort of cells
	vector <unsigned __int64> res;

	bool isCircle = dfs(row * 1ll * column, res, visited, height, width);

	if (isCircle) res.push_back(CIRCLE_REFERENCE);
	return res;
}

/*  Release dfs algorithm for topological sort
 */
bool Graph::dfs(unsigned __int64 v, vector <unsigned __int64>% res, set <unsigned __int64>% visit, unsigned int& height, unsigned int& width) {
	visit.insert(v);

	bool isCircle = false;
	unsigned int x = v / height;
	unsigned int y = v % height;

	for (auto iter = graph[x]->at(y)->begin(), end = graph[x]->at(y)->end(); iter != end; iter++){
		if (visit.find(*iter) != visit.end()) {
			isCircle = true;
			continue;
		}
			isCircle |= dfs(*iter, res, visit, height, width);
	}
	
	res.push_back(v);
	return isCircle;
}