#pragma once

#include "napr.h"
#include "adres.h"


class Univer
{
	private:
		
		Adres adres;
		std::string info;
		int count_napr;
		std::string univer_name;
		Napr* napr;

	public:
		friend std::ostream& operator<<(std::ostream& out, const Univer& u)
		{
			out << "Название: " << u.univer_name << std::endl;
			out << "Описание: " << u.info << std::endl;
			out << "Количество направлений: " << u.count_napr << std::endl;
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Univer& u);

		std::string get_univer_name(Univer& u)
		{
			return u.univer_name;
		}
		
		Adres get_adr(Univer& u)
		{
			return u.adres;
		}

};