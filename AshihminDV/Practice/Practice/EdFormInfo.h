#pragma once
#include "edForm.h"

#include <string>
#include <iostream>
#include <fstream>

class EdFormInfo
{
private:
	EducationalForm form_id;
	int score;
	int cost;

public:
	friend std::ifstream& operator>>(std::ifstream& in, EdFormInfo& EdFormInfo)
	{
		in >> EdFormInfo.score;
		std::string trash;
		getline(in, trash);
		in >> EdFormInfo.cost;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const EdFormInfo& EdFoIn)
	{
		out << std::to_string(EdFoIn.form_id) << std::endl;
		out << EdFoIn.score << std::endl;
		out << EdFoIn.cost << std::endl;
		return out;
	}

	void set_form_id(std::string name)
	{
		if (name == "OCHNAYA")
		{
			this->form_id = EducationalForm::OCHNAYA;
		}
		if (name == "ZAOCHNAY")
		{
			this->form_id = EducationalForm::ZAOCHNAY;
		}
		if (name == "VECHERNYA")
		{
			this->form_id = EducationalForm::VECHERNYA;
		}
	}
};