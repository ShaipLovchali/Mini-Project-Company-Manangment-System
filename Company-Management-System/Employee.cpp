#include "Employee.h"

void Employee::copy(const Employee& other)
{
	setFirstName(other.firstName);
	setLastName(other.lastName);
	setRank(other.rank);
	setPosition(other.position);
	setSalary(other.salary);
}

void Employee::erase()
{
	delete[] this->firstName;
	delete[] this->lastName;
	delete[] this->position;
}

Employee::Employee() : firstName(nullptr), lastName(nullptr), rank(-1), position(nullptr), salary(0) {}

Employee::Employee(const char* firstName, const char* lastName, int rank, const char* position, double salary)
{
	setFirstName(firstName);
	setLastName(lastName);
	setRank(rank);
	setPosition(position);
	setSalary(salary);
}

Employee::Employee(const Employee& other)
{
	copy(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Employee::~Employee()
{
	erase();
}

bool Employee::operator==(const Employee& other) const
{
	if (strcmp(firstName, other.firstName) == 0 && strcmp(lastName, other.lastName) == 0 && rank == other.rank &&
		strcmp(position, other.position) == 0 && salary == other.salary) {
		return true;
	}
	return false;
}

bool Employee::operator!=(const Employee& other) const
{
	return !(*this == other);
}

void Employee::setFirstName(const char* firstName)
{
	this->firstName = new char[strlen(firstName) + 1];
	for (size_t i = 0; firstName[i]; ++i)
	{
		this->firstName[i] = firstName[i];
	}
	this->firstName[strlen(firstName)] = '\0';
}

void Employee::setLastName(const char* lastName)
{
	this->lastName = new char[strlen(lastName) + 1];
	for (size_t i = 0; lastName[i]; ++i)
	{
		this->lastName[i] = lastName[i];
	}
	this->lastName[strlen(lastName)] = '\0';
}

void Employee::setRank(int rank)
{
	this->rank = rank;
}

void Employee::setPosition(const char* position)
{
	this->position = new char[strlen(position) + 1];
	for (size_t i = 0; position[i]; ++i)
	{
		this->position[i] = position[i];
	}
	this->position[strlen(position)] = '\0';
}

void Employee::setSalary(double salary)
{
	this->salary = salary;
}

int Employee::getRank() const
{
	return this->rank;
}

double Employee::getSalary() const
{
	return this->salary;
}

void Employee::hireEmployee(Vector<Employee>& employees, const Employee& newEmp)
{
	if (employees.isInVector(*this) && this->rank > newEmp.rank) {
		employees.push_back(newEmp);
	}
	else {
		std::cout << "Can not hire the new Employee" << std::endl;
	}
}

void Employee::dismissEmployee(Vector<Employee>& employees, const Employee& other)
{
	if (employees.isInVector(*this) && employees.isInVector(other) && this->rank > other.rank) {
		employees.pop_by_data(other);
	}
	else {
		std::cout << "Can not dismiss the other Employee" << std::endl;
	}
}

void Employee::changeSalary(Vector<Employee>& employees, Employee& other, size_t index, double newSalary)
{
	if (employees.isInVector(*this) && employees.isInVector(other) && this->rank > other.rank) {
		employees.pop_by_data(other);
		other.setSalary(newSalary);
		employees.push_by_index(other, index);
	}
	else {
		std::cout << "Can not change other Employee's salary" << std::endl;
	}
}

void Employee::uploadMaterials(Vector<Materials>& materials, const char* access, const char* input)
{
	std::cout << firstName << " " << lastName <<" is currently using the system." << std::endl;
	Materials m(access, input);
	materials.push_back(m);
}

void Employee::openMaterials(Vector<Materials>& materials)
{
	for (size_t i = 0; i < materials.getCapacity(); ++i)
	{
		if (materials[i].getAccess() == "public" || materials[i].getAccess().find(firstName) != -1) {
			std::cout << materials[i] << std::endl;
		}
	}
}

void Employee::modifyMaterials(Vector<Materials>& materials, const char* toReplace, const char* newContents)
{
	for (size_t i = 0; i < materials.getCapacity(); ++i)
	{
		if (materials[i].getAccess() == "public" || materials[i].getAccess().find(firstName) != -1) {
			String newMaterials;
			
			int startingIndex = materials[i].getMaterials().find(toReplace);
			if (startingIndex != -1) {
				for (size_t j = 0; j <= materials[i].getMaterials().getSize(); ++j)
				{
					if (j == startingIndex) {
						newMaterials += newContents;
						newMaterials.pushBack(' ');
						j += strlen(toReplace);
						continue;
					}
				
					newMaterials.pushBack(materials[i].getMaterials()[j]);
				}
				newMaterials.popBack();
				String access = materials[i].getAccess();
				materials.pop_by_data(materials[i]);
				Materials m(access, newMaterials);
				materials.push_by_index(m, i);
			}
		}
	}
}

void Employee::downloadMaterials(Vector<Materials>& materials)
{
	std::ofstream out("materials.txt");

	for (size_t i = 0; i < materials.getCapacity(); ++i)
	{
		if (materials[i].getAccess() == "public" || materials[i].getAccess().find(firstName) != -1) {
			out << materials[i] << "\n";
		}
	}
	out.close();
}

