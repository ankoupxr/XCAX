#pragma once

#include <TDocStd_Document.hxx>


class Document;
DEFINE_STANDARD_HANDLE(Document, TDocStd_Document)
using DocPtr = Handle(Document);

class  Document : public TDocStd_Document
{
public:

	
	TDF_Label RootLabel() const;
	TDF_Label EntityLable() const;


private:

};



