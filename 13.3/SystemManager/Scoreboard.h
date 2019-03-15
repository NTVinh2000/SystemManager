#pragma once
#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

class ScoreBoard {
public:
	void SearchAndView(); //Search and view scoreboard of a course
	void Export(); // Export a scoreboard to a csv file
	void Import(); //Import scoreboard of a course (midterm, final, lab, bonus) from a csv file
	void Edit(); //Edit grade of a student
};

#endif