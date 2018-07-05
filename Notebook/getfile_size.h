#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#ifndef _getfile_size_H_
#define _getfile_size_H_
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
#endif // !_getfile_size_H_
