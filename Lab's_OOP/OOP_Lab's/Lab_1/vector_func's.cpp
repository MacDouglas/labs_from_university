#include "pch.h"
#include "vector_func's.h"

using namespace std;

int x;
namespace math_subjects {

	int vector::i = 0;
	int x;
	vector::vector():vector(0,0,0){}
	vector::vector(double x,double y, double z){
		this->x = x;
		vector::y = y;
		this->z = z;
		//laboratory::x = x;
		::x = x;
		identification();
	}
	vector::vector(const vector &other):vector(other.x,other.y,other.z){}
	void vector::identification() {
		id = ++i;
		cout << "Конструктор вектора - " << id << endl;
	}
	void vector::set_x(double x) {
		this->x = x;
	}
	void vector::set_y(double y) {
		this->y = y;
	}
	void vector::set_z(double z) {
		this->z = z;
	}
	double vector::get_x() const {
		return x;
	}
	double vector::get_y() const {
		return y;
	}
	double vector::get_z() const {
		return z;
	}
	void vector::print() const {
		cout << "x= " << x << "\ty= " << y << "\tz= " << z << endl;
	}
	double vector::modul() const {
		double m = sqrt((x*x) + (y * y) + (z * z));
		return m;
	}
	void vector::norm() {
		double m = modul();
		x /= m;
		y /= m;
		z /= m;
	}
	void vector::multip(double num) {
		x *= num;
		y *= num;
		z *= num;
	}
	vector::~vector() {
		cout << "Деструктор вектора - " << id << endl;
	}
	
	vector sum_vec(const vector & a, const vector & b)
	{
		return vector(a.get_x()+b.get_x(), a.get_y()+b.get_y(), a.get_z()+b.get_z());
	}
	
	vector dif_vec(const vector &a, const vector &b){
		return vector(a.get_x()-b.get_x(), a.get_y()-b.get_y(),a.get_z()-b.get_z());
	}	

	vector mult_vec(const vector & a, const vector &b) {
		return vector(a.get_x()*b.get_z() - a.get_z()*b.get_y(), a.get_z()*b.get_x() - a.get_x()*b.get_z(), a.get_x()*b.get_y() - a.get_y()*b.get_x());
	}

	double scal_mult(const vector &a, const vector &b) {
		double s = a.get_x()*b.get_x() + a.get_y()*b.get_y() + a.get_z()*b.get_z();
		return s;
	}
	double cosin(const vector &a, const vector &b) {
		double co = scal_mult(a, b) / (a.modul()*b.modul());
		return co;
	}
	double sinus(const vector &a, const vector &b) {
		double si = mult_vec(a, b).modul() / (a.modul()*b.modul());
		return si;
	}
	double angle_between(const vector &a, const vector &b) {
		double ang = atan2(sinus(a,b),cosin(a, b));
		return ang;
	}
}
