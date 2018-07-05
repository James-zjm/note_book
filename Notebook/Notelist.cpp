#include "Notelist.h"


//获取特定格式的文件名
void GetAllFormatFiles(std::string path, std::vector<std::string>& files, std::string format)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
					GetAllFormatFiles(p.assign(path).append("\\").append(fileinfo.name), files, format);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}


Notelist::Notelist(Course input,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	course = new Course(input.getName(),input.getAdress());
	course->setAdress(input.getAdress());
	std::string format = ".rtf";
	std::vector<std::string> notes;
	std::vector<std::string> notes_name;
	GetAllFormatFiles(course->getAdress(), notes/*路径*/, format);
	std::string cla = "class_" + course->getId();
	char **p = show_file_name(ID.get__name(), (char*)cla.c_str()); 
	if (p != nullptr)
	{
		char *tem = p[0];
		int len = 0;
		while (tem) {
			for (int i = 0; i < notes_name.size(); i++)
			{
				if (tem != notes_name[i].c_str())
				{
					std::string ppath = course->getAdress() + "//" + tem;
					char* iddi = show_file_id(ID.get__name(), (char*)cla.c_str(), tem);
					download_file(ID.get__name(), (char*)cla.c_str(), (char*)ppath.c_str(), tem, iddi);
					Note *abx;
					abx = new Note(tem, ppath);
					abx->id = iddi;
					list.push_back(abx);
				}
				else
				{
					Note *abx;
					char* iddi = show_file_id(ID.get__name(), (char*)cla.c_str(), tem);
					abx = new Note(notes_name[i], notes[i]);
					abx->id = iddi;
					list.push_back(abx);
				}
			}
			len++;
			tem = p[len];
		}
	}
	ui.scrollAreaWidgetContents->setMinimumHeight(list.size() * 40);
	ui.scrollAreaWidgetContents->resize(list.size() * 40, 360);
	for (int i = 0; i < list.size(); i++)//仔细想想
	{
		list[i]->setObjectName(list[i]->name.c_str());
		ui.verticalLayout_2->addWidget(list[i]);
		connect(list[i]->deleteButton, SIGNAL(clicked()), this, SLOT(delete_note()));
	}
}

void Notelist::delete_note() {
	std::string na = QObject::sender()->objectName().toStdString();
	std::string cla = "class_" + course->getId();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->name == na)
		{
			ui.verticalLayout_2->removeWidget(list[i]);
			delete_file(ID.get__name(), (char*)cla.c_str(), (char*)list[i]->id.c_str());
			std::ifstream ffi(list[i]->adress);
			if (ffi)
			{
				remove(list[i]->adress.c_str());
			}
			delete list[i];
			list.erase(list.begin() + i);
			break;
		}
	}
}

void Notelist::new_note()
{
	std::string com = "echo off >> ";
	bool ok;
	QString namee = QInputDialog::getText(this, tr("New note"), tr("please print note name"), QLineEdit::Normal, tr("note"), &ok);
	if (ok == true)
	{
		mkdir(course->getAdress().c_str());
		std::string adress = course->getAdress() + "\\" + namee.toStdString() + ".rtf";
		com += adress;
		std::system(com.c_str());
		std::system(adress.c_str());
		Note* in;
		in = new Note(namee.toStdString(), com);
		bool num[200] = { 0 };
		int i;
		for (i = 0; i < list.size(); i++)
			num[stoi(list[i]->id)] = 1;
		for (i = 0; i < 200; i++)
			if (num[i] == 0)
				break;
		in->id = i;
		list.push_back(in);
		int pos = list.size()-1;
		list[pos]->setObjectName(list[pos]->name.c_str());
		ui.scrollAreaWidgetContents->setMinimumHeight(list.size() * 40);
		ui.scrollAreaWidgetContents->resize(list.size() * 40, 360);
		ui.verticalLayout_2->addWidget(list[pos]);
		connect(list[pos]->deleteButton, SIGNAL(clicked()), this, SLOT(delete_note()));
	}
}

void Notelist::search_note() 
{
	std::string sen = ui.lineEdit->text().toStdString();
	std::string a = sen;
	a = "*" + a + "*";
	std::regex repPattern(a, std::regex_constants::extended);
	std::match_results<std::string::const_iterator> rerResult;
	for (int i = 0; i < list.size(); i++)
	{
		bool bValid = std::regex_match(list[i]->name, rerResult, repPattern);
		if (bValid)
		{
			Note *fm = ui.scrollArea->findChild<Note*>(list[i]->name.c_str());
			if(fm==nullptr)
				ui.verticalLayout_2->addWidget(list[i]);
		}
		if (!bValid)
		{
			Note *fm = ui.scrollArea->findChild<Note*>(list[i]->name.c_str());
			if(fm != nullptr)
				ui.verticalLayout_2->removeWidget(list[i]);
		}
	}
}



void Notelist::closeEvent(QCloseEvent *event)
{
	std::string format = ".rtf";
	std::vector<std::string> notes;
	std::vector<std::string> notes_name;
	GetAllFormatFiles(course->getAdress(), notes/*路径*//*, notes_name*//*名称*/, format);
	std::string cla = "class_" + course->getId();
	char **p = show_file_name(ID.get__name(), (char*)cla.c_str());
	for (int i = 0; i < notes_name.size(); i++)
	{
		char *tem = p[0];
		int len = 0;
		while (tem) {
			if (notes_name[i].c_str() != tem)
			{
				int i = 0;
				for (i = 0; i < list.size(); i++)
					if (list[i]->name == notes_name[i])
						upload_file(ID.get__name(), (char*)cla.c_str(), (char*)notes[i].c_str(), (char*)notes_name[i].c_str(), (char*)list[i]->id.c_str());
			}
			len++;
			tem = p[len];
		}

	}

	event->accept(); // 接受退出信号，程序退出
}
Notelist::~Notelist()
{
}

void Note::open_note()
{
	std::system(adress.c_str());
}

