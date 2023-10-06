#include <TreeNode.h>



template<typename T> TreeNodeId Tree<T>::NodeParent(TreeNodeId id) const {
    const TreeNode* node = this->ptrNode(id);
    return node ? node->parent : 0;
}

template<typename T> TreeNodeId Tree<T>::NodeRoot(TreeNodeId id) const {
    while (!this->NodeIsRoot(id))
        id = this->NodeParent(id);

    return id;
}
