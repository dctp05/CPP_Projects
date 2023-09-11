/*
Yontrey Bush
COP3014
Assignment 4
Class Assignment
10/15/22
*/

#include<iostream>
using namespace std;

class COP3014
{
    double quiz1, quiz2, fin_exam, midterm, stave;
    int Znum;
    char grade;

    public:
        COP3014(int z_num, double quiz_1, double quiz_2, double mid, double final_exam);
        // COP3014( int Znum, double quiz1, double quiz2, double midterm, double fin_exam)
        // {
        //     if((Znum < 0)||(quiz1 < 0)||(quiz2 < 0 )||(midterm < 0)||(fin_exam < 0))
        //     {
        //         cout << "Input Invalid";
        //         exit(1);
        //     } else
        //     {
        //         this-> Znum = Znum;
        //         this-> quiz1 = quiz1;
        //         this-> quiz2 = quiz2;
        //         this-> midterm = midterm;
        //         this-> fin_exam = fin_exam;
        //     }
        // }
        void Average();
        void set_grade(double stave);
        void display(int Znum, double quiz1, double quiz2, double midterm, double fin_grade, double stave, char grade);
        double get_quiz1()
        {return quiz1;}
        double get_quiz2()
        {return quiz2;}
        double get_mid()
        {return midterm;}
        double get_fin()
        {return fin_exam;}
        double get_ave()
        {return stave;}
        char get_grade()
        {return grade;}
        int get_Znum()
        {return Znum;}
};

int main()
{
    COP3014 student(23632980, 9, 9, 90, 80);
    student.Average();
    student.set_grade(student.get_ave());
    student.display(student.get_Znum(),student.get_quiz1(),student.get_quiz2(),student.get_mid(),student.get_fin(), student.get_ave(), student.get_grade());
    return 0;
}

//Definitions
COP3014::COP3014(int z_num, double quiz_1, double quiz_2, double mid, double final_exam)
{
    if((z_num < 0)||(quiz_1 < 0)||(quiz_2 < 0 )||(mid < 0)||(final_exam < 0))
    {
        cout << "Input Invalid";
        exit(1);
    } else
    {
        Znum = z_num;
        quiz1 = quiz_1;
        quiz2 = quiz_2;
        midterm = mid;
        fin_exam = final_exam;
    }
}

void COP3014::Average()
{    
    stave = (quiz1 + quiz2) + (fin_exam * 0.5) + (midterm * 0.3);
}

void COP3014::set_grade(double stave)
{
    if(stave >= 90)
    {
        grade = 'A';
    }else if(stave>=80 && stave<90)
    {
        grade = 'B';
    }else if(stave >= 70 && stave < 80)
    {
        grade = 'C';
    }else if(stave >= 60 && stave < 70)
    {
        grade = 'D';
    }else if(stave < 60)
    {
        grade = 'F';
    }
}

void COP3014::display(int Znum, double quiz1, double quiz2, double midterm, double fin_exam,double stave, char grade)
{
    cout << "Ok, Z"<< get_Znum() << ", Here are your grades:" << endl
    << "Quiz 1:" << get_quiz1() << endl
    << "Quiz 2:" << get_quiz2() << endl
    << "Midterm:"<< get_mid() << endl
    << "Final Exam:" << get_fin() << endl
    << "Average:" << get_ave() << endl
    << "Your Letter Grade:"<< get_grade() << endl;
}