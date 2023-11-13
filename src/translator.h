#ifndef TRANSLATOR_H_INCLUDED
#define TRANSLATOR_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

extern vector<string> translatedCode;
extern bool isZincFile;

string translate_print(vector<string> tokens);
string translate_println(vector<string> tokens);
string translate_main(string line);
string translate_fn(string line);
string translate_loop(vector<string> tokens);

#endif // TRANSLATOR_H_INCLUDED