#pragma once

#include <random>
#include <vector>

using std::mt19937_64;
using std::uniform_int_distribution;
using std::vector;

class CharacterGenerator
{
private:
    mt19937_64 m_gen;
    uniform_int_distribution<int> m_distrib;
    vector<char> m_currentCharacters;
public:
    CharacterGenerator();
    ~CharacterGenerator() {};

    void init();
    char generate();
};