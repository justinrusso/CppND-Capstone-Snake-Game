#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <map>
#include <string>

class GameData {
 public:
  GameData(std::string filePath);

  inline static const std::string DATA_DIR = "./gamedata/";

  void readData(); // Gets data from file
  void writeData(); // Writes data to file

  // Data modifiers & getters
  int getProperty(const std::string& key);
  void setProperty(const std::string& key, const int& value);

 private:
  std::string _filePath;
  std::map<std::string, int> _data{};
};

#endif