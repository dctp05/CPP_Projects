/*Author: Dylan Cohen
 *Date: 10/15/2022
 *Assignment 4 - This program utilizes classes to model students in the COP3014 programming course.
 * Each student has private variables that hold their quiz and test scores, and various functions
 * that calculate and display scores and the weighted average, as well as the final letter grade the
 * student has in the course. Contstructors are utilized to set default values when declaring a student
 * in class COP3014.
 */

#include <iostream>     //used for info display and user input

using namespace std;

class COP3014 {
    /* Public values, containing the constructors, the setter function, the display function,
     * and the function to call the private functions that calulate the weighted average and
     * letter grade.
     */

    public:
        //constructors
        COP3014();
        COP3014(int z_num, double quiz1, double quiz2, double mid, double fin_exam);
        COP3014(double quiz1, double quiz2, double mid, double fin_exam);
        void set(int z_num, double quiz1, double quiz2, double mid, double fin_exam);
        
        //getter functions for displaying student data
        int get_z_number();
        double get_quiz_1();
        double get_quiz_2();
        double get_midterm();
        double get_final();
        double get_weighted_avg();
        char get_letter_grade();

        //print functions and public grade calculator function
        void print_student_data(ostream& outs);
        void calculate_grades();

    /* The private variables contain all the actual variables for the student's z number,
     * quiz and test scores, and letter grade, as well as the functions to calculate the 
     * average and letter grade.
     */
    private:
        //private grade calculation functions
        void calculate_weighted_avg();
        void calculate_letter_grade();

        //private member variables
        int z_number;
        double quiz_1;
        double quiz_2;
        double midterm;
        double final_exam;
        double weighted_avg;
        char letter_grade;
};

//Function declarations used to process and print student info, and handle data input from user.
void process_and_print_grades(COP3014& student);
void student_from_user_input(COP3014& student);

int main() {
    /* Declare student_a and student_b using constructors, and student_c using the default constructor,
     * which sets z number and scores to 0. 
     */
    COP3014 student_a(32445, 7, 7, 80, 70), student_b(8, 7.6, 75.3, 92.4), student_c;

    /* Call functions for each declared student which calls the necessary functions to calculate average
     * and letter grade and prints the info to the screen for the user. student_a uses the constructor for
     * five inputs, the z num and test scores. student_b uses the constructor that ignores z num and sets the
     * test scores. student_c uses the default constructor which sets everything to zero.
     */

    process_and_print_grades(student_a);
    process_and_print_grades(student_b);
    process_and_print_grades(student_c);

    /* Sets up a loop that allows the user to repeatedly put in znum and test scores for a student, and
     * print the weighted average and letter grade to the screen.
     */
    int continue_loop = 1;
    do {
        student_from_user_input(student_c);
        
        cout << "Enter data for another student? (1 for yes/0 for no): ";
        cin >> continue_loop;
    } while (continue_loop == 1);

    //Print goodbye message to the user and exit the program
    cout << "\nThank you for using the program. Have a nice day!";

    return 0;
}

//Calculates grades and prints info to the screen
void process_and_print_grades(COP3014& student) {
    //call private function to calculate weighted average and letter grade
    student.calculate_grades();

    //print the student info to the screen
    student.print_student_data(cout);
}

//get student info from user input and call funtions to calculate grades and print to screen
void student_from_user_input(COP3014& student) {
    //declare local variables for z num and test scores
    int z_num;
    double quiz1, quiz2, mid, fin_exam;

    //prompt user for data and input into variables
    cout << "Input Z-number: ";
    cin >> z_num;
    cout << "Input quiz 1 score out of 10: ";
    cin >> quiz1;
    cout << "Input quiz 2 score out of 10: ";
    cin >> quiz2;
    cout << "Input midterm score out of 100: ";
    cin >> mid;
    cout << "Input final test score out of 100: ";
    cin >> fin_exam;
    cout << "\n";

    //call set function to assign data to passed COP3014 class address
    student.set(z_num, quiz1, quiz2, mid, fin_exam);

    //calculate weighted avg and letter grade and print to screen
    process_and_print_grades(student);
}

//default constructor which assigns 0 to all variables
COP3014::COP3014() {
    z_number = 0;
    quiz_1 = 0;
    quiz_2 = 0;
    midterm = 0;
    final_exam = 0;
}

//constructor for 4 variables, znum is automatically 0, test scores are assigned
COP3014::COP3014(double quiz1, double quiz2, double mid, double fin_exam) {
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}

//constructor which assigns znum and all quiz and test scores
COP3014::COP3014(int z_num, double quiz1, double quiz2, double mid, double fin_exam) {
    z_number = z_num;
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}

//sets znum and quiz/test scores to an existing instance of class
void COP3014::set(int z_num, double quiz1, double quiz2, double mid, double fin_exam) {
    //exit program if any negative values are recieved
    if (z_num < 0 || quiz1 < 0 || quiz2 < 0 || mid < 0 || fin_exam < 0) {
        cout << "Illegal values for Z-number or test scores.\n";
        exit(1);
    }

    //set z number and test scores to private variables
    z_number = z_num;
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}

//getters for z number, quizzes and tests, weighted avg, and letter grade
int COP3014::get_z_number() {
    return z_number;
}

double COP3014::get_quiz_1() {
    return quiz_1;
}

double COP3014::get_quiz_2() {
    return quiz_2;
}

double COP3014::get_midterm() {
    return midterm;
}

double COP3014::get_final() {
    return final_exam;
}

double COP3014::get_weighted_avg() {
    return weighted_avg;
}

char COP3014::get_letter_grade() {
    return letter_grade;
}

//prints z number, quiz and test scores, along with weighted average and letter grades
void COP3014::print_student_data(ostream& outs) {
    outs << "Z Number: " << get_z_number()
         << "\nQuiz 1: " << get_quiz_1() << "/10"
         << "\nQuiz 2: " << get_quiz_2() << "/10"
         << "\nMidterm: " << get_midterm() << "/100"
         << "\nFinal: " << get_final() << "/100"
         << "\nWeighted Average: " << get_weighted_avg() << "%"
         << "\nLetter Grade: " << get_letter_grade() << "\n\n";
}

//calls two private functions to calculate weighted average and letter grade
void COP3014::calculate_grades() {
    calculate_weighted_avg();
    calculate_letter_grade();
}

/* Since quiz 1 and 2 are out of 10, and each one is worth 10% of the final grade, there is no need
 * to normalize the quiz scores. The first commented line, line 228, shows what it would look like to
 * normalize the quiz scores. The sum of the quizzes divided by 20, then multiplied by 20, is the same
 * thing as just adding the quizzes together. If the final was worth 40%, the midterm 30%, and the quizzes
 * 15% each, then the second commented line, line 229, would be used. In that case, normalizing the quiz 
 * scores would be necessary.
 */
void COP3014::calculate_weighted_avg() {
    weighted_avg = quiz_1 + quiz_2 + 0.3*midterm + 0.5*final_exam;
    // weighted_avg = ((quiz_1 + quiz_2)/20)*20 + 0.3*midterm + 0.5*final_exam;
    // weighted_avg = ((quiz_1 + quiz_2)/20)*30 + 0.3*midterm + 0.4*final_exam;
    
}

//assigns char to letter_grade depending on what range it falls into
void COP3014::calculate_letter_grade() {
    if (weighted_avg < 60) letter_grade = 'F';
    else if (weighted_avg < 70) letter_grade = 'D';
    else if (weighted_avg < 80) letter_grade = 'C';
    else if (weighted_avg < 90) letter_grade = 'B';
    else letter_grade = 'A';
}


