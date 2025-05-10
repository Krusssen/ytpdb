#include "player_table.h"

PlayerTable::PlayerTable() {
    columns = {"id", "name", "class", "race"};
}

void PlayerTable::load(const std::string& filename) {
    Table::load(filename);
}

void PlayerTable::save(const std::string& filename) {
    this->filename = filename;
    Table::save();
}

void PlayerTable::add(const std::map<std::string, std::string>& data) {
    int id = std::stoi(data.at("id"));
    this->data[id] = data;
    save(filename);
}

void PlayerTable::remove(int id) {
    if (exists(id)) {
        data.erase(id);
        save(filename);
    }
}

std::map<std::string, std::string> PlayerTable::get(int id) {
    return data.at(id);
}
