#include "race_table.h"

RaceTable::RaceTable() {
    columns = {"race_name", "ability"};
}

void RaceTable::load(const std::string& filename) {
    Table::load(filename);
}

void RaceTable::save(const std::string& filename) {
    this->filename = filename;
    Table::save();
}

void RaceTable::add(const std::map<std::string, std::string>& data) {
    int id = static_cast<int>(this->data.size()) + 1;
    this->data[id] = data;
    this->data[id]["id"] = std::to_string(id); // Добавляем ID в данные
    save(filename);
}

void RaceTable::remove(int id) {
    if (exists(id)) {
        data.erase(id);
        save(filename);
    }
}

std::map<std::string, std::string> RaceTable::get(int id) {
    return data.at(id);
}
