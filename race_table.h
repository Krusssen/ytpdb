#pragma once

#include "database.h"
#include "table.h"

class RaceTable : public Database, protected Table {
public:
    RaceTable();
    void load(const std::string& filename) override;
    void save(const std::string& filename) override;
    void add(const std::map<std::string, std::string>& data) override;
    void remove(int id) override;
    std::map<std::string, std::string> get(int id) override;
    bool exists(int id) const override { return Table::exists(id); }
    void printAll() const override { Table::printAll(); }
};
