#include "fileManager.hpp"
#include <iostream>
#include <utility>

using std::endl;
using std::pair;

FileManager::~FileManager()
{
    m_stream.close();
}

bool FileManager::init()
{
    if (!m_stream.is_open())
    {
        m_stream.open("settings.ini", std::ios::app | std::ios::in | std::ios::out);
        m_stream.seekg(0, m_stream.end);
        if (m_stream.tellg() < 10)
        {
            m_stream.close();
            m_stream.open("settings.ini", std::ios::trunc | std::ios::out);
            m_stream << "currentCharacterSet ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789" << endl;
            m_stream << "defaultPasswordLength 12" << endl;
            m_stream << "passwordFilePath ." << endl;
        }
        m_stream.close();
        m_stream.open("settings.ini", std::ios::in | std::ios::app);
        while (!m_stream.eof())
        {
            string t_setting;
            string t_value;
            getline(m_stream, t_setting, ' ');
            getline(m_stream, t_value);
            if (!t_setting.empty() && !t_value.empty())
            {
                m_settings[t_setting] = t_value;
            }
            else break;
        }
        m_stream.close();
        m_stream.open("data.txt");
        m_stream.seekg(0, m_stream.end);
        if (m_stream.tellg() > 10)
        {
            m_stream.seekg(0, m_stream.beg);
            while (!m_stream.eof())
            {
                string t_site;
                string t_data;
                getline(m_stream, t_site, ' ');
                getline(m_stream, t_data);
                if (!t_site.empty() && !t_data.empty())
                {
                    m_data[t_site] = t_data;
                }
                else break;
            }
        }
        m_stream.close();
    }
    else 
    {
        m_stream.close();
        return false;
    }
}

bool FileManager::changeSetting(const string& in_setting, const string& in_value, bool op_save)
{
    m_settings[in_setting] = in_value;
    if (op_save)
    {
        if (m_stream.is_open())
        {
            m_stream.close();
        }
        m_stream.open("settings.ini", std::ios::trunc | std::ios::out);
        for (auto a = m_settings.begin(); a != m_settings.end(); a++)
        {
            m_stream << a->first << ' ' << a->second << endl;
        }
    }
}

vector<char> FileManager::getCurrentCharSet()
{
    vector<char> t_charSet;
    for (size_t i = 0; i < m_settings["currentCharacterSet"].size(); i++)
    {
        t_charSet.push_back(m_settings["currentCharacterSet"].at(i));
    }
    return t_charSet;
}