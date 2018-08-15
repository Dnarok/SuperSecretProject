#include "fileManager.hpp"

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
			m_stream << "passwordFilePath .\\" << endl;
			m_stream.close();
		}
		m_stream.open("settings.ini", std::ios::in);
        while (!m_stream.eof())
        {
            string t_line;
            getline(m_stream, t_line);
            if (!t_line.empty())
            {
                m_settings.insert
                (
                    t_line.substr(0, t_line.find(' ') + 1),
                    t_line.substr(t_line.find(' ') + 1)
                );
            }
        }
        m_stream.close();
        m_stream.open("data.txt");
    }
    else 
    {
        m_stream.close();
        return false;
    }
}

bool FileManager::changeSetting(const string& in_setting, const string& in_value, bool op_save = true)
{
    if (op_save)
    {
        string t_line;
        string t_setting = "";
        while (t_setting != in_setting)
        {
            if (getline(m_stream, t_line)) 
            {
                t_setting = t_line.substr(0, t_line.find(' ') + 1);
            }
            else return false;
        }
        string t_settings = "";
    }
}