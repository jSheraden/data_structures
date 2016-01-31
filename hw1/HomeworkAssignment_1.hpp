#ifndef HOMEWORKASSIGNMENT_1_HPP
#define HOMEWORKASSIGNMENT_1_HPP

class HomeworkAssignment_1
{
	private:
        bool quit;
		std::string choice;
        unsigned short numBits;
        unsigned short mask;
		void printChar( char ch );
		void printShort( short sh );
		void printFloat( FloatUnion fl );
        void displayMenu();
        void getUserInput();
		bool choiceIsValid();
	public:
		HomeworkAssignment_1();
		void run();
};

#endif
