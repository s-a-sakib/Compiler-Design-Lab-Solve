/*
    Write a program that abbreviates the following code:
    CSE-3141 as Computer Science & Engineering, 3rd Year, 1st Semester, Compiler Design, Theory.
*/ 


#include <bits/stdc++.h>
using namespace std;

// Function to map department codes to full department names
string dept(const string& str) {
    map<string, string> departments = {
        {"CSE", "Computer Science & Engineering"},
        {"EEE", "Electrical & Electronic Engineering"},
        {"ICE", "Information & Communication Engineering"},
        {"CHEM", "Chemistry"},
        {"MATH", "Mathematics"},
        {"ENG", "English"},
        {"STAT", "Statistics"},
        {"PHY", "Physics"},
        {"LAW", "Cyber Law"},
        {"ACCO", "Accounting and Management"}
    };

    return departments[str];
}

// Function to map year numbers to their full form
string year(char c) {
    map<char, string> years = {
        {'1', "1st Year"},
        {'2', "2nd Year"},
        {'3', "3rd Year"},
        {'4', "4th Year"}
    };

    return years[c];
}

// Function to map semester numbers to their full form
string semester(char c) {
    return c == '1' ? "1st Semester" : "2nd Semester";
}

// Function to map course types to their full form
string type(char c) {
    return c == '1' ? "Theory" : "Lab";
}

// Function to map course codes to course names
string courseName(const string& str) {
    map<string, string> courses = {
        {"CSE-4211", "Machine Learning"},
        {"CSE-4212", "Machine Learning Lab"},
        {"CSE-4221", "Computer Graphics"},
        {"CSE-4222", "Computer Graphics Lab"},
        {"CSE-4231", "Cryptography and Network Security"},
        {"CSE-4232", "Cryptography and Network Security Lab"},
        {"CSE-4241", "Multimedia System"},
        {"CSE-4242", "Multimedia System Lab"},
        {"CSE-4251", "Distributed Database Management System"},
        {"CSE-4252", "Distributed Database Management System Lab"},
        {"CSE-4261", "Neural Networks and Deep Learning"},
        {"CSE-4262", "Neural Networks and Deep Learning Lab"},
        {"CSE-4271", "Big Data"},
        {"CSE-4272", "Big Data Lab"},
        {"CSE-4280", "Board viva-voce"},
        {"CSE-4281", "Systems Biology"},
        {"CSE-4282", "Systems Biology Lab"},
        {"CSE-4292", "Thesis/ Project (Part II)"},
        {"CSE-4111", "Parallel Processing and Distributed System"},
        {"CSE-4112", "Parallel Processing and Distributed System Lab"},
        {"CSE-4121", "Object Oriented Design and Design Patterns"},
        {"CSE-4122", "Object Oriented Design and Design Patterns Lab"},
        {"CSE-4131", "Artificial Intelligence"},
        {"CSE-4132", "Artificial Intelligence Lab"},
        {"CSE-4141", "Microprocessor Interfacing and Microcontrollers"},
        {"CSE-4142", "Microprocessor Interfacing and Microcontrollers Lab"},
        {"CSE-4151", "Computational Geometry"},
        {"CSE-4152", "Computational Geometry Lab"},
        {"CSE-4161", "Digital Image Processing"},
        {"CSE-4162", "Digital Image Processing Lab"},
        {"CSE-4171", "Computer Simulation and Modeling"},
        {"CSE-4172", "Computer Simulation and Modeling Lab"},
        {"CSE-4181", "UI UX Engineering"},
        {"CSE-4182", "UI UX Engineering Lab"},
        {"CSE-4191", "Blockchain"},
        {"CSE-4192", "Blockchain Lab"},
        {"CSE-4192", "Thesis/ Project (Part I)"},
        {"CSE-3211", "Project Planning & Management"},
        {"CSE-3221", "Digital Signal Processing"},
        {"CSE-3222", "Digital Signal Processing Lab"},
        {"CSE-3231", "Microprocessor and Assembly Language"},
        {"CSE-3232", "Microprocessor and Assembly Language Lab"},
        {"CSE-3241", "Operating Systems"},
        {"CSE-3242", "Operating Systems Lab"},
        {"CSE-3251", "Computer Networks"},
        {"CSE-3252", "Computer Networks Lab"},
        {"CSE-3111", "Software Engineering"},
        {"CSE-3112", "Software Engineering Lab"},
        {"CSE-3121", "Database Management Systems"},
        {"CSE-3122", "Database Management Systems Lab"},
        {"CSE-3131", "Web Engineering"},
        {"CSE-3132", "Web Engineering Lab"},
        {"CSE-3141", "Compiler Design"},
        {"CSE-3142", "Compiler Design Lab"},
        {"CSE-3151", "Engineering Ethics and Environment Protection"},
        {"ICE-3161", "Communication Engineering"},
        {"CSE-3162", "Mobile Application Development Lab"},
        {"LAW-2211", "Cyber and Intellectual Property Law"},
        {"MATH-2231", "Numerical Methods"},
        {"MATH-2232", "Numerical Methods Lab"},
        {"MATH-2241", "Linear Algebra"},
        {"CSE-2211", "Theory of Computation"},
        {"CSE-2221", "Design and Analysis of Algorithms"},
        {"CSE-2222", "Design and Analysis of Algorithms Lab"},
        {"CSE-2231", "Computer Architecture and Organization"},
        {"CSE-2232", "Computer Architecture and Organization Lab"},
        {"CSE-2242", "Technical Writing and Presentation"},
        {"CSE-2252", "Web Application Development Lab"},
        {"ACCO-2111", "Industrial Management and Accountancy"},
        {"STAT-2111", "Theory of Statistics"},
        {"MATH-2131", "Differential Equations and Optimization"},
        {"CSE-2111", "Digital System Design Lab"},
        {"CSE-2112", "Digital System Design"},
        {"CSE-2121", "Data Structure"},
        {"CSE-2122", "Data Structure Lab"},
        {"CSE-2142", "Writing Professional Code Lab"},
        {"CSE-2131", "Discrete Mathematics"},
        {"ECON-1211", "Engineering Economics"},
        {"STAT-1211", "Statistics for Engineers"},
        {"MATH-1221", "Co-ordinate Geometry, Vector analysis and Complex Variable"},
        {"PHY-1211", "Basic Electricity and Electrical Circuits"},
        {"CSE-1211", "Introduction to Digital Electronics"},
        {"CSE-1212", "Introduction to Digital Electronics Lab"},
        {"CSE-1221", "Object Oriented Programming"},
        {"CSE-1222", "Object Oriented Programming Lab"},
        {"ENG-1111", "Technical and Communicative English"},
        {"MATH-1121", "Differential and Integral Calculus"},
        {"CHEM-1121", "Chemistry"},
        {"EEE-1132", "Basic Electronics Lab"},
        {"CSE-1111", "Introduction to Computer Systems"},
        {"CSE-1112", "Computer Maintenance and Engineering Drawing Lab"},
        {"CSE-1121", "Structural Programming Language"},
        {"CSE-1122", "Structural Programming Language Lab"}
    };

    return courses[str];
}

int main() {
    cout << "Input course code: ";
    string courseCode;
    cin >> courseCode;
    cout << endl;

    // Parsing the input course code
    string deptCode = courseCode.substr(0, courseCode.find('-'));
    char yearChar = courseCode[courseCode.find('-') + 1];
    char semChar = courseCode[courseCode.find('-') + 2];
    string fullCourseName = courseName(courseCode);
    char typeChar = courseCode.back();

    // Output the expanded course information
    cout << courseCode << " as " 
         << dept(deptCode) << ", " 
         << year(yearChar) << ", " 
         << semester(semChar) << ", " 
         << fullCourseName << ", " 
         << type(typeChar) << "." 
         << endl;

    return 0;
}
