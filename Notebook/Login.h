#pragma once

#include <QDialog>
#include<QInputDialog>
#include<QMessageBox>.
#include <iostream>  
#include <fstream>
#include"Sql.h"
#include "ui_Login.h"
#include "Sql.h"
#include "Identity.h"
extern "C" {
#include "Sql.h";  
}


extern Identity ID;

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
private:
	char* isvalid;
	Ui::Login ui;
private slots:
	void on_check();
	void on_new();
};
