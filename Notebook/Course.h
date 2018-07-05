#pragma once

#include<string>
#include <io.h>
#include <direct.h>

class Course
{
public:
	Course(std::string &a, std::string &obj);
	~Course();
	inline void setId(std::string &ii) {
		id = ii;
	}
	inline std::string getName() {
		return name;
	}
	inline std::string getAdress() {
		return adress;
	}
	void setAdress(std::string asd)
	{
		adress = asd;
	}
	inline std::string getId()
	{
		return id;
	}
private:
	std::string name;
	std::string adress;
	std::string id;
};

