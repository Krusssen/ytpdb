#pragma once

#include <string>
#include <map>
#include <iostream>

class Database {
public:
    virtual ~Database() = default;
    virtual void load(const std::string& filename) = 0;
    virtual void save(const std::string& filename) = 0;
    virtual void add(const std::map<std::string, std::string>& data) = 0;
    virtual void remove(int id) = 0;
    virtual std::map<std::string, std::string> get(int id) = 0;
    virtual bool exists(int id) const = 0; // без конст не работает
    virtual void printAll() const = 0; // тут тож (Я НЕ ЗНАЮ ПОЧЕМУ)
};
