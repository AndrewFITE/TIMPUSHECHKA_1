#include "modAlphaCipher.h"

bool isValid(const wstring& s)
{
    for(const auto &c:s)
        if (!isalpha(c) )
            return false;
    return true;
}

int main()
{
    int key;
    wstring row;
    unsigned operation;
    wcout << "Input key (number): ";
    wcin >> key;
    if (!wcin.good()) {
        wcerr << "Key not valid!\n";
        return 1;
    }
    wcout << L"Key loaded!\n";
    modAlphaCipher cipher(key);
    do {
        wcout << L"Input operation (0 - exit, 1 - encrypt, 2 - decrypt): ";
        wcin >> operation;
        if (operation > 2) {
            wcout << L"Illegal operation!\n";
        } else if (operation > 0) {
            wcout << L"Input text: ";
            wcin >> row;
            if (isValid(row)) {
                if (operation == 1) {
                    wcout << L"Encrypted text: " << cipher.coder(row) << endl;
                } else {
                    wcout << L"Decrypted text: " << cipher.decoder(row) << endl;
                }
            } else {
                wcout << L"Invalid text!\n";
            }
        }
    } while (operation != 0);

    return 0;
}
