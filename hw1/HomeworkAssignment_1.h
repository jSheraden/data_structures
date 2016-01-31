#ifndef HOMEWORKASSIGNMENT_1_H
#define HOMEWORKASSIGNMENT_1_H

class HomeworkAssignment_1
{
	private:
		std::string choice;
		bool quit;
		void displayMenu();
		void getUserInputs();
		void printChar( char ch );
		void printShort( short sh );
		void printFloat( float fl );
		bool choiceIsValid();
	public:
		HomeworkAssignment_1();
		void run();
};

#endif
