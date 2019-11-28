#pragma once
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>

namespace texttable {
	class TextTable {
	public:
		TextTable() {};
		typedef std::vector<std::string> Row;

		void add(const std::string& str) {
			_current.push_back(str);
		};

		void endRow() {
			_rows.push_back(_current);
			_current.clear();
		};

		friend static std::ostream& operator<<(std::ostream& out, TextTable& table) {
			size_t size = 0;
			table.determineWidths();
			for (auto outterIterator = table._rows.begin(); outterIterator != table._rows.end(); ++outterIterator) {
				const Row& row = *outterIterator;
				for (size_t i = 0; i < row.size(); ++i) {
					size = table._widths[i] - row[i].size() + table._margin;
					out << std::left << std::setw(row[i].size() + size) << row[i];
				}
				std::cout << std::endl;
			}
			return out;
		};

	private:
		Row _current;
		std::vector<Row> _rows;
		std::vector<size_t> _widths;
		//configure margins
		size_t _margin = 3;

		void determineWidths() {
			//_size = count of columns
			size_t _size = this->_rows[0].size();
			for (int i = 0; i < _size; ++i) {
				this->_widths.push_back(0);
			}
			for (size_t i = 0; i < _size; ++i) {
				for (auto iterator = this->_rows.begin(); iterator != this->_rows.end(); ++iterator) {
					if (_widths[i] < (*iterator)[i].size()) {
						_widths[i] = (*iterator)[i].size();
					}
				}
			}
		};
	};
}