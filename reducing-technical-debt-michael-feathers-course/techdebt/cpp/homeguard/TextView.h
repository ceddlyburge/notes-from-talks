
#pragma once

#include "HomeguardView.h"

class TextView : public HomeguardView
{
public:
	virtual void showMessage(const std::string& message);
};