#include "characterGenerator.hpp"
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
    CharacterGenerator t_cgen;
    t_cgen.init();

    while (true)
    {
        cout << "What would you like to do?\n\t";
        getline(cin, t_command);
        if (t_command == "generate")
        {
            cout << "\nHow long should it be?\n\t";
            getline(cin, t_command);
            cout << endl;
            for (size_t i = 0; i < stoi(t_command); i++)
            {
                cout << t_cgen.generate();
            }
            cout << endl;
        }
        else if (t_command == "change characters")
        {
            cout << "\nEnter your new characters: \n\t";
            getline(cin, t_command);
            t_cgen.updateCurrentCharacters(t_command);
            cout << "\nCurrent characters updated." << endl;
        }
        else if (t_command == "exit")
        {
            break;
        }
    }

    cout << "Goodbye!" << endl;

    return EXIT_SUCCESS;
}