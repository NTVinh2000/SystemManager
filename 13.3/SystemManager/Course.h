#pragma once
#ifndef _COURSE_H_
#define _COURSE_H_

class Course {
public:
	//Create / update / delete / view academic years (2018-2019), and semesters (Fall)
	//...
	void ImportCourse(); //From a semester, import courses such as CTT008, CTT010 from a csv file
	void AddANewCourse(); //Manually add a new course
	void EditCourse(); //Edit an existing course
	void RemoveCourse(); //Remove a course
	void RemoveStudent(); //Remove a student from a course
	void AddStudentToACourse(); //Add a specific student to a course
	void ViewCourses(); //View list of courses in the current semester
	void ViewStudents(); //View list of students of a course
	void ViewAttendence(); //View attendance list of a course
	//View attendance list of a course
	//...
};

#endif#pragma once
