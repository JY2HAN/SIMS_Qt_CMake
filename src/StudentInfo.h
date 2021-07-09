#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <QString>

class StudentInfo
{
private:
    QString name, grade;
    int id, score, A, B, C;
    double avg;
public:
    StudentInfo();
    StudentInfo(int tid, QString tname, QString tgrade, int tA, int tB, int tC) {
        name = tname;
        grade = tgrade;
        id = tid;
        A = tA;
        B = tB;
        C = tC;
        avg = (tA + tB + tC) / 3.0;
    }
    int getId() {
        return id;
    }
    QString getName() {
        return name;
    }
    QString getGrade() {
        return grade;
    }
    int getA() {
        return A;
    }
    int getB() {
        return B;
    }
    int getC() {
        return C;
    }
    double getAvg() {
        return avg;
    }
    void setId(int tid) {
        id = tid;
    }
    void setName(QString tname) {
        name = tname;
    }
    void setGrade(QString tgrade) {
        grade = tgrade;
    }
    void setA(int tA) {
        A = tA;
        avg = (A + B + C) / 3.0;
    }
    void setB(int tB) {
        B = tB;
        avg = (A + B + C) / 3.0;
    }
    void setC(int tC) {
        C = tC;
        avg = (A + B + C) / 3.0;
    }
};


#endif // STUDENTINFO_H
