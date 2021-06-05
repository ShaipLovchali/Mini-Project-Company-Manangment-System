#pragma once
 #include "String.h"

class Materials {
private:
	String access;
	String materialsToUpload;
public:
	Materials();
	Materials(const String&, const String&);

	String getMaterials() const;
	String getAccess() const;

	bool operator==(const Materials&) const;
	bool operator!=(const Materials&) const;

	friend std::ostream& operator<<(std::ostream& out, const Materials& materials) {
		out << materials.materialsToUpload;
		return out;
	};
};
