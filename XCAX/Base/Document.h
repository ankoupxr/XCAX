#pragma once

#include <TDocStd_Document.hxx>
#include <TreeNode.h>
#include <filesystem>
#include <Ptr.h>
#include <mutex>

class  Document : public TDocStd_Document
{
public:
	Document(const AppPtr& app);
	~Document();

	int Identify() const { return m_identify; };

	enum class FormatType {Binary,Xml};//�ı���ʽ:�����ơ�Xml

	////�ļ�·��
	//const std::filesystem::path& FilePath();
	//void SetFilePath(const std::filesystem::path& filePath);

	//�ĵ�����
	const std::string& Name() const;
	void SetName(std::string name);

	//TDF_Label RootLabel() const;
	//TDF_Label EntityLabel() const;

	////bool IsEntity(TreeNodeId nodeId);
	//int EntityCount() const;

	//Tree
	//TreeNodeId EntityTreeNodeId(int index) const;
	
	static const char* ConvertToFormat(Document::FormatType format);

	void SetIdentify(int identify) { m_identify = identify; };


private:

	AppPtr m_app;
	int m_identify;
	std::string m_name;
	std::filesystem::path m_filePath;
	//Tree<TDF_Label> m_modelTree;

};



