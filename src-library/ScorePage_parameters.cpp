//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Thu May  1 14:05:41 PDT 2014
// Last Modified: Thu May  1 14:05:43 PDT 2014
// Filename:      ScorePage_parameters.cpp
// URL:           https://github.com/craigsapp/scorelib/blob/master/src-library/ScorePage_parameters.cpp
// Syntax:        C++11
//
// Description:   This file contains ScorePage class functions related to
//                processing all parameters on the page.
//

#include "ScorePage.h"

using namespace std;


//////////////////////////////
//
// ScorePage::copyParameterOverwrite --
//

void ScorePage::copyParameterOverwrite(const string& newnamespace,
      const string& oldnamespace, const string& parameter) {
   for (auto& it : item_storage) {
      it->copyParameterOverwrite(newnamespace, oldnamespace, parameter);
   }
}



//////////////////////////////
//
// ScorePage::copyParameterNoOverwrite --
//

void ScorePage::copyParameterNoOverwrite(const string& newnamespace,
      const string& oldnamespace, const string& parameter) {
   for (auto& it : item_storage) {
      it->copyParameterNoOverwrite(newnamespace, oldnamespace, parameter);
   }
}



