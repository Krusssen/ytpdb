#include "table.h"
#include <fstream>
#include <sstream>

// Реализация метода split
std::vector<std::string> Table::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Реализация метода load
void Table::load(const std::string& filename) {
    this->filename = filename;
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    if (std::getline(file, line)) {
        columns = split(line, '\t');
    }

    while (std::getline(file, line)) {
        auto values = split(line, '\t');
        if (values.size() != columns.size()) continue;

        int id = std::stoi(values[0]);
        std::map<std::string, std::string> row;
        for (size_t i = 0; i < columns.size(); ++i) {
            row[columns[i]] = values[i];
        }
        data[id] = row;
    }
}

// Реализация метода save
void Table::save() {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (size_t i = 0; i < columns.size(); ++i) {
        if (i != 0) file << '\t';
        file << columns[i];
    }
    file << '\n';

    for (const auto& pair : data) {
        const auto& row = pair.second;
        for (size_t i = 0; i < columns.size(); ++i) {
            if (i != 0) file << '\t';
            file << row.at(columns[i]);
        }
        file << '\n';
    }
}

// Реализация метода exists
bool Table::exists(int id) const {
    return data.find(id) != data.end();
}

// Реализация метода printAll
void Table::printAll() const {
    for (const auto& col : columns) {
        std::cout << col << "\t";
    }
    std::cout << "\n";

    for (const auto& pair : data) {
        const auto& row = pair.second;
        for (const auto& col : columns) {
            std::cout << row.at(col) << "\t";
        }
        std::cout << "\n";
    }
}
