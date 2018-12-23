#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;

//stores each index, mark and grade of a student in a certain subject
//each Subject has its own Student records
class Student {
    private:
        string studentID;
        int studentMark;
        char studentGrade;
    public:
        string getStudentID(void) {return studentID;}
        int getStudentMark(void) {return studentMark;}
        char getStudentGrade(void) {return studentGrade;}
        
        Student(string studentID, int studentMark) {
            this -> studentID = studentID;
            this -> studentMark = studentMark;

            if (studentMark >= 70) {studentGrade = 'A';}
            else if (studentMark >= 55) {studentGrade = 'B';}
            else if (studentMark >= 40) {studentGrade = 'C';}
            else if (studentMark >= 30) {studentGrade = 'D';}
            else {studentGrade = 'F';}
        }
};

//stores subject details and a pointer to Student pointer array
class Subject {
    private:
        string subjectCode;
        Student **studentArray; //pointer to array of Student pointers
        int studentCount, countA, countB, countC, countD, countF;
        float totalMarks, averageMark, variance, standardDeviation;
    public:
        //creating a Student object requires a pre-build Student array which has the Student records of that certain subject
        //here, studentArray is the array which has records of marks of that subject
        Subject(string subjectCode, Student **studentArray, int studentCount) {
        	countA = countB = countC = countD = countF = 0;
        	totalMarks = averageMark = variance = standardDeviation = 0;
        	
            this -> subjectCode = subjectCode;
            this -> studentArray = studentArray;
            this -> studentCount = studentCount;
            
            for (int studentIterator = 0; studentIterator < studentCount; studentIterator++) {
                Student tempStudent = *studentArray[studentIterator];
                totalMarks += tempStudent.getStudentMark();

                if (tempStudent.getStudentGrade() == 'A') countA++;
                else if (tempStudent.getStudentGrade() == 'B') countB++;
                else if (tempStudent.getStudentGrade() == 'C') countC++;
                else if (tempStudent.getStudentGrade() == 'D') countD++;
                else if (tempStudent.getStudentGrade() == 'F') countF++;
            }

            averageMark = totalMarks/studentCount; //needed to find variance

            for (int studentIterator = 0; studentIterator < studentCount; studentIterator++) {
                Student tempStudent = *studentArray[studentIterator];
                variance += pow((tempStudent.getStudentMark() - averageMark), 2);
            }

            variance /= studentCount;
            standardDeviation = sqrt(variance);
        }
        
        string getSubjectCode(void) {return subjectCode;}
        int getStudentCount(void) {return studentCount;}
        Student **getStudentArray(void) {return studentArray;}
        
        float getAverageMark(void) {return averageMark;}
        float getStandardDeviation(void) {return standardDeviation;}

        int getCountA(void) {return countA;}
        int getCountB(void) {return countB;}
        int getCountC(void) {return countC;}
        int getCountD(void) {return countD;}
        int getCountF(void) {return countF;}

        Student *getStudent(string studentID) {
            for (int studentIterator = 0; studentIterator < studentCount; studentIterator++)
                if (studentArray[studentIterator] -> getStudentID() == studentID) return studentArray[studentIterator];
            return NULL;
        }

        ~Subject() {
            for (int studentIterator = 0; studentIterator < studentCount; studentIterator++) 
                delete(studentArray[studentIterator]);
        }
};

Subject **subjectArray;
int subjectArrayCount = 0;

Student **studentArray; //temporary holder of student array
//every Subject object has it's own studentArray

int init() {
    ifstream dataFile("subjdata.txt");
    string line, subjectCode, studentID;
    int studentCount, studentMark, subjectIterator = -1;
    
    if (!dataFile.is_open()) return 1; //file open failure

    //count number of subjects
    while (getline(dataFile, line)) {
        studentCount = atoi(line.substr(line.find(' ') + 1).c_str());
        for (int i = 0; i < studentCount; i++) getline(dataFile, line); //skip over student marks TODO: Seek line instead of reading
        subjectArrayCount++;
    } 

    //init subject array of size subjectArrayCount
    if (subjectArrayCount > MAXSUBJECTS) return 2;
    subjectArray = new Subject*[subjectArrayCount];

    //reset file pointer
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    //parse data
    while (getline(dataFile, line)) {
        subjectIterator++;

        subjectCode = line.substr(0, line.find(' '));
        studentCount = atoi(line.substr(line.find(' ') + 1).c_str());

        if (studentCount > MAXSTUDENTS) return 3;
        studentArray = new Student*[studentCount]; //create array for storing student marks
        
        for (int studentIterator = 0; studentIterator < studentCount; studentIterator++) {
            getline(dataFile, line);
            studentID = line.substr(0, line.find(' '));
            studentMark = atoi(line.substr(line.find(' ') + 1).c_str());

            studentArray[studentIterator] = new Student(studentID, studentMark);
        }

        //create array for subject
        subjectArray[subjectIterator] = new Subject(subjectCode, studentArray, studentCount);
        //each subject has it's own student array for storing the subject's own marks and correspoiding student ids
    }

    dataFile.close();
    return 0;
}

int main(void) {
    string subjectCode, studentID;
    Subject *tempSubject;
    Student **tempSubjectStudentArray, *tempStudent;
    int tempMark, option = 0, flag = 0;
    ofstream outputDataFile;

    if (init()) {
        cout << "ERROR: File not found!" << endl;
        return 1;
    }

    while (true) {
        cout << "\nSelect an option..\n";
        cout << "\t1. Display subject\n";
        cout << "\t2. Display student\n";
        cout << "\t3. Display subject summary\n";
        cout << "\t4. Save summaries\n";
        cout << "\t5. Exit programme\n";
        cout << ":";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                cout << "Enter subject code: ";
                cin >> subjectCode;
                flag = false; //false == doesn't exist
                for (int subjectIterator = 0; subjectIterator < subjectArrayCount; subjectIterator++) {
                    tempSubject = subjectArray[subjectIterator];
                    if (tempSubject -> getSubjectCode() == subjectCode) {
                        flag = true;
                        tempSubjectStudentArray = (tempSubject -> getStudentArray());

                        cout << "\n\nMARKS OF SUBJECT " << subjectCode << endl;
                        for (int studentIterator = 0; studentIterator < tempSubject -> getStudentCount(); studentIterator++) {
                            tempStudent = tempSubjectStudentArray[studentIterator];

                            cout << "ID: " <<  tempStudent -> getStudentID() << "\t";
                            cout << "Mark: " << tempStudent -> getStudentMark() << "\t";
                            cout << "Grade: " << tempStudent -> getStudentGrade() << endl;
                        }
                        break;
                    } 
                }
                if (!flag) cout << "ERROR: Subject not found!\n\n";
                break;
            case 2:
                cout << "Enter student ID: ";
                cin >> studentID;

                cout << "\nMARKS OF STUDENT " << studentID << endl;
                for (int subjectIterator = 0; subjectIterator < subjectArrayCount; subjectIterator++) {
                    tempSubject = subjectArray[subjectIterator];
                    cout << "Subject: " << tempSubject -> getSubjectCode();
                    if (tempSubject -> getStudent(studentID) == NULL) cout << "\tNo records found!" << endl;
                    else {
                        cout << "\tMark: " << tempSubject -> getStudent(studentID) -> getStudentMark();
                        cout << "\tGrade: " << tempSubject -> getStudent(studentID) -> getStudentGrade() << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter subject code: ";
                cin >> subjectCode;
                flag = false; //false == doesn't exist

                for (int subjectIterator = 0; subjectIterator < subjectArrayCount; subjectIterator++) {
                    tempSubject = subjectArray[subjectIterator];
                    if (tempSubject -> getSubjectCode() == subjectCode) {
                        flag = true;
                        cout << "\nSUMMARY OF SUBJECT " << tempSubject -> getSubjectCode();
                        cout << "\nAverageMark: " << std::fixed << setfill('0') << setprecision(1) << tempSubject -> getAverageMark();
                        cout << "\t\tStandardDeviation: " << std::fixed << setfill('0') <<  setprecision(1) << tempSubject -> getStandardDeviation();
                        cout << "\nA: " << tempSubject -> getCountA();
                        cout << "\tB: " << tempSubject -> getCountB();
                        cout << "\tC: " << tempSubject -> getCountC();
                        cout << "\tD: " << tempSubject -> getCountD();
                        cout << "\tF: " << tempSubject -> getCountF() << endl;
                        break;
                    }
                }
                if (!flag) cout << "ERROR: Subject not found!\n\n";
                break;
            case 4:
                outputDataFile.open("summdata.txt");
                for (int subjectIterator = 0; subjectIterator < subjectArrayCount; subjectIterator++) {
                    tempSubject = subjectArray[subjectIterator];
                    outputDataFile << tempSubject -> getSubjectCode() << " ";
                    outputDataFile << tempSubject -> getStudentCount();
                    outputDataFile << " A " << std::fixed << setfill('0') << setprecision(1) << (float) (tempSubject -> getCountA())/(tempSubject -> getStudentCount())*100 << "%";
                    outputDataFile << " B " << std::fixed << setfill('0') << setprecision(1) << (float) (tempSubject -> getCountB())/(tempSubject -> getStudentCount())*100 << "%";
                    outputDataFile << " C " << std::fixed << setfill('0') << setprecision(1) << (float) (tempSubject -> getCountC())/(tempSubject -> getStudentCount())*100 << "%";
                    outputDataFile << " D " << std::fixed << setfill('0') << setprecision(1) << (float) (tempSubject -> getCountD())/(tempSubject -> getStudentCount())*100 << "%";
                    outputDataFile << " F " << std::fixed << setfill('0') << setprecision(1) << (float) (tempSubject -> getCountF())/(tempSubject -> getStudentCount())*100 << "%" << endl;
                }

                outputDataFile.close();
                cout << "\nSummary saved successfully..\n";
                break;
            case 5:
                cout << "Goodbye...\n";
                return 0;
            default:
                cout << "\nPlease try again..\n";
                break;
        }
    }
}
