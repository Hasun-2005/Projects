#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    int CourseID;
    int CourseNumber;
    string CourseName;
    string Description;
    string Date;

public:
    void setCourseID(int newCourseID) { CourseID = newCourseID; }
    int getCourseID() const { return CourseID; }

    void setCourseNumber(int newCourseNumber) { CourseNumber = newCourseNumber; }
    int getCourseNumber() const { return CourseNumber; }

    void setCourseName(const string& newCourseName) { CourseName = newCourseName; }
    string getCourseName() const { return CourseName; }

    void setDescription(const string& newDescription) { Description = newDescription; }
    string getDescription() const { return Description; }

    void setDate(const string& newDate) { Date = newDate; }
    string getDate() const { return Date; }
};

class User : public Course {
private:
    int UserID;
    string UserName;
    string Password;
    string Email;
    string Role;

public:
    void setUserID(int newUserID) { UserID = newUserID; }
    int getUserID() const { return UserID; }

    void setUserName(const string& newUserName) { UserName = newUserName; }
    string getUserName() const { return UserName; }

    void setPassword(const string& newPassword) { Password = newPassword; }
    string getPassword() const { return Password; }

    void setEmail(const string& newEmail) { Email = newEmail; }
    string getEmail() const { return Email; }

    void setRole(const string& newRole) { Role = newRole; }
    string getRole() const { return Role; }
};

class Assignment : public User {
private:
    int AssignmentID;
    string Title;
    string DueDate;
    string Instructions;

public:
    void setAssignmentID(int newAssignmentID) { AssignmentID = newAssignmentID; }
    int getAssignmentID() const { return AssignmentID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setDueDate(const string& newDueDate) { DueDate = newDueDate; }
    string getDueDate() const { return DueDate; }

    void setInstructions(const string& newInstructions) { Instructions = newInstructions; }
    string getInstructions() const { return Instructions; }
};

class Module : public Course {
private:
    int ModuleID;
    string Title;
    string DueDate;
    string Instructions;

public:
    void setModuleID(int newModuleID) { ModuleID = newModuleID; }
    int getModuleID() const { return ModuleID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setDueDate(const string& newDueDate) { DueDate = newDueDate; }
    string getDueDate() const { return DueDate; }

    void setInstructions(const string& newInstructions) { Instructions = newInstructions; }
    string getInstructions() const { return Instructions; }
};

class Resources : public Module {
private:
    int ResourceID;
    string Title;
    string FileType;
    string Content;

public:
    void setResourceID(int newResourceID) { ResourceID = newResourceID; }
    int getResourceID() const { return ResourceID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setFileType(const string& newFileType) { FileType = newFileType; }
    string getFileType() const { return FileType; }

    void setContent(const string& newContent) { Content = newContent; }
    string getContent() const { return Content; }
};

class Quiz : public Module {
private:
    int QuizID;
    string Questions;
    float TimeLimit;

public:
    void setQuizID(int newQuizID) { QuizID = newQuizID; }
    int getQuizID() const { return QuizID; }

    void setQuestions(const string& newQuestions) { Questions = newQuestions; }
    string getQuestions() const { return Questions; }

    void setTimeLimit(float newTimeLimit) { TimeLimit = newTimeLimit; }
    float getTimeLimit() const { return TimeLimit; }
};

class GradeBook : public Quiz {
private:
    int GradeID;
    float Score;
    string Gradebook;

public:
    void setGradeID(int newGradeID) { GradeID = newGradeID; }
    int getGradeID() const { return GradeID; }

    void setScore(float newScore) { Score = newScore; }
    float getScore() const { return Score; }

    void setGradebook(const string& newGradebook) { Gradebook = newGradebook; }
    string getGradebook() const { return Gradebook; }
};

int main() {
    // Example object creation and setting values this is for testing
        //Course course;
       // course.setCourseID(101);
        //course.setCourseName("Introduction to Programming");
       // course.setCourseNumber(1);
       // course.setDescription("A beginner course in programming.");
       // course.setDate("2023-09-01");
       // cout << "Course ID: " << course.getCourseID() << endl;
      //  cout << "Course Name: " << course.getCourseName() << endl;
       // cout << "Course Number: " << course.getCourseNumber() << endl;
      //  cout << "Description: " << course.getDescription() << endl;
        //cout << "Date: " << course.getDate() << endl;
        int options;
        string start;
        cout << "Press Y for yes" << endl;
        cout << "Press N for no" << endl;
        cout << "Would you like to start:" << endl;
        cin >> start;

        if (start == "Y" || start == "y") {
            cout << "Welcome to the student management system!" << endl;
            cout << "Would you like to start" << endl;
            cout << endl;

            cout << "What is your role" << endl;
            cout << "Press 1 if you are a lecturer" << endl;
            cout << "Press 2 if you are a student" << endl;
            cout << "Press anything else if you are anything else:" << endl;
            cin >> options;

            if (options == 1) {
                int lecturercourses;
                Course course;
                cout << "Welcome lecturer!" << endl;
                cout << "How many courses would you like to see";
                cin >> lecturercourses;


            }
            else if (options == 2) {
                int studentcourses;
                cout << "Welcome student!" << endl;
            }
            else {
                cout << "Welcome visitor!" << endl;
            }
        }

        return 0;
}






