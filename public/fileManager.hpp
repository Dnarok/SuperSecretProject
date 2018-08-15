#pragma once

#include <fstream>
#include <map>
#include <string>
#include <vector>

using std::fstream;
using std::map;
using std::string;
using std::vector;

class FileManager
{
private:
    fstream m_stream;
    map<string, string> m_settings;
    map<string, string> m_data;
public:
    FileManager() : m_stream{}, m_settings{}, m_data{} {};
    ~FileManager();

    bool init();
    bool changeSetting(const string&, const string&, bool = true);
    map<string, string> getData();
    bool addDatum(const string&, const string&);
    bool changeDatum(const string&, const string&);
    bool removeDatum(const string&);

    vector<char> getCurrentCharSet();
    void showAllData();
};