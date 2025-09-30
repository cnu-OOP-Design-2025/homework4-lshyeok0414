#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    last_student_id++;
    students[num_of_students] = Student(name, last_student_id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    int deleteidx = -1;
    for(int i = 0; i < num_of_students; i++){
        if(id == students[i].getID()){
            deleteidx = i;
        }
    }
    if(deleteidx > -1){
        for(int i = deleteidx; i < num_of_students; i++){
            students[i] = students[i+1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    for(int i = 0; i < num_of_students; i++){
        if(student.getID() == students[i].getID()){
            students[i].updateRecord(student.getName().c_str(),student.getRecord().getMidterm(),student.getRecord().getFinal());
            break;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    for(int i = 0; i < num_of_students; i++){
        if(id == students[i].getID()){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    int idx = 0;
    float bestMid = 0;
    for(int i = 0; i < num_of_students; i++){
        if(bestMid < students[i].getRecord().getMidterm()){
            idx = i;
            bestMid = students[i].getRecord().getMidterm();
        }
    }
    return idx;
    return -1;
}

int StudentManager::findBestStudentInFinal() const {
    int idx = 0;
    float bestFin = 0;
    for(int i = 0; i < num_of_students; i++){
        if(bestFin < students[i].getRecord().getFinal()){
            idx = i;
            bestFin = students[i].getRecord().getFinal();
        }
    }
    return idx;
    return -1;
}

int StudentManager::findBestStudent() const {
    int idx = 0;
    int bestSum = 0;
    int sum;
    for(int i = 0; i < num_of_students; i++){
        sum = students[i].getRecord().getTotal();
        if(bestSum < sum){
            idx = i;
            bestSum = sum;
        }
    }
    return students[idx].getID();
    return -1;
}

float StudentManager::getMidtermAverage() const {
    float sum = 0;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getMidterm();
    }

    return sum / (float)num_of_students;
}

float StudentManager::getFinalAverage() const {
    
    float sum = 0;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getFinal();
    }

    return sum / (float)num_of_students;
}

float StudentManager::getTotalAverage() const {

    float sum = 0;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getTotal();
    }

    return sum / (float)num_of_students;
}

