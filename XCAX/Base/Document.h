#pragma once

#include <TDocStd_Document.hxx>
#include <TreeNode.h>
#include <filesystem>

class Document;
DEFINE_STANDARD_HANDLE(Document, TDocStd_Document)
using DocPtr = Handle(Document);

class  Document : public TDocStd_Document
{
public:
	int Identify() const { return m_identify; };

	enum class FormatType {Binary,Xml};//�ı���ʽ:�����ơ�Xml

	//�ļ�·��
	const std::filesystem::path& FilePath();
	void SetFilePath(const std::filesystem::path& filePath);

	TDF_Label RootLabel() const;
	TDF_Label EntityLabel() const;

	bool IsEntity(TreeNodeId nodeId);
	int EntityCount() const;

	//Tree
	TreeNodeId EntityTreeNodeId(int index) const;
	

private:
	int m_identify;
	std::filesystem::path m_filePath;
};



