#ifndef HOMEWORKASSIGNMENT_1_HPP
#define HOMEWORKASSIGNMENT_1_HPP

class HomeworkAssignment_1
{
	private:
        bool quit;
		std::string choice;
        void displayMenu();
        void getUserInput();
		bool choiceIsValid();
	public:
		HomeworkAssignment_1();
		void run();
        static void printChar( char ch );
        static void printShort( short sh );
        static void printFloat( float fl );
};

#endif
