#pragma once

#include <string>
#include <bitset>
#include <unordered_map>

class DocumentObject
{
public:
	std::string Label;

	DocumentObject();
	~DocumentObject();

	const char* GetDocumentObjectName() const;
	long GetObjectID() const;


protected:
	const std::string* pcNameInDocument{ nullptr };


private:

};
