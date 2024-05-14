#pragma once

#include "napr.h"
#include "adres.h"


class Univer
{
	private:
		
		std::string univer_name;
		Adres adres;
		std::string info;
		int count_napr;
		Napr* napr;

	public:

		Univer();
		Univer(int n);
		//~Univer();

		friend std::ostream& operator<<(std::ostream& out, const Univer& u)
		{
			out << "Название - " << u.univer_name << std::endl;
			out << "Описание -  " << u.info << std::endl;
			out << "Количество направлений - " << u.count_napr << std::endl;
			out << "Адрес - " << u.adres <<std::endl;
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Univer& u);

		const Univer& operator= (const Univer&);

		std::string get_univer_name() const
		{
			return this->univer_name;
		}
		
		Adres get_adr() const
		{
			return adres;
		}

		std::string get_univer_info(const Univer& u) const
		{
			return u.info;
		}

		int get_count_napr() const
		{
			return count_napr;
		}

		Napr get_napr(int idx) const
		{
			return napr[idx];
		}

		void set_count_napr(int k)
		{
			count_napr = k;
		}

		void make_naprs(int k)
		{
			this->count_napr = k;
			this->napr = new Napr[k];
			int i = 0;
		}

		void set_name_univ(const std::string name)
		{
			this->univer_name = name;
		}

		void set_naprs(int idx, Napr n)
		{
			this->napr[idx] = n;
		}

		void list_napr();

		void copy_univ(const int idx_napr_to_copy, const int idx_napr_from_copy,
			const int idx_edform_to_copy, const int idx_edform_from_copy, const Univer& univer);
		

		void min_ball();

};