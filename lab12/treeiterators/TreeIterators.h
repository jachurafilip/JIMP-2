//
// Created by filip on 31.05.18.
//

#include "../tree/Tree.h"
#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

namespace tree {

    template <typename T>
    class InOrderTreeIterator
    {
    public:
        explicit InOrderTreeIterator(Tree<T> &element)
        {
            while (element.Left())
            {
                element = *element.Left();
            }

            element_ = std::make_shared<Tree<T>>(element);
        }


        void operator++()
        {
          //todo
        }

        T& operator* ()
        {
            return *(element_->value_);
        }

        bool operator!=(const InOrderTreeIterator<T> &other) const
        {
            return element_->Value()!=other.element_->Value() || left_seen_ != other.left_seen_;
        }
        std::shared_ptr<Tree<T>> element_;
        bool left_seen_;


    };

    template <typename T>
    class InOrderTreeView
    {
    public:
        explicit InOrderTreeView<T>(Tree<T> *tree)
        {
            root_ = std::make_shared<Tree<T>>(*tree);
        }
        InOrderTreeIterator<T>begin()
        {
            while (root_->Left())
            {
                root_ = root_ ->Left();
            }
            return InOrderTreeIterator<T>(*root_);
        }

        InOrderTreeIterator<T>end()
        {
            while(root_->Right())
            {
                root_ = root_ -> Right();
            }
            return InOrderTreeIterator<T>(*root_);
        }

    private:
        std::shared_ptr<Tree<T>> root_;
    };

    template <typename T>
    InOrderTreeView<T> InOrder(Tree<T> *tree)
    {
        return InOrderTreeView<T>(tree);
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
