#include "player_table.h"
#include "class_table.h"
#include "race_table.h"
#include <iostream>
#include <limits>

void printMainMenu() {
    std::cout << "\n=== RPG Database Menu ===\n";
    std::cout << "1. Players Management\n";
    std::cout << "2. Classes Management\n";
    std::cout << "3. Races Management\n";
    std::cout << "4. Exit\n";
    std::cout << "Select option: ";
}

void printPlayerMenu() {
    std::cout << "\n=== Players Management ===\n";
    std::cout << "1. Add Player\n";
    std::cout << "2. Remove Player\n";
    std::cout << "3. Find Player\n";
    std::cout << "4. List All Players\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Select option: ";
}

void printClassMenu() {
    std::cout << "\n=== Classes Management ===\n";
    std::cout << "1. Add Class\n";
    std::cout << "2. Remove Class\n";
    std::cout << "3. List All Classes\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Select option: ";
}

void printRaceMenu() {
    std::cout << "\n=== Races Management ===\n";
    std::cout << "1. Add Race\n";
    std::cout << "2. Remove Race\n";
    std::cout << "3. List All Races\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Select option: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    PlayerTable players;
    ClassTable classes;
    RaceTable races;

    // Загрузка данных
    players.load("players.txt");
    classes.load("classes.txt");
    races.load("races.txt");

    int mainChoice;
    do {
        printMainMenu();
        std::cin >> mainChoice;
        clearInputBuffer();

        switch (mainChoice) {
            case 1: { // Управление игроками
                int playerChoice;
                do {
                    printPlayerMenu();
                    std::cin >> playerChoice;
                    clearInputBuffer();

                    switch (playerChoice) {
                        case 1: { // Добавить игрока
                            std::map<std::string, std::string> playerData;
                            std::cout << "Enter player ID: ";
                            std::cin >> playerData["id"];
                            clearInputBuffer();
                            
                            std::cout << "Enter player name: ";
                            std::getline(std::cin, playerData["name"]);
                            
                            std::cout << "Enter player class: ";
                            std::getline(std::cin, playerData["class"]);
                            
                            std::cout << "Enter player race: ";
                            std::getline(std::cin, playerData["race"]);
                            
                            players.add(playerData);
                            std::cout << "Player added successfully!\n";
                            break;
                        }
                        case 2: { // Удалить игрока
                            int id;
                            std::cout << "Enter player ID to remove: ";
                            std::cin >> id;
                            if (players.exists(id)) {
                                players.remove(id);
                                std::cout << "Player removed successfully!\n";
                            } else {
                                std::cout << "Player not found!\n";
                            }
                            break;
                        }
                        case 3: { // Найти игрока
                            int id;
                            std::cout << "Enter player ID: ";
                            std::cin >> id;
                            if (players.exists(id)) {
                                auto player = players.get(id);
                                std::cout << "\nPlayer found:\n";
                                std::cout << "ID: " << player["id"] << "\n";
                                std::cout << "Name: " << player["name"] << "\n";
                                std::cout << "Class: " << player["class"] << "\n";
                                std::cout << "Race: " << player["race"] << "\n";
                            } else {
                                std::cout << "Player not found!\n";
                            }
                            break;
                        }
                        case 4: // Список игроков
                            std::cout << "\nAll Players:\n";
                            players.printAll();
                            break;
                        case 5: // Назад
                            break;
                        default:
                            std::cout << "Invalid option!\n";
                    }
                } while (playerChoice != 5);
                break;
            }
            case 2: { // Управление классами
                int classChoice;
                do {
                    printClassMenu();
                    std::cin >> classChoice;
                    clearInputBuffer();

                    switch (classChoice) {
                        case 1: { // Добавить класс
                            std::map<std::string, std::string> classData;
                            std::cout << "Enter class name: ";
                            std::getline(std::cin, classData["class_name"]);
                            
                            std::cout << "Enter class skill: ";
                            std::getline(std::cin, classData["skill"]);
                            
                            classes.add(classData);
                            std::cout << "Class added successfully!\n";
                            break;
                        }
                        case 2: { // Удалить класс
                            int id;
                            std::cout << "Enter class ID to remove: ";
                            std::cin >> id;
                            if (classes.exists(id)) {
                                classes.remove(id);
                                std::cout << "Class removed successfully!\n";
                            } else {
                                std::cout << "Class not found!\n";
                            }
                            break;
                        }
                        case 3: // Список классов
                            std::cout << "\nAll Classes:\n";
                            classes.printAll();
                            break;
                        case 4: // Назад
                            break;
                        default:
                            std::cout << "Invalid option!\n";
                    }
                } while (classChoice != 4);
                break;
            }
            case 3: { // Управление расами
                int raceChoice;
                do {
                    printRaceMenu();
                    std::cin >> raceChoice;
                    clearInputBuffer();

                    switch (raceChoice) {
                        case 1: { // Добавить расу
                            std::map<std::string, std::string> raceData;
                            std::cout << "Enter race name: ";
                            std::getline(std::cin, raceData["race_name"]);
                            
                            std::cout << "Enter race ability: ";
                            std::getline(std::cin, raceData["ability"]);
                            
                            races.add(raceData);
                            std::cout << "Race added successfully!\n";
                            break;
                        }
                        case 2: { // Удалить расу
                            int id;
                            std::cout << "Enter race ID to remove: ";
                            std::cin >> id;
                            if (races.exists(id)) {
                                races.remove(id);
                                std::cout << "Race removed successfully!\n";
                            } else {
                                std::cout << "Race not found!\n";
                            }
                            break;
                        }
                        case 3: // Список рас
                            std::cout << "\nAll Races:\n";
                            races.printAll();
                            break;
                        case 4: // Назад
                            break;
                        default:
                            std::cout << "Invalid option!\n";
                    }
                } while (raceChoice != 4);
                break;
            }
            case 4: // Выход
                std::cout << "Saving data and exiting...\n";
                players.save("players.txt");
                classes.save("classes.txt");
                races.save("races.txt");
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    } while (mainChoice != 4);

    return 0;
}
