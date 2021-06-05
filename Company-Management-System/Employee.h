#pragma once
#include "cstring"
#include "Vector.cpp"
#include "Materials.h"
#include <fstream>

class Employee {
private:
	char* firstName;
	char* lastName;
	int rank;
	char* position;
	double salary;

	void copy(const Employee&);
	void erase();
public:
	Employee();
	Employee(const char*, const char*, int, const char*, double);
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	~Employee();

	bool operator==(const Employee&) const;
	bool operator!=(const Employee&) const;

	void setFirstName(const char*);
	void setLastName(const char*);
	void setRank(int);
	void setPosition(const char*);
	void setSalary(double);

	int getRank() const;
	double getSalary() const;

	void hireEmployee(Vector<Employee>&, const Employee&);
	void dismissEmployee(Vector<Employee>&, const Employee&);
	void changeSalary(Vector<Employee>&, Employee&, size_t, double);

	void uploadMaterials(Vector<Materials>&, const char*, const char*);
	void openMaterials(Vector<Materials>&);
	void modifyMaterials(Vector<Materials>&, const char*, const char*);
	void downloadMaterials(Vector<Materials>&);

	friend std::ostream& operator<<(std::ostream& out, const Employee& employee) {
		out << employee.firstName << " ";
		out << employee.lastName << " ";
		out << employee.rank << " ";
		out << employee.position << " ";
		out << employee.salary << "\n";
		return out;
	}
};
