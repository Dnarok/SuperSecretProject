#pragma once

#include <fstream>
#include <map>
#include <string>

using std::fstream;
using std::map;
using std::string;

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
    bool changeSetting(const string&, const string&, bool);
    map<string, string> getData();
    bool addDatum(const string&, const string&);
    bool changeDatum(const string&, const string&);
    bool removeDatum(const string&);
};