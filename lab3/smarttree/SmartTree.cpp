//
// Created by filip on 20.03.18.
//

#include "SmartTree.h"

using std::string;
using std::array;
using std::unique_ptr;
using std::ostream;
using std::move;


namespace datastructures
{
    std::unique_ptr<SmartTree> Init();

    std::unique_ptr<SmartTree> CreateLeaf(int value)
    {
        auto new_leaf = std::make_unique<SmartTree>();
        new_leaf->value = value;
        new_leaf->left = nullptr;
        new_leaf->right = nullptr;
        return new_leaf;
    }
    unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree)
    {
        tree->left = move(left_subtree);
        return tree;

    }

    unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree)
    {
        tree->right = move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out)
    {
        if(unique_ptr)
        {
            if(unique_ptr->left)
            {
                PrintTreeInOrder(unique_ptr->left,out);
            }
            *out << unique_ptr->value <<", ";
            if(unique_ptr->right)
            {
                PrintTreeInOrder(unique_ptr->right, out);
            }
        }
    }

    string DumpTree(const unique_ptr<SmartTree> &tree)
    {
        string dump = "";
        if (tree!= nullptr)
        {
            string lewa = DumpTree(tree->left);
            string prawa = DumpTree(tree ->right);
            dump+="[";
            if(tree!= nullptr)
            {
                dump += std::to_string(tree->value);
            }
            dump+=" ";
            dump+=lewa;
            dump+=" ";
            dump+=prawa;
            dump+="]";
        }
        else
        {
            dump+="[none]";
        }
        return dump;
    }
    unique_ptr <SmartTree> RestoreTree(const std::string &tree)
    {

    }
}
