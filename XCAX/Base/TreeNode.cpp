#include <TreeNode.h>

///Tree
Tree::Tree() {}


std::vector<TreeNodeId> Tree::NodeChilds(TreeNodeId id) const
{
    return m_treeNodeIdArray;
}

TreeNodeId Tree::GetRootNode() const
{
    return m_rootId;
}

TreeNodeId Tree::AppendChild(TreeNodeId parentId, TDF_Label label)
{
    m_currentId++;
    TreeNode currentNode;
    TCollection_AsciiString asciiString;
    //TDF_Tool::Label(label, asciiString); 

    const char* charString = asciiString.ToCString(); // ½«TCollection_AsciiString×ª»»Îªconst char*
    currentNode.ParentId = parentId;
    currentNode.Id = m_currentId;
    m_treeNodeArray.push_back(currentNode);
    m_treeNodeIdArray.push_back(m_currentId);
    return m_currentId;
}

//DocumentTreeNode
//DocumentTreeNode::DocumentTreeNode(const DocPtr& docPtr, TreeNodeId nodeId)
//    : m_doc(docPtr), m_id(nodeId)
//{ }
//
//bool DocumentTreeNode::IsValid() const
//{
//    return !m_doc.IsNull() && m_id != 0;
//}
//
//const DocumentTreeNode& DocumentTreeNode::Null() 
//{
//    static const DocumentTreeNode node = {};
//    return node;
//}
//
//TDF_Label DocumentTreeNode::Label() const 
//{
//    if (this->IsValid()) 
//    {
//        return TDF_Label();
//    }
//    else 
//    {
//        return TDF_Label();
//    }
//}
