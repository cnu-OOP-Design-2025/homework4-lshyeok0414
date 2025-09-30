#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) : midterm(midterm), final(final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{}

float StudentRecord::getTotal() const {
    return final+midterm;
}

void StudentRecord::updateScores(float midterm, float final) {
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student() : name(""), id()
/* TODO: Initializer list 사용해 초기화 해보기 */
{ }

Student::Student(const char *name, int id, float midterm, float final) : name(name), id(id), record(midterm, final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{}


void Student::updateRecord(const char *name, float midterm, float final) {
    this->name = std::string(name);
    this->record.updateScores(midterm,final);
}

