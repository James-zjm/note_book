#pragma once

#include <QWidget>
#include <string>
#include<QInputDialog>
#include <regex>
#include<ostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <QCloseEvent>
#include "ui_Notelist.h"
#include "course.h"
#include "Sql.h"
#include "Identity.h"

extern Identity ID;

class Note : public QWidget
{
	Q_OBJECT
public:
	Note(std::string nam, std::string path, QWidget *parent = NULL) : QWidget(parent),adress(path),name(nam)
	{
		QHBoxLayout *playout = new QHBoxLayout(this);
		QVBoxLayout *playout2 = new QVBoxLayout(this);
		title = new QLineEdit;
		title->setText(name.c_str());
		title->setReadOnly(true);

		openButton = new QPushButton;
		openButton->setObjectName(name.c_str());
		openButton->setText("OPEN");
		connect(openButton, SIGNAL(clicked()), this, SLOT(open_note()));

		deleteButton = new QPushButton;
		openButton->setObjectName(name.c_str());
		deleteButton->setText("DELETE");

		playout->addWidget(title);
		playout2->addWidget(openButton);
		playout2->addWidget(deleteButton);
		playout->addLayout(playout2);
	}
	std::string name;
	std::string adress;
	QPushButton *deleteButton;
	std::string id;
private:
	QLineEdit* title;
	QPushButton *openButton;
private slots:
	void open_note();//打开笔记
};

class Notelist : public QWidget
{
	Q_OBJECT

public:
	Notelist(Course input,QWidget *parent = Q_NULLPTR);//构造
	~Notelist();
private:
	Ui::Notelist ui;
	Course *course;
	std::vector<Note*> list;
	int note_num = 0;
private slots:
	void delete_note();
	void new_note();//新建笔记
	void search_note();//搜索笔记
	void closeEvent(QCloseEvent *event);//重写关闭函数
};
