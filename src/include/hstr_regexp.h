/*
 ============================================================================
 Name        : hstr_regexp.h
 Author      : martin.dvorak@mindforger.com
 Copyright   : Apache 2.0
 Description : Simplified regexp that suits HSTR needs - matching and caching
 ============================================================================
*/

#ifndef _HSTR_REGEXP_H
#define _HSTR_REGEXP_H

#include <regex.h>
#include <stdio.h>
#include <stdbool.h>

#include "hashset.h"

typedef struct {
    bool caseSensitive;
    HashSet cache;
} HstrRegexp;

void hstr_regexp_init(HstrRegexp *hstrRegexp);
bool hstr_regexp_match(HstrRegexp *hstrRegexp, const char *regexp, const char *text, regmatch_t *match, char *errorMessage, const size_t errorMessageSize);
void hstr_regexp_destroy(HstrRegexp *hstrRegexp);

#endif
