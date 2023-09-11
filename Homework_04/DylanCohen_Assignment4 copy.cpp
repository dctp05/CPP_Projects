#include <iostream>     

using namespace std;

class COP3014 {
    public:
        COP3014();
        COP3014(int z_num, double quiz1, double quiz2, double mid, double fin_exam);
        COP3014(double quiz1, double quiz2, double mid, double fin_exam);
        void set(int z_num, double quiz1, double quiz2, double mid, double fin_exam);
        
        int get_z_number();
        double get_quiz_1();
        double get_quiz_2();
        double get_midterm();
        double get_final();
        double get_weighted_avg();
        char get_letter_grade();

        void print_student_data(ostream& outs);
        void calculate_grades();
   
    private:
        void calculate_weighted_avg();
        void calculate_letter_grade();

        int z_number;
        double quiz_1;
        double quiz_2;
        double midterm;
        double final_exam;
        double weighted_avg;
        char letter_grade;
};

void process_and_print_grades(COP3014& student);
void student_from_user_input(COP3014& student);

int main() {
    COP3014 student_a(32445, 7, 7, 80, 70), student_b(8, 7.6, 75.3, 92.4), student_c, student_d;
    student_d.set(32445, 7, 7, 80, 70);

    process_and_print_grades(student_a);
    process_and_print_grades(student_b);
    process_and_print_grades(student_c);
    process_and_print_grades(student_d);
   
    int continue_loop = 1;
    do {
        student_from_user_input(student_c);
        
        cout << "Enter data for another student? (1 for yes/0 for no): ";
        cin >> continue_loop;
    } while (continue_loop == 1);

    cout << "\nThank you for using the program. Have a nice day!";

    return 0;
}

void process_and_print_grades(COP3014& student) {
    student.calculate_grades();
    student.print_student_data(cout);
}

void student_from_user_input(COP3014& student) {
    int z_num;
    double quiz1, quiz2, mid, fin_exam;
    
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
    
    student.set(z_num, quiz1, quiz2, mid, fin_exam);

    process_and_print_grades(student);
}

COP3014::COP3014() {
    z_number = 0;
    quiz_1 = 0;
    quiz_2 = 0;
    midterm = 0;
    final_exam = 0;
}

COP3014::COP3014(double quiz1, double quiz2, double mid, double fin_exam) {
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}

COP3014::COP3014(int z_num, double quiz1, double quiz2, double mid, double fin_exam) {
    z_number = z_num;
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}

void COP3014::set(int z_num, double quiz1, double quiz2, double mid, double fin_exam) {
    if (z_num < 0 || quiz1 < 0 || quiz2 < 0 || mid < 0 || fin_exam < 0) {
        cout << "Illegal values for Z-number or test scores.\n";
        exit(1);
    }
    
    z_number = z_num;
    quiz_1 = quiz1;
    quiz_2 = quiz2;
    midterm = mid;
    final_exam = fin_exam;
}


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

void COP3014::print_student_data(ostream& outs) {
    outs << "Z Number: " << get_z_number()
         << "\nQuiz 1: " << get_quiz_1() << "/10"
         << "\nQuiz 2: " << get_quiz_2() << "/10"
         << "\nMidterm: " << get_midterm() << "/100"
         << "\nFinal: " << get_final() << "/100"
         << "\nWeighted Average: " << get_weighted_avg() << "%"
         << "\nLetter Grade: " << get_letter_grade() << "\n\n";
}

void COP3014::calculate_grades() {
    calculate_weighted_avg();
    calculate_letter_grade();
}

void COP3014::calculate_weighted_avg() {
    weighted_avg = quiz_1 + quiz_2 + 0.3*midterm + 0.5*final_exam;
}

void COP3014::calculate_letter_grade() {
    if (weighted_avg < 60) letter_grade = 'F';
    else if (weighted_avg < 70) letter_grade = 'D';
    else if (weighted_avg < 80) letter_grade = 'C';
    else if (weighted_avg < 90) letter_grade = 'B';
    else letter_grade = 'A';
}
