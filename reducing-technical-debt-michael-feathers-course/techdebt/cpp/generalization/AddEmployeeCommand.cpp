
#include "AddEmployeeCommand.h"


const unsigned char AddEmployeeCommand::header [] = {(unsigned char)0xde, (unsigned char)0xad};
const unsigned char AddEmployeeCommand::commandChar [] = {0x02};
const unsigned char AddEmployeeCommand::footer [] = {(unsigned char)0xbe, (unsigned char)0xef};
const int AddEmployeeCommand::SIZE_LENGTH = 1;
const int AddEmployeeCommand::CMD_BYTE_LENGTH = 1;

AddEmployeeCommand::AddEmployeeCommand
						(const std::string& name, 
						 const std::string& address,
						 const std::string& city,
						 const std::string& state,
						 const std::string& yearlySalary)
						 : name(name), address(address),city(city),state(state),yearlySalary(yearlySalary)
{
}


void AddEmployeeCommand::writeBytes(std::vector<unsigned char>& buffer, unsigned char *source, int length)
{

	for (int n = 0; n < length; ++n) {
		buffer.push_back(source [n]);
	}
}


void AddEmployeeCommand::write(std::vector<unsigned char>& buffer)
{
	int bufferSize = getSize();


	writeBytes(buffer,(unsigned char*)&header[0],sizeof(header));
    writeByte(buffer,((unsigned char *)&bufferSize)[0]);
    writeBytes(buffer,(unsigned char *)&commandChar,sizeof(commandChar));

    writeBytes(buffer,(unsigned char *)name.c_str(), name.size());
    writeByte (buffer,0x00);

    writeBytes(buffer,(unsigned char *)address.c_str(), address.size());
    writeByte (buffer,0x00);

	writeBytes(buffer,(unsigned char *)city.c_str(), city.size());
    writeByte (buffer,0x00);

	writeBytes(buffer,(unsigned char *)state.c_str(), state.size());
    writeByte (buffer,0x00);

	writeBytes(buffer,(unsigned char *)yearlySalary.c_str(), yearlySalary.size());
    writeByte (buffer,0x00);

    writeBytes(buffer,(unsigned char *)footer,sizeof(footer));
}

void AddEmployeeCommand::writeByte(std::vector<unsigned char>& buffer, unsigned char source)
{
		buffer.push_back(source);

}


int AddEmployeeCommand::getSize() 
{
    return sizeof(header) +  SIZE_LENGTH +  CMD_BYTE_LENGTH + sizeof(footer) +
            name.size() + 1 +
            address.size() + 1 +
            city.size() + 1 +
            state.size() + 1 +
            yearlySalary.size() + 1;
  
}
