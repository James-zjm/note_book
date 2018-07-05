#include "Login.h"

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.lineEdit_2->setEchoMode(QLineEdit::Password);
}

void Login::on_check()
{
	isvalid = use_user(ui.lineEdit->text().toStdString().c_str(), ui.lineEdit_2->text().toStdString().c_str());
	if (isvalid == NULL)
		return;
	if (*isvalid == '1')
	{
		ID.setName(ui.lineEdit->text().toStdString());
		ID.setPassword(ui.lineEdit_2->text().toStdString());
		ID.setAuthority(1);
		this->accept();
	}
	if (*isvalid == '2')
	{
		ID.setName(ui.lineEdit->text().toStdString());
		ID.setPassword(ui.lineEdit_2->text().toStdString());
		ID.setAuthority(2);
		this->accept();
	}
}
void Login::on_new() 
{
	bool ok;
	QString admin = QInputDialog::getText(this, tr("Account"), tr("please print account"), QLineEdit::Normal, tr("admin"), &ok);
	if (ok == true)
	{
		bool ok2;
		QString pass = QInputDialog::getText(this, tr("Password"), tr("please print password"), QLineEdit::Normal, tr("123456"), &ok2);
		if (ok2 == true)
		{
			int isok=add_user((admin.toStdString()).c_str(), (pass.toStdString()).c_str(), "1");
			if (isok == 1)
			{
				QMessageBox::about(this, ("Registration"), "Success!");
				std::ofstream myfile; //创建Schedule
				myfile.open("Schedule.csv"); //创建文件  
				Identity iii;
				iii.setName(admin.toStdString());
				upload_file(iii.get__name(), "class_0", "Schedule.csv", "Schedule", "0");
				std::ofstream mylist;
				mylist.open("NumToName.csv");
				upload_file(iii.get__name(), "class_0", "NumToName.csv", "NumToName", "1");
			}
			else
				QMessageBox::about(this, ("Registration"), "False!");
		}
	}

}
Login::~Login()
{
}
