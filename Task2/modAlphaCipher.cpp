#include "modAlphaCipher.h"
using namespace std;

wstring modAlphaCipher::coder(const wstring& open_st)
{
    wstring result = open_st;
    int length, number_of_rows, loc, a;
    length = open_st.size();
    number_of_rows = (length - 1)/newkey + 1;
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) {
        for (int line_number = 0; line_number < number_of_rows; line_number++) {
            loc = colum_number+newkey*line_number;
            if (loc-1 < length) {
                result[a] = open_st[loc-1];
                a++;
            }
        }
    }
    return result;
}

wstring modAlphaCipher::decoder(const wstring& cipher_st)
{
    wstring result = cipher_st;
    int length, number_of_rows, loc, a;
    length = cipher_st.size();
    number_of_rows = (length - 1)/newkey + 1;
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) {
        for (int line_number = 0; line_number < number_of_rows; line_number++) {
            loc = newkey*line_number+colum_number;
            if (loc-1 < length) {
                result[loc-1] = cipher_st[a];
                a++;
            }
        }
    }
    return result;
}

