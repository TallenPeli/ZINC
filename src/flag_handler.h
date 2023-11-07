#ifndef FLAG_HANDLER_H_INCLUDED
#define TFLAG_HANDLER_H_INCLUDED


#include <string>

using namespace std;

extern bool keepTranslation;
extern bool verboseOutput;
extern bool compileToAsssembly;

extern string optimizationList[];
extern int optimization;

void flagHandler(int FlagAmt, char **flag);

#endif // FLAG_HANDLER_H_INCLUDED