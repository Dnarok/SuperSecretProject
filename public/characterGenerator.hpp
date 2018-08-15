#pragma once

#include <random>
#include <vector>
#include <string>

using std::mt19937_64;
using std::uniform_int_distribution;
using std::vector;
using std::string;

class CharacterGenerator
{
private:
    mt19937_64 m_gen;
    uniform_int_distribution<int> m_distrib;
    vector<char> m_currentCharacters;
public:
    CharacterGenerator() : m_gen{}, m_distrib{}, m_currentCharacters{} {};
    ~CharacterGenerator() {};

    void init(const vector<char>&);
    char generate();
    string generateStr(size_t);
    void updateCurrentCharacters(const vector<char>&);
};