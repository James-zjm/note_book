#pragma once

#include <string>
//#include<mysql.h>
class Identity
{
public:
	Identity() :authority(0) {};
	~Identity();
	inline std::string getName() {
		return name;
	}
	void setName(std::string &a);

	void setPassword(std::string &b);
	inline std::string getPassword() {
		return password;
	}

	void setAuthority(int a)
	{
		authority = a;
	}
	inline int getAuthority() {
		return authority;
	}
	inline char* get__name()
	{
		return _name;
	}
private:
    std::string name, password;
	char* _name;
	int authority;
};

