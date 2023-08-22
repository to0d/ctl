#ifndef __LT_CPP_TREE__
#define __LT_CPP_TREE__

#include <lt_help/cpp/lt_cpp_base.h>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void outputTree(TreeNode* tree)
{
    std::vector<TreeNode*> nodeList;

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(tree);
    while(!nodeQueue.empty())
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        nodeList.push_back(node);
        
        if( node != nullptr )
        {   nodeQueue.push(node->left); 
            nodeQueue.push(node->right); 
        }
    }
    
    int size = nodeList.size();
    while( size > 0 && nodeList[size-1] == nullptr )
    {   --size;
    }
    
    std::cout << "[";
    for(int i=0; i<size; ++i)
    {
        if( i != 0 )
            std::cout << ",";

        TreeNode* node = nodeList[i];
        if( node == nullptr )
        {   std::cout << "null";
        }
        else
        {
            std::cout << node->val;
        }        
    }
    std::cout << "]";
}


TreeNode* makeTree(std::string s)
{
    // "{1,2,3,#,#,4,#,#,5}"
    
    int begin = 0;
    int end   = s.size();

    while( begin < end && s[begin] != '{' )
        ++begin;
    
    while( begin < end && s[end-1] != '}' )
        --end;
    
    if( begin == end )
        return nullptr;
    
    ++begin, --end; //skip {}
    
    std::vector<TreeNode*> nodeList;
    
    while( begin < end )
    {
        int pos = begin;
        while (pos < end && s[pos] != ',')
            ++pos;

        if( pos == (begin+1) && s[begin] == '#' )
        {   nodeList.push_back(nullptr);
        }
        else if( pos == (begin+4) && s.substr(begin, 4) == "null" )
        {   nodeList.push_back(nullptr);
        }
        else
        {
            std::string str = s.substr(begin, pos-begin);
            // std::cout << "str=\"" << s << "\"" << ", pos=" << pos << ", begin=" << begin << std::endl;
            int val = std::stoi(s.substr(begin, pos-begin));
            nodeList.push_back(new TreeNode(val));
        }
            
        begin = pos+1;
    }
       
    
    TreeNode* root = nullptr;
    TreeNode* cur  = nullptr;
    bool      left = true;
    
    std::queue<TreeNode*> nodeQueue;

    for( TreeNode* node: nodeList)
    {
        if( cur == nullptr )
        {   if( !nodeQueue.empty() )
            {   cur = nodeQueue.front();
                nodeQueue.pop();
                left = true;
            }
        }

        if( node == nullptr )
        {
            if( cur != nullptr )
            {
                if( left )
                    left = false;
                else
                    cur = nullptr;
            }
        }
        else if( root == nullptr )
        {
            root = node;
            cur  = node;
        }
        else
        {

            if( left )
            {
                left = false;
                cur->left = node;
            }
            else
            {
                cur->right = node;
                cur = nullptr;
            }

            nodeQueue.push(node);
        }
    }

    return root;
}

TreeNode* TN(int val)
{   return new TreeNode(val);
}


//TreeNode* makeTree(int num, ...)
//{
//    TreeNode* root = nullptr;
//    TreeNode* cur  = nullptr;
//    bool      left = true;
//    
//    std::queue<TreeNode*> nodeQueue;
//
//    va_list valist;
//    va_start(valist, num); 
//    for (int i = 0; i < num; i++)
//    {
//        if( cur == nullptr )
//        {   if( !nodeQueue.empty() )
//            {   cur = nodeQueue.front();
//                nodeQueue.pop();
//                left = true;
//            }
//        }
//
//        TreeNode* node = va_arg(valist, TreeNode*);
//        if( node == nullptr )
//        {
//            if( cur != nullptr )
//            {
//                if( left )
//                    left = false;
//                else
//                    cur = nullptr;
//            }
//        }
//        else if( root == nullptr )
//        {
//            root = node;
//            cur  = node;
//        }
//        else
//        {
//
//            if( left )
//            {
//                left = false;
//                cur->left = node;
//            }
//            else
//            {
//                cur->right = node;
//                cur = nullptr;
//            }
//
//            nodeQueue.push(node);
//        }
//    }
//
//    va_end(valist);    
//
//    return root;
//}


TreeNode* findNode(TreeNode* tree, int val)
{

    if( tree == NULL || tree->val == val )
        return tree;
    
    TreeNode* node = findNode(tree->left, val);
    if( node != NULL )
        return node;
    
    return findNode(tree->right, val);
}

#endif //__LT_CPP_TREE__