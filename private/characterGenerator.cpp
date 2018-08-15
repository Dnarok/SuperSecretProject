#include "characterGenerator.hpp"
#include <ctime>

using std::time;

void CharacterGenerator::init(const vector<char>& in_currentCharacters)
{
    m_currentCharacters = in_currentCharacters;
    m_gen.seed(time(nullptr));
}

char CharacterGenerator::generate()
{
    return m_currentCharacters.at(m_distrib(m_gen) % m_currentCharacters.size());
}

void CharacterGenerator::updateCurrentCharacters(const vector<char>& in_currentCharacters)
{
    m_currentCharacters = in_currentCharacters;
}

string CharacterGenerator::generateStr(size_t in_size)
{
    string out_str = "";
    for (size_t i = 0; i < in_size; i++)
    {
        out_str.push_back(generate());
    }
    return out_str;
}