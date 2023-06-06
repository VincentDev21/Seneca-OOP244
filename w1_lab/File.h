#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}

// Your header file content goes here

#endif