#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Employee.h"

TEST_CASE("Test hiring an Employee") {
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);
	Employee e3("Mitko", "Pink", 3, "CIO", 5000);
	Employee e4("Shaip", "Lovchali", 1, "junior-developer", 900);

	Vector<Employee> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);

	e1.hireEmployee(employees, e4);

	CHECK(employees.getCapacity() == 4);
	CHECK(employees[3] == e4);

	Employee e5("Nasko", "Grey", 4, "senior-developer", 4000);
	e3.hireEmployee(employees, e5);

	CHECK(employees.getCapacity() == 4);
	CHECK(employees[3] == e4);
}

TEST_CASE("Test dismissing an Employee") {
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);
	Employee e3("Mitko", "Pink", 3, "CIO", 5000);

	Vector<Employee> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);

	e2.dismissEmployee(employees, e1);

	CHECK(employees.getCapacity() == 2);
	CHECK(employees[0] == e2);

	e3.dismissEmployee(employees, e2);

	CHECK(employees.getCapacity() == 2);
	CHECK(employees[0] == e2);
}

TEST_CASE("Test changing the salary of an Employee") {
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);
	Employee e3("Mitko", "Pink", 3, "CIO", 5000);

	Vector<Employee> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);

	e2.changeSalary(employees, e1, 0, 1200);

	CHECK(employees[0].getSalary() == 1200);
	CHECK(e1.getSalary() == 1200);

	e1.changeSalary(employees, e2, 1, 6900);

	CHECK(employees[1].getSalary() == 6000);
	CHECK(e2.getSalary() == 6000);
}

TEST_CASE("Test uploading materials") {
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);

	Vector<Materials> materials;
	e1.uploadMaterials(materials, "public", "My name is John");
	e2.uploadMaterials(materials, "John", "My name is Sasho");

	CHECK(materials[0].getAccess() == "public");
	CHECK(materials[0].getMaterials() == "My name is John");

	CHECK(materials[1].getAccess() == "John");
	CHECK(materials[1].getMaterials() == "My name is Sasho");
}

TEST_CASE("Test modifying materials") {
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);

	Vector<Materials> materials;
	e1.uploadMaterials(materials, "public", "My name is John and I'm a developer at the firm");
	e2.uploadMaterials(materials, "John", "My name is Sasho and I'm the CEO of the company");
	
	e1.modifyMaterials(materials, "name", "nickname");

	CHECK(materials[0].getMaterials() == "My nickname is John and I'm a developer at the firm");
	CHECK(materials[1].getMaterials() == "My nickname is Sasho and I'm the CEO of the company");

	e2.modifyMaterials(materials, "Hello", "Hi");
	CHECK(materials[0].getMaterials() == "My nickname is John and I'm a developer at the firm");
	CHECK(materials[1].getMaterials() == "My nickname is Sasho and I'm the CEO of the company");
}

int main()
{
	doctest::Context().run();
	Employee e1("John", "Black", 2, "developer", 1000);
	Employee e2("Sasho", "White", 5, "CEO", 6000);

	Vector<Materials> materials;
	e1.uploadMaterials(materials, "public", "My name is John and I'm a developer at the firm");
	e2.uploadMaterials(materials, "John", "My name is Sasho and I'm the CEO of the company");

	e1.openMaterials(materials);
	e1.downloadMaterials(materials);
}
