#include "characterGenerator.hpp"
#include "fileManager.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::stoi;

int main()
{
    cout << "Welcome to the SSP!" << endl;

    string t_command;
    FileManager t_fman;
    t_fman.init();
    CharacterGenerator t_cgen;
    t_cgen.init(t_fman.getCurrentCharSet());

    while (true)
    {
        cout << "What would you like to do?\n\t";
        getline(cin, t_command);
        if (t_command == "new password")
        {
            string t_site;
            string t_size;
            cout << "What site is this for?\n\t";
            getline(cin, t_site);
            cout << "How long should it be?\n\t";
            getline(cin, t_size);
            t_fman.addDatum(t_site, t_cgen.generateStr(stoi(t_size)));
            cout << "New password for " << t_site << ": \n\t" << t_fman.getDatum(t_site) << endl;
        }
        else if (t_command == "change password")
        {
            string t_site;
            string t_size;
            cout << "What site's password will be changed?\n\t";
            getline(cin, t_site);
            cout << "How long should the new password be?\n\t";
            getline(cin, t_size);
            t_fman.changeDatum(t_site, t_cgen.generateStr(stoi(t_size)));
            cout << "New password for " << t_site << ": \n\t" << t_fman.getDatum(t_site) << endl;
        }
        else if (t_command == "get password")
        {
            string t_site;
            cout << "The password for which site?\n\t";
            getline(cin, t_site);
            cout << "Password for " << t_site << " is: \n\t" << t_fman.getDatum(t_site) << endl;
        }
        else if (t_command == "change characters")
        {
            cout << "Enter your new characters: \n\t";
            getline(cin, t_command);
            t_fman.changeSetting("currentCharacterSet", t_command);
            t_cgen.updateCurrentCharacters(t_fman.getCurrentCharSet());
            cout << "Current characters updated." << endl;
        }
        else if (t_command == "character set")
        {
            cout << "The current character set: \n\t";
            vector<char> t_currentCharSet = t_fman.getCurrentCharSet();
            for (size_t i = 0; i < t_currentCharSet.size(); i++)
            {
                cout << t_currentCharSet.at(i);
            }
            cout << endl;
        }
        else if (t_command == "exit")
        {
            break;
        }
    }

    cout << "Goodbye!" << endl;

    return EXIT_SUCCESS;
}