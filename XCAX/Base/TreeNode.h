#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>


using TreeNodeId = uint32_t;


template<typename T> class Tree
{
public:
	Tree();

	TreeNodeId NodeRoot(TreeNodeId id) const;

	TreeNodeId NodeParent(TreeNodeId id) const;

	TreeNodeId NodeChild(TreeNodeId id) const;

	~Tree();

private:
	struct TreeNode 
	{
		TreeNodeId PreviousId;
		TreeNodeId NextId;
		TreeNodeId ParentId;
		T data;
		bool IsDeleted;
	};
};
