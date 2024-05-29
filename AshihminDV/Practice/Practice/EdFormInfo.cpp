#include "EdFormInfo.h"

void EdFormInfo::set_form_id(const std::string& name)
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