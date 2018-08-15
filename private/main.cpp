#include "characterGenerator.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    CharacterGenerator t_cgen;
    t_cgen.init();
    cout << "Some character-gen tests: " << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << t_cgen.generate();
    }

    return EXIT_SUCCESS;
}