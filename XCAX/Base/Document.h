#pragma once

#include <TDocStd_Document.hxx>
#include <TreeNode.h>
#include <filesystem>
#include <Ptr.h>

class  Document : public TDocStd_Document
{
public:
	int Identify() const { return m_identify; };

	enum class FormatType {Binary,Xml};//文本格式:二进制、Xml

	//文件路径
	const std::filesystem::path& FilePath();
	void SetFilePath(const std::filesystem::path& filePath);

	//文档名称
	const std::string& Name();
	void SetName(std::string name);

	TDF_Label RootLabel() const;
	TDF_Label EntityLabel() const;

	bool IsEntity(TreeNodeId nodeId);
	int EntityCount() const;

	//Tree
	TreeNodeId EntityTreeNodeId(int index) const;
	
	static const char* ConvertToFormat(Document::FormatType format);

private:
	int m_identify;
	std::string m_name;
	std::filesystem::path m_filePath;
	Tree<TDF_Label> m_modelTree;
};



