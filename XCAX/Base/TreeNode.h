#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>
#include <Document.h>
#include <TDF_Tool.hxx>


using TreeNodeId = uint32_t;


class Tree
{
public:
	Tree();

	TreeNodeId GetRootNode() const;

	std::vector<TreeNodeId> NodeChilds(TreeNodeId id) const;

	TreeNodeId AppendChild(TreeNodeId parentId, TDF_Label label);
	//void RemoveRoot(TreeNodeId id);

	//~Tree();

private:
	struct TreeNode 
	{
		TreeNodeId Id;
		TreeNodeId ParentId;
		TDF_Label Name;
		bool IsDeleted;
	};
	TreeNodeId m_rootId = 0;
	TreeNodeId m_currentId = 0;
	std::vector<TreeNode> m_treeNodeArray;
	std::vector<TreeNodeId> m_treeNodeIdArray;
};


//class DocumentTreeNode
//{
//public:
//	DocumentTreeNode() = default;
//	DocumentTreeNode(const DocPtr& docPtr,TreeNodeId nodeId);
//
//	bool IsValid() const;
//	TDF_Label Label() const;
//	//bool IsEntity() const;
//	//bool IsLeaf() const;
//
//	//const DocPtr& GetDocument() const;
//	//TreeNodeId Id() const;
//	static const DocumentTreeNode& Null();
//	//bool operator==(const DocumentTreeNode& other) const;
//
//private:
//	DocPtr m_doc;
//	TreeNodeId m_id = 0;
//};
