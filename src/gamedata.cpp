#include "gamedata.h"

#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

GameData::GameData(std::string fileName)
    : _filePath(DATA_DIR + fileName) {
  readData();
}

void GameData::readData() {
  std::ifstream filestream(_filePath);
  if (filestream.is_open()) {
    std::string line;
    std::string key;
    std::string value;

    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        _data.insert(std::make_pair(key, std::stoi(value)));
      }
    }
  } else {
    std::experimental::filesystem::create_directories(DATA_DIR);
  }
}

void GameData::writeData() {
  std::ofstream outFile;
  outFile.open(_filePath);

  if (outFile.is_open()) {
    for (std::map<std::string, int>::iterator it=_data.begin(); it!=_data.end(); ++it) {
      outFile << it->first << " " << it->second << '\n';
    }

    outFile.close();
  } else {
    std::cout << "Failed to save data to " << _filePath << "\n";
  }
}

int GameData::getProperty(const std::string& key) {
  return _data[key];
}

void GameData::setProperty(const std::string& key, const int& value) {
  _data[key] = value;
}
