#pragma once

#include <TDocStd_Document.hxx>

class  Document : public TDocStd_Document
{
public:
	
	TDF_Label RootLabel() const;
	TDF_Label EntityLable() const;

	TreeNodeId entityTreeNodeId(int index) const;
	DocumentTreeNode entityTreeNode(int index) const;
private:
	 
	std::
};



