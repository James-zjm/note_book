#pragma once

#include <QDialog>
#include <string>
#include "ui_AddCourse.h"
#include "Course.h"

class AddCourse : public QDialog
{
	Q_OBJECT

public:
	AddCourse(std::string sch[],std::string &obj,QWidget *parent = Q_NULLPTR);
	~AddCourse();
	Course *corr;
	std::string schedule[26];
private:
	QPushButton * courseButton[26];
	Ui::AddCourse ui;
	Course *xxx;
	std::string obj_path;
private slots:
	void getName();
	void changecolor();
	void determine();
};
