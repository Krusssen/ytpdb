#include "class_table.h"

ClassTable::ClassTable() {
    columns = {"class_name", "skill"};
}

void ClassTable::load(const std::string& filename) {
    Table::load(filename);
}

void ClassTable::save(const std::string& filename) {
    this->filename = filename;
    Table::save();
}

void ClassTable::add(const std::map<std::string, std::string>& data) {
    int id = static_cast<int>(this->data.size()) + 1;
    this->data[id] = data;
    this->data[id]["id"] = std::to_string(id); // Добавляем ID в данные
    save(filename);
}

void ClassTable::remove(int id) {
    if (exists(id)) {
        data.erase(id);
        save(filename);
    }
}

std::map<std::string, std::string> ClassTable::get(int id) {
    return data.at(id);
}
