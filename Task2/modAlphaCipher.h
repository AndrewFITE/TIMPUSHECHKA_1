#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;

class modAlphaCipher
{
private:
    int newkey; //количество столбцов таблицы

public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& key) :newkey(key) {};
    wstring coder(const wstring& open_st);
    wstring decoder(const wstring& cipher_st);
};
