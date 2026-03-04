/*
 * 串的典型操作接口声明。所有类型的串都应该实现这些接口。
 */

#include <stdbool.h>

#include "auxf.h"

extern bool StrInsert(StringPtr s, int pos, StringPtr t);
extern bool StrDelete(StringPtr s, int pos, int len);
extern void StrCopy(StringPtr s, StringPtr t);
extern int StrCompare(StringPtr s, StringPtr t);
extern int StrIndex(StringPtr s, int pos, StringPtr t);
extern bool StrEmpty(StringPtr s);
extern int StrLength(StringPtr s);
extern void StrClear(StringPtr s);
extern int StrCat(StringPtr s, StringPtr t);
extern bool SubString(StringPtr sub, StringPtr s, int pos, int len);
extern void StrDestroy(StringPtr s);
extern int StrReplace(StringPtr s, StringPtr p, StringPtr r);

extern int StrAssign(StringPtr s, CHAR *t);
extern int StrPrint(StringPtr s);

extern void StrInit(StringPtr s);