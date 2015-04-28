//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sat Apr 12 20:10:32 PDT 2014
// Last Modified: Sun Apr 26 20:41:54 PDT 2015
// Filename:      scorex.cpp
// URL: 	  https://github.com/craigsapp/scorelib/blob/master/src-programs/scorex.cpp
// Documentation: http://scorelib.sapp.org/program/scorex
// Syntax:        C++ 11
//
// Description:   Extract pages, overlays or systems from multi-page input.
//

#include "scorelib.h"

using namespace std;

void   processData          (ScorePage& infile, Options& opts);
void   extractBinaryPages   (ScorePageSet& infiles, Options& opts);
void   extractAsciiPages    (ScorePageSet& infiles, Options& opts);

///////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
   Options opts;
   opts.define("c|count=b", "count the number of input pages/segments");
   opts.define("pc|page-count=b", "count the number of input pages");
   opts.define("sc|segment-count=b", "count the number of input segments");
   opts.define("i|info=b", "count input pages, overlays, and systems");
   opts.define("p|page=i:0", "Extract given page index (offset from 1)");
   opts.define("mus=b", "Extract pages into binary .MUS files");
   opts.define("pag=b", "Extract pages into binary .PAG files");
   opts.define("pmx=b", "Extract pages into ASCII .PMX files");
   opts.define("txt=b", "Extract pages into ASCII .TXT files");
   opts.process(argc, argv);

   ScorePageSet infiles(opts);

   if (opts.getBoolean("count")) {
      cout << "Pages:\t\t" << infiles.getPageCount() << endl;
      infiles.analyzeSegmentsByIndent();
      cout << "Segments:\t" << infiles.getSegmentCount() << endl;
      exit(0);
   }

   if (opts.getBoolean("mus") || opts.getBoolean("pag")) {
      extractBinaryPages(infiles, opts);
      exit(0);
   }

   if (opts.getBoolean("pmx") || opts.getBoolean("txt")) {
      extractAsciiPages(infiles, opts);
      exit(0);
   }

   if (opts.getBoolean("page-count")) {
      cout << infiles.getPageCount() << endl;
      exit(0);
   }

   if (opts.getBoolean("segment-count")) {
      infiles.analyzeSegmentsByIndent();
      cout << infiles.getSegmentCount() << endl;
      exit(0);
   }

   if (opts.getBoolean("page")) {
      cout << infiles[opts.getInteger("page")-1];
      exit(0);
   }

   // extract segment here.



   return 0;
}

///////////////////////////////////////////////////////////////////////////


//////////////////////////////
//
// extractBinaryPages -- extract file from set and write as binary .mus
//   files.  The filenames muse be present in the data (excluding optional
//   filename extensions).
//

void extractBinaryPages(ScorePageSet& infiles, Options& opts) {
   int pages = infiles.getPageCount();
   ScorePage* infile;
   string filename;
   for (int i=0; i<pages; i++) {
      infile = infiles.getPage(i);
      filename = infile->getFilename();
      if (filename.size() == 0) {
         cerr << "Error: Filename is empty for page " << i+1 << endl;
         exit(1);
      }
      // filename should not have an extension, maybe check, but for now
      // add ".mus" or ".pag" always:
      if (opts.getBoolean("mus")) {
         filename += ".mus";
      } else if (opts.getBoolean("pag")) {
         filename += ".pag";
      }
      infile->writeBinary(filename);
   }
}



//////////////////////////////
//
// extractAsciiPages -- extract file from set and write as ASCII .pmx
//   files.  The filenames muse be present in the data (excluding optional
//   filename extensions).
//

void extractAsciiPages(ScorePageSet& infiles, Options& opts) {
   int pages = infiles.getPageCount();
   ScorePage* infile;
   string filename;
   ofstream outfile;

   for (int i=0; i<pages; i++) {
      infile = infiles.getPage(i);
      filename = infile->getFilename();
      if (filename.size() == 0) {
         cerr << "Error: Filename is empty for page " << i+1 << endl;
         exit(1);
      }
      // filename should not have an extension, maybe check, but for now
      // add ".pmx" or ".txt" always:
      if (opts.getBoolean("pmx")) {
         filename += ".pmx";
      } else if (opts.getBoolean("txt")) {
         filename += ".txt";
      }
      outfile.open(filename.data());
      infile->printPmx(outfile);
      outfile.close();
   }
}


