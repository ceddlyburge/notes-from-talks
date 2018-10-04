
#pragma once

#include <string>
#include <vector>



class AddEmployeeCommand
{
public:
					AddEmployeeCommand
						(const std::string& name, 
						 const std::string& address,
						 const std::string& city,
						 const std::string& state,
						 const std::string& yearlySalary);

	void			write(std::vector<unsigned char>& buffer);

private:

	int			getSize();
	void		writeBytes(std::vector<unsigned char>& buffer, unsigned char *source, int length);
	void		writeByte(std::vector<unsigned char>& buffer, unsigned char source);
	
	std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string yearlySalary;	
	static const unsigned char header [];
	static const unsigned char commandChar [];
	static const unsigned char footer [];
	static const int SIZE_LENGTH;
	static const int CMD_BYTE_LENGTH;


};