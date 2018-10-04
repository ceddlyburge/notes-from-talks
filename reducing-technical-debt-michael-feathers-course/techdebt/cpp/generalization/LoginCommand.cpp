

#include "LoginCommand.h"

const unsigned char LoginCommand::header [] = {(unsigned char)0xde, (unsigned char)0xad};
const unsigned char LoginCommand::commandChar [] = {0x01};
const unsigned char LoginCommand::footer [] = {(unsigned char)0xbe, (unsigned char)0xef};
const int LoginCommand::SIZE_LENGTH = 1;
const int LoginCommand::CMD_BYTE_LENGTH = 1;

LoginCommand::LoginCommand(const std::string name, const std::string password)
: userName(name), passwd(password)
{
}


void LoginCommand::writeBytes(std::vector<unsigned char>& buffer, unsigned char *source, int length)
{

	for (int n = 0; n < length; ++n) {
		buffer.push_back(source [n]);
	}
}


void LoginCommand::write(std::vector<unsigned char>& buffer)
{
	int bufferSize = getSize();


	writeBytes(buffer,(unsigned char*)&header[0],sizeof(header));
    writeByte(buffer,((unsigned char *)&bufferSize)[0]);
    writeBytes(buffer,(unsigned char *)&commandChar,sizeof(commandChar));
    writeBytes(buffer,(unsigned char *)userName.c_str(), userName.size());
    writeByte (buffer,0x00);
    writeBytes(buffer,(unsigned char *)passwd.c_str(),passwd.size());
    writeByte (buffer,0x00);
    writeBytes(buffer,(unsigned char *)footer,sizeof(footer));
}

void LoginCommand::writeByte(std::vector<unsigned char>& buffer, unsigned char source)
{
		buffer.push_back(source);

}


int LoginCommand::getSize() 
{
    return sizeof(header) +  SIZE_LENGTH +  CMD_BYTE_LENGTH + sizeof(footer) +
            userName.size() + 1 +
            passwd.size() + 1;
  
}