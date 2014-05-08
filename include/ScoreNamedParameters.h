//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Thu May  1 14:46:29 PDT 2014
// Last Modified: Thu May  1 14:46:32 PDT 2014
// Filename:      ScoreNamedParameters.h
// URL:           https://github.com/craigsapp/scorelib/blob/master/include/ScoreNamedParameters.h
// Syntax:        C++11
//
// Description:   Official named parameters and namespaces.
//

#ifndef _SCORENAMEDPARAMETER_H_INCLUDED
#define _SCORENAMEDPARAMETER_H_INCLUDED

#include <string>

using namespace std;


///////////////////////////////////////////////////////////////////////////
//
// auto namespace -- The "auto" namespace is used to store automatically 
//    calculated parameters, such as pitch.
//

const string ns_auto = "auto";

//
// Automatic rhythm analysis parameters:
//

// @auto@staffOffsetDuration -- The duration from the start of the staff 
//      to the given item, in terms of quarter notes.
const string np_staffOffsetDuration = "staffOffsetDuration";

// @auto@staffDuration -- The duration from the start to end of a staff.
const string np_staffDuration = "staffDuration";


//
// Automatic pitch analysis parameters:
//

// @auto@base40Pitch -- The automatically identified pitch in base-40 format.
const string np_base40Pitch = "base40Pitch";

// @auto@courtesy -- True if a courtesy accidental is shown for the
//     given note item.  The value should be true|false.
const string np_courtesy = "courtesy";


///////////////////////////////////////////////////////////////////////////
//
// lyrics namespace -- The "lyrics" namespace is used to store information 
//      about musical lyrics.

const string ns_lyrics = "lyrics";

// @lyrics@verseLine: indicates that a text item is part of some lyrics,
//     and this is the line number of the lyric.  The highest lyric
//     is number 1.  Zero is not used for a lyric number.
const string np_verseLine = "verseLine";

// @lyrics@hyphenAfter: indicates that a text items is not the end of 
//     a word, and there is another syllable to follow.  The value
//     should be true|false.
const string np_hyphenAfter = "hyphenAfter";

// @lyrics@hyphenBefore: indicates that a text items is not the start of 
//     a word, and there is another syllable preceding it.  The value
//     should be true|false.
const string np_hyphenBefore = "hyphenBefore";

// @lyrics@hyphen: indicates that a line item (P1=4) is a word hyphen 
//     within lyrics.  The value should be true|false.
const string np_lyricsHyphen = "lyricsHyphen";

// @lyrics@wordExtension: indicates that a line items is a word extension
//     for a lyric syllable.  The value should be true|false.
const string np_wordExtension = "wordExtension";




#endif /* _SCORENAMEDPARAMETER_H_INCLUDED */
