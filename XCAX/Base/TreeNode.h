//#pragma once
//#include <algorithm>
//#include <cstdint>
//#include <vector>
//#include <Document.h>
//
//
//using TreeNodeId = uint32_t;
//
//
//template<typename T> class Tree
//{
//public:
//	Tree();
//
//	TreeNodeId NodeRoot(TreeNodeId id) const;
//
//	TreeNodeId NodeParent(TreeNodeId id) const;
//
//	std::vector<TreeNodeId> NodeChilds(TreeNodeId id) const;
//
//	const T& NodeData(TreeNodeId id) const;
//
//	TreeNodeId AppendChild(TreeNodeId parentId, T&& data);
//	void RemoveRoot(TreeNodeId id);
//
//	~Tree();
//
//private:
//	struct TreeNode 
//	{
//		TreeNodeId PreviousId;
//		TreeNodeId NextId;
//		TreeNodeId ParentId;
//		T data;
//		bool IsDeleted;
//	};
//
//	std::vector<TreeNode> m_treeNodeArray;
//	std::vector<TreeNodeId> m_treeNodeIdArray;
//};
//
//
//class DocumentTreeNode
//{
//public:
//	DocumentTreeNode() = default;
//	DocumentTreeNode(const DocPtr& docPtr,TreeNodeId nodeId);
//
//	bool IsValid() const;
//	TDF_Label Label() const;
//	bool IsEntity() const;
//	bool IsLeaf() const;
//
//	const DocPtr& GetDocument() const;
//	TreeNodeId Id() const;
//	static const DocumentTreeNode& Null();
//	bool operator==(const DocumentTreeNode& other) const;
//
//private:
//	DocPtr m_doc;
//	TreeNodeId m_id = 0;
//};
