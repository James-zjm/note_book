#include "Notebook.h"

Notebook::Notebook(QWidget *parent)
	: QMainWindow(parent)
{
	char obj[100];
	ui.setupUi(this);
	getcwd(obj, sizeof(obj));//获取当前路径
	obj_path = obj;
	obj_path = obj_path + "\\" + ID.getName();
	mkdir(obj_path.c_str());
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

	std::string sch_path = obj_path + "\\Schedule.csv" ;
	char s_path[100];
	sch_path.copy(s_path, sch_path.size(), 0);
	std::ifstream fin(sch_path);
	if (fin)
	{
		remove(sch_path.c_str());
	}
	fin.close();
	download_file(ID.get__name(), "class_0", "E:\\Schedule.csv", "Schedule", "0");
	std::fstream fp(sch_path);//获取当前课表
	std::string line;
	char delims[] = ",";
	char a, b, c;
	int i = 1;
	while (std::getline(fp, line))
	{
		std::istringstream sss(line);
		std::string field;
		while (std::getline(sss, field, ',')) {
			schedule[i++]=field;
			int flag = 0;
			if (field.size() != 0)
			{
				for (int i = 0; i < course.size(); i++)
				{
					if (field == course[i].getName())
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					std::string obj = obj_path;
					Course aas(field,obj);
					course.push_back(aas);
				}
			}
		}
	}
	fp.close();

	std::string cor_path = obj_path + "\\" + "NumToName.csv";
	char c_path[100] = { 0 };
	cor_path.copy(c_path, cor_path.size(), 0);
	std::ifstream fin2(cor_path);
	if (fin2)
	{
		remove(cor_path.c_str());
	}
	fin2.close();
	char c_name[100] = { 0 };
	strcpy(c_name,ID.get__name());
	download_file(c_name, "class_0", c_path, "NumToName", "1");

	std::fstream fp2(cor_path);
	i = 1;
	while (std::getline(fp2, line))
	{
		std::istringstream sss(line);
		std::string field;
		int flag = 0,i = 0;
		while (std::getline(sss, field, ',')) {
			if (flag == 0)
			{
				for (; i < course.size(); i++)
				{
					if (course[i].getName() == field)
					{
						flag = 1;
						break;
					}
				}
			}
			else
			{
				course[i].setId(field);
			}
		}
	}
	fp2.close();

	for (int i = 1; i < 26; i++)
	{
		if (schedule[i].size() != 0)
			courseButton[i]->setText(schedule[i].c_str());
		connect(courseButton[i], SIGNAL(clicked()), this, SLOT(gotocourse()));
	}
}

void Notebook::gotocourse() 
{
	std::string name = QObject::sender()->objectName().toStdString();
	int pos = name.find('_');
	int co = atoi(name.substr(pos+1, name.size()).c_str());
	if (schedule[co].size() != 0)
	{
		int i = 0;
		for (; i < course.size(); i++)
			if (course[i].getName() == schedule[co])
				break;
		//接口进入下一个界面
		view = new Notelist(course[i]);//将类指针实例化
		view->show();
	}
}

void Notebook::addcourse() 
{
	std::string obj = obj_path;
	add = new AddCourse(schedule,obj, this);
	add->show();
	if (add->exec() == QDialog::Accepted)
	{
		if (add->corr == nullptr)
			return;
		//设置数字
		int num[26] = { 0 },i,flag=0;
		for (i = 0; i < course.size(); i++)
		{
			if (course[i].getName() == add->corr->getName())
				flag = 1;
			num[stoi(course[i].getId())] = 1;
		}
		if (flag == 0)
		{
			for (i = 1; i < 25; i++)
				if (num[i] == 0)
					break;
			add->corr->setId(std::to_string(i));
			course.push_back(*add->corr);
		}

		for (int i = 1; i <= 25; i++)
		{
			schedule[i] = add->schedule[i];
			courseButton[i]->setText(schedule[i].c_str());
		}
		bool acc = access((*add->corr).getAdress().c_str(), 0);
		if (acc != 0)
			mkdir((*add->corr).getAdress().c_str());

		std::string sch_path = obj_path + "\\" + "Schedule.csv";
		std::ofstream outfile;
		outfile.open(sch_path.c_str(), std::ios::out);
		for (int i = 1; i <= 25; i++)
			outfile << schedule[i] << ",";
		outfile.close();
		char s_path[100] = { 0 };
		sch_path.copy(s_path, sch_path.size(), 0);
		delete_file(ID.get__name(), "class_0", "0");
		upload_file(ID.get__name(), "class_0", s_path, "Schedule", "0");

		std::string cor_path = obj_path + "\\" + "NumToName.csv";
		std::ofstream outfile2;
		outfile2.open(cor_path.c_str(), std::ios::out);
		for (int i = 0; i < course.size(); i++)
			outfile2 << course[i].getName() << "," << course[i].getId() << "," << "\n";
		outfile2.close();
		char c_path[100] = { 0 };
		cor_path.copy(c_path, cor_path.size(), 0);
		delete_file(ID.get__name(), "class_0", "1");
		upload_file(ID.get__name(), "class_0", c_path, "NumToName", "1");
				//建库
		delete add;
	}
}
void Notebook::deletecourse()
{
	bool ok;
	QStringList items;//条目
	for (int i = 0; i < course.size(); i++)
		items << course[i].getName().c_str();
	QString item = QInputDialog::getItem(this, "Delete", "please choose one to delete", items, 0, true, &ok);
	std::string ite = item.toStdString();
	std::string num = "0";
	for (int i=0;i<course.size();i++)
	{
		if (course[i].getName()==ite)
		{
			num = course[i].getId();
			rmdir(course[i].getAdress().c_str());
			course.erase(course.begin() + i);
			break;
		}
	}
	std::string cla = "class_" + num;
	delete_table_file(ID.get__name(), (char*)cla.c_str());

	std::string cor_path = obj_path + "\\" + "NumToName.csv";
	std::ifstream fin2(cor_path);
	if (fin2)
	{
		remove(cor_path.c_str());
	}
	std::ofstream outfile2;
	outfile2.open(cor_path.c_str(), std::ios::out);
	for (int i = 0; i < course.size(); i++)
		outfile2 << course[i].getName() << "," << course[i].getId() << "," << "\n";
	char c_path[100];
	cor_path.copy(c_path, cor_path.size(), 0);
	delete_file(ID.get__name(), "class_0", "1");
	upload_file(ID.get__name(), "class_0", c_path, "NumToName", "1");

	for (int i = 1; i < 26; i++)
		if (schedule[i] == ite)
		{
			schedule[i].clear();
			courseButton[i]->setText("");
		}

	std::string sch_path = obj_path + "\\" + "Schedule.csv";
	std::ifstream fin(sch_path);
	if (fin)
	{
		remove(sch_path.c_str());
	}
	std::ofstream outfile;
	outfile.open(sch_path.c_str(), std::ios::out);
	for (int i = 1; i <= 25; i++)
		outfile << schedule[i] << ",";
	char s_path[100];
	sch_path.copy(s_path, sch_path.size(), 0);
	delete_file(ID.get__name(), "class_0", "0");
	upload_file(ID.get__name(), "class_0", s_path, "Schedule", "0");
}
void Notebook::synchronize() 
{
}
