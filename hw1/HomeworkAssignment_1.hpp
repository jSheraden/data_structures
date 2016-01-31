#ifndef HOMEWORKASSIGNMENT_1_HPP
#define HOMEWORKASSIGNMENT_1_HPP

class HomeworkAssignment_1
{
	private:
		std::string choice;
		bool quit;
		void printChar( char ch );
		void printShort( short sh );
		void printFloat( float fl );
        void displayMenu();
        void getUserInput();
		bool choiceIsValid();
	public:
		HomeworkAssignment_1();
		void run();
};

#endif
