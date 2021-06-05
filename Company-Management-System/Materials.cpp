#include "Materials.h"

Materials::Materials(){}

Materials::Materials(const String& access, const String& materialsToUpload) : access(access), materialsToUpload(materialsToUpload){}

String Materials::getMaterials() const
{
	return this->materialsToUpload;
}

String Materials::getAccess() const
{
	return this->access;
}

bool Materials::operator==(const Materials& other) const
{
	return this->access == other.access && this->materialsToUpload == other.materialsToUpload;
}

bool Materials::operator!=(const Materials& other) const
{
	return !(*this == other);
}
