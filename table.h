#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Table {
protected:
    std::vector<std::string> columns;
    std::map<int, std::map<std::string, std::string>> data;
    std::string filename;

    std::vector<std::string> split(const std::string &s, char delimiter);
    
public:
    virtual ~Table() = default;
    void load(const std::string& filename);
    void save();
    bool exists(int id) const;
    void printAll() const;
};
