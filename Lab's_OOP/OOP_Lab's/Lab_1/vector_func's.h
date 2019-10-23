#pragma once
#include "pch.h"

namespace math_subjects {

	class vector
	{
	private:
		double x;
		double y;
		double z;
		static int i;
		int id;
	public:
		vector();
		vector(double x, double y, double z);
		vector(const vector &other);
		void identification();
		void set_x(double x);
		void set_y(double y);
		void set_z(double z);
		double get_x() const;
		double get_y() const;
		double get_z() const;
		void print() const;
		double modul() const;
		void norm();
		void multip(double num);
		~vector();
	};
	vector sum_vec(const vector & a, const vector & b);
	vector dif_vec(const vector &a, const vector &b);
	vector mult_vec(const vector &a, const vector &b);
	double scal_mult(const vector &a, const vector &b);
	double cosin(const vector &a, const vector &b);
	double sinus(const vector &a, const vector &b);
	double angle_between(const vector &a, const vector &b);
}