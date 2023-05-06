#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include<QMap>

#include "LecHall.h"

class Course {
    private:
        QString name;
        QString code;
        QString lecHall;
      //  std::map <QString, float> students;
        QString day;
        QString time;


    public:

        QVector <QString> professorsForCourse;   //code

         //code--->course
        static QMap<QString, Course> courses;

         //ID_Student---->grade
        QMap<QString, float> studentsGrade;

        Course();
        Course(QString n, QString c);

        QString getCourseName();
        QString getCode();
        QString getLecHall();
        QString getLecTime();
        QString getLecDay();

        void setCourseName(QString);
        void setCode(QString);
        void setLecHall(QString);
        void setLecTime(QString);
        void setLecDay(QString);

};
#endif // COURSE_H
