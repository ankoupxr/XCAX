#include <TreeNode.h>

///Tree
template<typename T> Tree<T>::Tree() {}

template<typename T> TreeNodeId Tree<T>::NodeParent(TreeNodeId id) const {
    const TreeNode* node = this->ptrNode(id);
    return node ? node->parent : 0;
}

template<typename T> 
TreeNodeId Tree<T>::NodeRoot(TreeNodeId id) const {
    while (!this->NodeIsRoot(id))
        id = this->NodeParent(id);

    return id;
}

template<typename T>
std::vector<TreeNodeId> Tree<T>::NodeChilds(TreeNodeId id) const
{
    return m_treeNodeIdArray;
}

template<typename T>
const T& Tree<T>::NodeData(TreeNodeId id) const 
{
    static const T nullObject = {};
    const TreeNode* node = this->
}


//DocumentTreeNode
DocumentTreeNode::DocumentTreeNode(const DocPtr& docPtr, TreeNodeId nodeId)
    : m_doc(docPtr), m_id(nodeId)
{ }

bool DocumentTreeNode::IsValid() const
{
    return !m_doc.IsNull() && m_id != 0;
}

const DocumentTreeNode& DocumentTreeNode::Null() 
{
    static const DocumentTreeNode node = {};
    return node;
}

TDF_Label DocumentTreeNode::Label() const 
{
    if (this->IsValid()) 
    {
        return TDF_Label();
    }
    else 
    {
        return TDF_Label();
    }
}
