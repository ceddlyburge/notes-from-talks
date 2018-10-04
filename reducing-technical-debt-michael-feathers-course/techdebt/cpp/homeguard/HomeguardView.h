
#pragma once

#include <string>


class HomeguardView
{
public:
	virtual void showMessage(const std::string& message) = 0;
};