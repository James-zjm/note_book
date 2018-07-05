#include "Sql.h"
std::wstring Change_string_to_wstring(std::string str)
{
	if (str.length() == 0)
		return L"";

	std::wstring wstr;
	wstr.assign(str.begin(), str.end());
	return wstr;
}
int file_size(char *path)
{
	int size;
	std::string string_path = path;
	std::wstring wstring_path = Change_string_to_wstring(string_path);
	LPCWSTR File_pointer = wstring_path.c_str();
	HANDLE handle = CreateFile(File_pointer, FILE_READ_EA, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (handle != INVALID_HANDLE_VALUE)
	{
		size = GetFileSize(handle, NULL);
		CloseHandle(handle);
		return size;
	}
	return 0;
}
char *read_file(char *path,int size)
{
	FILE *file;
	file = fopen(path, "rb");
	char *buf = (char*)malloc(sizeof(char)*(size + 1));
	int n = std::fread(buf, 1, size, file);
	return buf;
}
int write_file(char *buf, char *path,int size)
{
	FILE *file;
	file = fopen(path, "wb");
	int p = fwrite(buf, 1, size, file);
	return 1;
}
int connect_database()
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char username[] = "root";
	char password[] = "123456";
	char database[] = "mysql";
	char *sql;
	if (mysql_init(&mysql_conn) != NULL)
	{
		if (mysql_real_connect(&mysql_conn, ip, username, password, database, MYSQL_PORT, NULL, 0) != NULL)
		{
			return 1;
		}
	}
	return 0;
}
int add_user(const char *username, const char *password, const char *level)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char database[] = "user";
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "create database ";
	sql_string += username;
	sql_string += ";";
	char *sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	sql_string = "create table ";
	sql_string += username;
	sql_string += "(password text,level text,id int);";
	sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	sql_string = "insert into ";
	sql_string += username;
	sql_string += "(password,level)value(";
	sql_string += password;
	sql_string += ",";
	sql_string += level;
	sql_string += ");";
	sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	sql_string = "use ";
	sql_string += username;
	sql_string += ";";
	sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	for (int i = 0; i < 80; i++)
	{
		sql_string = "create table class_";
		sql_string += std::to_string(i);
		sql_string += "(file longblob,file_name text,id int);";
		sql = (char*)malloc(sizeof(char)*(sql_string.length()));
		strcpy(sql, sql_string.c_str());
		int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
		if (flag != 0)
		{
			return 0;
		}
	}
	return 1;
}
char* use_user(const char *username, const char *password)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char database[] = "user";
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "select password from ";
	sql_string += username;
	sql_string += ";";
	char *sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	row = mysql_fetch_row(result);
	char *s = *row;
	for (int i = 0; i < strlen(password); i++)
	{
		if (s[i] != password[i])
		{
			return 0;
		}
	}
	sql_string = "select level from ";
	sql_string += username;
	sql_string += ";";
	sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	row = mysql_fetch_row(result);
	return *row;
}
int upload_file(char *database_name, char *table_name, char *path,char* filename,char*id)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	char *buf = read_file(path, file_size(path));
	int n = file_size(path);
	std::string sql_string = "insert into ";
	sql_string += table_name;
	sql_string += "(file_name,id,file)value(\'";
	sql_string += filename;
	sql_string += "\',";
	sql_string += id;
	sql_string += ",";
	char *sql_1 = (char*)malloc(sizeof(char)*(n)*2+256);
	strcpy(sql_1, sql_string.c_str());
	char* end = sql_1 + strlen(sql_1);
	*end ++= '\'';
	end += mysql_real_escape_string(&mysql_conn, end, buf, n);
	*end++ = '\'';
	*end++ = ')';
	int flag=mysql_real_query(&mysql_conn, sql_1, (unsigned int)(end-sql_1));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}
int download_file(char *database_name, char *table_name, char *path,char* filename,char* id)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "select file from ";
	sql_string += table_name;
	sql_string += " where id=";
	sql_string += id;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	FILE* fp;
	fp = fopen(path, "wb");
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		unsigned long *length = mysql_fetch_lengths(result);
		for (int i = 0; i<mysql_num_fields(result); i++)
		{
			fwrite(row[0], 1, length[0], fp);
		}
	}
	return 1;
}
char* show_file_name(char *database_name, char *table_name, char* id)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "select file_name from ";
	sql_string += table_name;
	sql_string += " where id=";
	sql_string += id;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	row = mysql_fetch_row(result);
	return *row;
}
char* show_file_id(char *database_name, char *table_name, char* file_name)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "select id from ";
	sql_string += table_name;
	sql_string += " where file_name=\'";
	sql_string += file_name;
	sql_string += "\';";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	row = mysql_fetch_row(result);
	return *row;
}
int create_public_class(char *class_id)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char database[] = "mysql";
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "create database ";
	sql_string += class_id;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}
int create_public_class_add_student(char *class_id, char *student)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char* database = class_id;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "create table ";
	sql_string += student;
	sql_string += "(file longblob,file_name text,id int);";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}
int delete_database(char *database_name)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char database[] = "mysql";
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "drop database ";
	sql_string += database_name;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}
int delete_table(char *database_name,char* table)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "drop table ";
	sql_string += table;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}

int delete_file(char *database_name, char *table_name, char* id)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "delete from ";
	sql_string += table_name;
	sql_string += " where id=";
	sql_string += id;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}

char** show_file_name(char *database_name, char *table_name)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "select file_name from ";
	sql_string += table_name;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	result = mysql_store_result(&mysql_conn);
	row = mysql_fetch_row(result);
	return row;
}

int delete_table_file(char *database_name, char* table)
{
	MYSQL mysql_conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char ip[] = "120.78.180.34";
	char root[] = "root";
	char pass[] = "123456";
	char *database = database_name;
	mysql_init(&mysql_conn);
	mysql_real_connect(&mysql_conn, ip, root, pass, database, MYSQL_PORT, NULL, 0);
	std::string sql_string = "drop table ";
	sql_string += table;
	sql_string += ";";
	char*sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	int flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	sql_string = "create table ";
	sql_string += table;
	sql_string += "(file longblob,file_name text,id int);";
	sql = (char*)malloc(sizeof(char)*(sql_string.length()));
	strcpy(sql, sql_string.c_str());
	flag = mysql_real_query(&mysql_conn, sql, (unsigned int)strlen(sql));
	if (flag != 0)
	{
		return 0;
	}
	return 1;
}
