QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddCoursePage.cpp \
    AddProfessorPage.cpp \
    AddStudentPage.cpp \
    AdminEditPage.cpp \
    AdminInfoPage.cpp \
    CourseEditPage.cpp \
    CourseInfoPage.cpp \
    CoursePage.cpp \
    HomePage.cpp \
    LecHall.cpp \
    ProfessorEditPage.cpp \
    ProfessorInfoPage.cpp \
    ProfessorPage.cpp \
    SignupPage.cpp \
    StudentEditPage.cpp \
    StudentInfoPage.cpp \
    StudentPage.cpp \
    admin.cpp \
    course.cpp \
    main.cpp \
    LoginPage.cpp \
    professor.cpp \
    student.cpp

HEADERS += \
    AddCoursePage.h \
    AddProfessorPage.h \
    AddStudentPage.h \
    AdminEditPage.h \
    AdminInfoPage.h \
    CourseEditPage.h \
    CourseInfoPage.h \
    CoursePage.h \
    HomePage.h \
    LecHall.h \
    LoginPage.h \
    ProfessorEditPage.h \
    ProfessorInfoPage.h \
    ProfessorPage.h \
    SignupPage.h \
    StudentEditPage.h \
    StudentInfoPagee.h \
    StudentPage.h \
    User.h \
    admin.h \
    course.h \
    professor.h \
    student.h

FORMS += \
    AddCoursePage.ui \
    AddProfessorPage.ui \
    AddStudentPage.ui \
    AdminEditPage.ui \
    AdminInfoPage.ui \
    CourseEditPage.ui \
    CourseInfoPage.ui \
    CoursePage.ui \
    HomePage.ui \
    LoginPage.ui \
    ProfessorEditPage.ui \
    ProfessorInfoPage.ui \
    ProfessorPage.ui \
    SignupPage.ui \
    StudentEditPage.ui \
    StudentInfoPage.ui \
    StudentPage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

