#include "AddCourse.h"

AddCourse::AddCourse(std::string sch[],std::string &obj, QWidget *parent)
	: QDialog(parent), xxx(nullptr),corr(nullptr),obj_path(obj)
{
	ui.setupUi(this);
	for (int i = 1; i <= 25; i++)
		schedule[i] = sch[i];
	courseButton[1] = ui.pushButton_1;
	courseButton[2] = ui.pushButton_2;
	courseButton[3] = ui.pushButton_3;
	courseButton[4] = ui.pushButton_4;
	courseButton[5] = ui.pushButton_5;
	courseButton[6] = ui.pushButton_6;
	courseButton[7] = ui.pushButton_7;
	courseButton[8] = ui.pushButton_8;
	courseButton[9] = ui.pushButton_9;
	courseButton[10] = ui.pushButton_10;
	courseButton[11] = ui.pushButton_11;
	courseButton[12] = ui.pushButton_12;
	courseButton[13] = ui.pushButton_13;
	courseButton[14] = ui.pushButton_14;
	courseButton[15] = ui.pushButton_15;
	courseButton[16] = ui.pushButton_16;
	courseButton[17] = ui.pushButton_17;
	courseButton[18] = ui.pushButton_18;
	courseButton[19] = ui.pushButton_19;
	courseButton[20] = ui.pushButton_20;
	courseButton[21] = ui.pushButton_21;
	courseButton[22] = ui.pushButton_22;
	courseButton[23] = ui.pushButton_23;
	courseButton[24] = ui.pushButton_24;
	courseButton[25] = ui.pushButton_25;
	for (int i = 1; i < 26; i++)
	{
		if (schedule[i].size() != 0)
		{
			courseButton[i]->setText(schedule[i].c_str());
			courseButton[i]->setStyleSheet("background-color: rgb(200, 200, 0);");
		}
		else
		{
			connect(courseButton[i], SIGNAL(clicked()), this, SLOT(changecolor()));
			courseButton[i]->setStyleSheet("background-color: rgb(2, 2, 2);)");
		}
	}
}

void AddCourse::getName()
{

	if (xxx != nullptr)
	{
		for (int i = 1; i < 26; i++)
		{
			if (schedule[i] == xxx->getName())
			{
				schedule[i].clear();
				courseButton[i]->setStyleSheet("background-color: rgb(2, 2, 2);)");
				courseButton[i]->setText("");
			}
		}
		delete xxx;
	}
	xxx = new Course(ui.lineEdit->text().toStdString(),obj_path);

}
void AddCourse::changecolor()
{
	std::string name = QObject::sender()->objectName().toStdString();
	int pos = name.find('_');
	int co = atoi(name.substr(pos + 1, name.size()).c_str());
	if (schedule[co].size() == 0)
	{
		if (xxx != nullptr)
		{
			courseButton[co]->setStyleSheet("background-color: rgb(0, 255, 0);");
			courseButton[co]->setText((xxx->getName()).c_str());
			schedule[co] = xxx->getName();
		}
	}
	else
	{
		courseButton[co]->setStyleSheet("background-color: rgb(2, 2, 2);)");
		courseButton[co]->setText("");
		schedule[co].clear();
	}
}

void AddCourse::determine()
{
	if(xxx!=nullptr)
		corr = new Course(xxx->getName(),obj_path);
	this->accept();
}
AddCourse::~AddCourse()
{
}
