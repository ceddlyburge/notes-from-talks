

#pragma once

#include <string>
#include <vector>

class LoginCommand
{
public:
	LoginCommand(const std::string name, const std::string password);

	void write(std::vector<unsigned char>& buffer);

private:

	int			getSize();
	void		writeBytes(std::vector<unsigned char>& buffer, unsigned char *source, int length);
	void		writeByte(std::vector<unsigned char>& buffer, unsigned char source);
	
	std::string userName;
	std::string passwd;
	static const unsigned char header [];
	static const unsigned char commandChar [];
	static const unsigned char footer [];
	static const int SIZE_LENGTH;
	static const int CMD_BYTE_LENGTH;


};