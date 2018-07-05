#include "Notebook.h"
#include <QtWidgets/QApplication>
#include "Login.h"
#include "Identity.h"

Identity ID;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Login dlg;                        // �����Լ��½�����Ķ���dlg
	int flag=connect_database();
	dlg.show();
	if (dlg.exec() == QDialog::Accepted) // ����Accepted����ֵ�жϰ�ť�Ƿ񱻰���
	{
		Notebook w;
		w.show();                      // ��������£���ʾ������
		return a.exec();               // ����һֱִ�У�ֱ�������ڹر�
	}
	else 
		return 0;            //���û�����£��򲻻���������ڣ����������������
}
