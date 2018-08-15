#include ".\public\characterGenerator.hpp"
#include <ctime>

using std::time;

CharacterGenerator::CharacterGenerator() : 
    m_gen{},
    m_distrib{}
{
    m_currentCharacters =
    {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '1', '2', '3', '4',
        '5', '6', '7', '8', '9', '0', '!', '@',
        '#', '$', '%', '^', '&', '*', '(', ')'
    };
}

void CharacterGenerator::init()
{
    m_gen.seed(time(nullptr));
}

char CharacterGenerator::generate()
{
    return m_currentCharacters.at(m_distrib(m_gen) % m_currentCharacters.size());
}