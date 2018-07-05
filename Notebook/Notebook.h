#pragma once

#include <QtWidgets/QMainWindow>
#include <string>
#include <iostream>
#include <vector>
#include<ostream>
#include <sstream>
#include <fstream>
#include <QInputDialog>
#include <vector>
#include  <direct.h>  

#include "ui_Notebook.h"
#include "Notelist.h"
#include "AddCourse.h"
#include "Course.h"
#include "Identity.h"
#include "Sql.h"
extern Identity ID;

class Notebook : public QMainWindow
{
	Q_OBJECT

public:
	Notebook(QWidget *parent = Q_NULLPTR);
private:
	Ui::NotebookClass ui;

	QPushButton * courseButton[26];
	std::string schedule[26];
	std::vector <Course> course;
	Notelist *view;
	AddCourse* add;
	std::string obj_path;
private slots:
	void gotocourse();
	void addcourse();
	void deletecourse();
	void synchronize();
};
