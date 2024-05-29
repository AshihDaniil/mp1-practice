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
		if (EdFoIn.form_id == 1)
		{
			out << "Форма обучения - Очная" << std::endl;
		}
		else if (EdFoIn.form_id == 2)
		{
			out << "Форма обучения - Заочная" << std::endl;
		}
		else
		{
			out << "Форма обучения - Вечерняя" << std::endl;
		}
		out << "Проходной балл - " << EdFoIn.score << std::endl;
		out << "Стоимость договорного обучения - " << EdFoIn.cost ;
		return out;
	}

	void set_form_id(const std::string& name);

	int get_form_id() const { return form_id; }

	int get_score() const { return score; }

};