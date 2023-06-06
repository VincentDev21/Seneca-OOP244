#ifndef SDDS_MOVIE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_MOVIE_H
namespace sdds {
    struct Movie {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };
	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}

// Your header file content goes here

#endif