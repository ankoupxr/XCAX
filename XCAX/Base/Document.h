#pragma once

#include <TDocStd_Document.hxx>
#include <TreeNode.h>

class Document;
DEFINE_STANDARD_HANDLE(Document, TDocStd_Document)
using DocPtr = Handle(Document);

class  Document : public TDocStd_Document
{
public:
	int Identify() const { return m_identify; };

	
	TDF_Label RootLabel() const;
	TDF_Label EntityLable() const;

	bool IsEntity(TreeNodeId nodeId);
	int EntityCount() const;

private:
	int m_identify;
};



