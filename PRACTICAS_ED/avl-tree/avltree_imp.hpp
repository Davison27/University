#pragma once

#include "avltree.hpp"

#ifdef assert
//We undefined this macro to not shadow our implementation of assert.
#undef assert
#endif

/**
 * @brief Check an assertion.
 * In Debug mode, if the assertion is not met, a segfault is generated.
 * @param assertion
 */
inline void assert(bool assertion)
{
#ifndef NDEBUG
    (void)((assertion) || (__assert("Assert violation!", __FILE__, __LINE__), 0));
#endif
}

/****
 * AVLTNode class implementation.
****/

template <class T>
AVLTNode<T>::AVLTNode(T const &it, AVLTNode<T>::Ref parent,
                      AVLTNode<T>::Ref left, AVLTNode<T>::Ref right) : item_(it), parent_(parent), left_(left), right_(right), height_(0)
{
    //TODO
    compute_height();
    //
    assert(check_height_invariant());
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::create(T const &it,
                                              AVLTNode<T>::Ref parent,
                                              AVLTNode<T>::Ref left,
                                              AVLTNode<T>::Ref right)
{
    return std::make_shared<AVLTNode<T> >(it, parent, left, right);
}

template <class T>
const T &AVLTNode<T>::item() const
{
    //TODO

    return item_;
}

template <class T>
int AVLTNode<T>::height() const
{
    //TODO
    return height_;
}

template <class T>
int AVLTNode<T>::balance_factor() const
{
    int bf = 0;
    //TODO
    int l = 0, r = 0;
    if (has_right() == true)
    {
        right_->compute_height();
        r = 1 + right_->height();
    }

    if (has_left() == true)
    {
        left_->compute_height();
        l = 1 + left_->height();
    }
    bf = r - l;
    //
    return bf;
}

template <class T>
bool AVLTNode<T>::has_parent() const
{
    //TODO
    if (parent_ != nullptr)
        return true;

    return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::parent() const
{
    //TODO
    return parent_;
}

template <class T>
bool AVLTNode<T>::has_left() const
{
    //TODO
    if (left_ != nullptr)
        return true;

    return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::left() const
{
    //TODO
    return left_;
}

template <class T>
bool AVLTNode<T>::has_right() const
{
    //TODO
    if (right_ != nullptr)
        return true;

    return false;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::right() const
{
    //TODO
    return right_;
}

template <class T>
bool AVLTNode<T>::check_height_invariant() const
{
    bool ret_val = false;
    //TODO
    int l = -1, r = -1, max;

    if (has_left() == true)
        l = left_->height_;

    if (has_right() == true)
        r = right_->height_;

    if (r > l)
        max = r + 1;

    else if (r <= l)
        max = l + 1;

    if (height_ == max)
        ret_val = true;
    //
    return ret_val;
}

template <class T>
void AVLTNode<T>::set_item(const T &new_it)
{
    //TODO
    item_ = new_it;
    //
    assert(item() == new_it);
}

template <class T>
void AVLTNode<T>::set_parent(AVLTNode<T>::Ref const &new_parent)
{
    //TODO
    parent_ = new_parent;
    compute_height();
    //
    assert(parent() == new_parent);
}

template <class T>
void AVLTNode<T>::remove_parent()
{
    //TODO
    parent_ = nullptr;
    compute_height();
    //
    assert(!has_parent());
}

template <class T>
void AVLTNode<T>::set_left(AVLTNode<T>::Ref const &new_child)
{
    //TODO
    left_ = new_child;
    compute_height();
    //
    assert(check_height_invariant());
    assert(left() == new_child);
}

template <class T>
void AVLTNode<T>::remove_left()
{
    //TODO
    left_ = nullptr;
    compute_height();

    //
    assert(check_height_invariant());
    assert(!has_left());
}

template <class T>
void AVLTNode<T>::set_right(AVLTNode<T>::Ref const &new_child)
{
    //TODO
    right_ = new_child;
    compute_height();

    //
    assert(check_height_invariant());
    assert(right() == new_child);
}

template <class T>
void AVLTNode<T>::remove_right()
{
    //TODO
    right_ = nullptr;
    compute_height();

    //
    assert(check_height_invariant());
    assert(!has_right());
}

template <class T>
void AVLTNode<T>::compute_height()
{
    //TODO
    if (!has_right() && !has_left())
    {
        height_ = 0;
        if (has_parent())
            parent_->compute_height();
    }

    else
    {
        int r = 0, l = 0;
        if (has_right() == true)
            r = right_->height() + 1;

        if (has_left() == true)
            l = left_->height() + 1;

        if (l < r)
            height_ = r;

        else
            height_ = l;

        if (has_parent() == true)
            parent_->compute_height();
    }

    assert(check_height_invariant());
}

/***
 * AVLTree class implementation.
 ***/

template <class T>
AVLTree<T>::AVLTree()
{
    //TODO
    raiz_ = nullptr;
    actual_ = nullptr;
    previo_ = nullptr;
    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
}

template <class T>
AVLTree<T>::AVLTree(T const &item)
{
    //TODO
    raiz_ = AVLTNode<T>::create(item);

    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create()
{
    return std::make_shared<AVLTree<T> >();
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(T const &item)
{
    return std::make_shared<AVLTree<T> >(item);
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(std::istream &in) noexcept(false)
{
    auto tree = AVLTree<T>::create();
    std::string token;
    in >> token;
    if (!in)
        throw std::runtime_error("Wrong input format");

    //TODO
    if (token == "[")
    {
        T a;
        in >> a;
        tree = AVLTree<T>::create(a);

        auto l = AVLTree<T>::create(in);
        tree->set_left(l);

        auto r = AVLTree<T>::create(in);
        tree->set_right(r);

        in >> token;
    }

    else if (token != "[]")
    {
        throw std::runtime_error("Wrong input format");
    }

    if (!tree->is_a_balanced_tree())
    {
        throw std::runtime_error("It is not an avl bstree");
    }

    if (!tree->is_a_binary_search_tree())
    {
        throw std::runtime_error("It is not a binary search tree");
    }

    return tree;
}

#ifdef __ONLY_BSTREE__
/**
 * @brief Create a BSTree by inserting the median of an ordered sequence.
 * @param data is an ordered sequence of keys.
 * @param begin,
 * @param end specify a [begin, end) indexing interval of data to use.
 * @pre data values are in order.
 * @pre 0 <= begin <= end <=data.size()
 */
template <class T>
void create_inserting_median(std::vector<T> const &data,
                             size_t begin,
                             size_t end,
                             typename AVLTree<T>::Ref &tree)
{
    assert(begin <= end);
    assert(end <= data.size());

    //TODO
    //Hint: use a recursive design by inserting the median of input
    // (begin, end] interval
    //and recursively, apply to each sub-interval [begin, median),
    //[median+1, end).
    int resta = end - begin;
    if ((resta) >= 1)
    {

        tree->insert(data[begin + ((resta) / 2)]);
        create_inserting_median(data, begin, begin + ((resta) / 2), tree);
        create_inserting_median(data, (begin + ((resta) / 2)) + 1, end, tree);
    }
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(std::vector<T> &data)
{
    assert(data.size() > 0);
    auto tree = AVLTree<T>::create();
    std::sort(data.begin(), data.end());
    create_inserting_median(data, 0, data.size(), tree);
    return tree;
}
#endif //#ifdef __ONLY_BSTREE__

template <class T>
bool AVLTree<T>::is_empty() const
{
    //TODO
    if (raiz_ == nullptr)
        return true;

    return false;
}

template <class T>
T const &AVLTree<T>::item() const
{
    return raiz_->item();
}

template <class T>
std::ostream &AVLTree<T>::fold(std::ostream &out) const
{
    //TODO
    if (raiz_ == nullptr)
        out << "[]";

    else
    {
        out << "[ ";
        out << item();
        out << " ";
        left()->fold(out);
        out << " ";
        right()->fold(out);
        out << " ]";
    }
    //
    return out;
}

template <class T>
bool AVLTree<T>::current_exists() const
{
    //TODO
    auto a = raiz_;

    while (1)
    {
        if (actual_ == nullptr)
            return false;

        if (a->item() < actual_->item())
        {
            if (a->has_right() == true)
                a = a->right();

            else
            {
                return false;
            }
        }
        else if (actual_->item() < a->item())
        {
            if (a->has_left() == true)
                a = a->left();

            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}

template <class T>
T const &AVLTree<T>::current() const
{
    assert(current_exists());
    //TODO
    return actual_->item();
}

template <class T>
int AVLTree<T>::current_level() const
{
    assert(current_exists());
    int level = 0;
    //TODO
    for (auto i = raiz_; i != actual_; level++)
    {
        if (i->item() > actual_->item())
            i = i->left();

        else if (actual_->item() > i->item())
            i = i->right();
    }
    //
    return level;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::left() const
{
    assert(!is_empty());
    //TODO
    auto l = AVLTree<T>::create();

    if (raiz_->has_left())
    {
        l->create_root(raiz_->left()->item());
        l->raiz_->set_left(raiz_->left()->left());
        l->raiz_->set_parent(nullptr);
        l->raiz_->set_right(raiz_->left()->right());
    }

    return l;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::right() const
{
    assert(!is_empty());
    //TODO
    auto r = AVLTree<T>::create();

    if (raiz_->has_right())
    {
        r->create_root(raiz_->right()->item());
        r->raiz_->set_left(raiz_->right()->left());
        r->raiz_->set_parent(nullptr);
        r->raiz_->set_right(raiz_->right()->right());
    }

    return r;
}

template <class T>
int AVLTree<T>::size() const
{
    int s = 0;
    //TODO
    if (is_empty() == false)
        s = left()->size() + 1 + right()->size();

    return s;
}

template <class T>
int AVLTree<T>::height() const
{
    int h = -1;
    //TODO
    if (is_empty() == false)
    {
        h = raiz_->height();
    }
    //
    return h;
}

template <class T>
int AVLTree<T>::balance_factor() const
{
#ifdef __ONLY_BSTREE__
    return 0;
#else
    int bf = 0;
    //TODO
    if (!is_empty())
    {
        bf = raiz_->balance_factor();
    }
    //
    return bf;
#endif
}

template <class T>
bool AVLTree<T>::has(const T &k) const
{
#ifndef NDEBUG
    bool old_current_exists = current_exists();
    T old_current;
    if (old_current_exists)
        old_current = current();
#endif
    bool found = true;

    //TODO
    auto j = raiz_;

    while (1)
    {
        if (k < j->item())
        {
            if (j->has_left())
            {
                j = j->left();
            }
            else
            {
                found = false;
                break;
            }
        }
        else if (k > j->item())
        {
            if (j->has_right())
            {
                j = j->right();
            }
            else
            {
                found = false;
                break;
            }
        }
        else
            break;
    }
    //
#ifndef NDEBUG
    assert(!old_current_exists || old_current == current());
#endif
    return found;
}

template <class T>
bool AVLTree<T>::is_a_binary_search_tree() const
{
    bool is_bst = true;
    //TODO
    if (is_empty() == false)
    {
        if (raiz_->has_left())
        {
            is_bst = (item() > left()->item());
        }
        if (raiz_->has_right())
            is_bst = (item() < right()->item()) && is_bst;

        is_bst = right()->is_a_binary_search_tree() && is_bst && left()->is_a_binary_search_tree();
    }
    return is_bst;
}

template <class T>
bool AVLTree<T>::is_a_balanced_tree() const
{
#ifdef __ONLY_BSTREE__
    return true;
#else
    bool is_balanced = true;
    //TODO
    if (raiz_ != nullptr)
    {
        is_balanced = right()->is_a_balanced_tree() && (std::abs(raiz_->balance_factor()) <= 1) && left()->is_a_balanced_tree();
    }
    return is_balanced;
#endif
}

template <class T>
void AVLTree<T>::create_root(T const &item)
{
    assert(is_empty());
    //TODO
    raiz_ = AVLTNode<T>::create(item, nullptr, nullptr, nullptr);

    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
    assert(this->item() == item);
}

template <class T>
bool AVLTree<T>::search(T const &k)
{
    bool found = false;
    //TODO
    actual_ = raiz_;
    previo_ = nullptr;
    while (!found && actual_ != nullptr)
    {
        if (actual_->item() == k)
            found = true;

        else
        {
            previo_ = actual_;
            if (actual_->item() < k)
            {
                actual_ = actual_->right();
            }
            else
                actual_ = actual_->left();
        }
    }

    //
    assert(!found || current() == k);
    assert(found || !current_exists());
    return found;
}

template <class T>
void AVLTree<T>::insert(T const &k)
{
    if (!search(k))
    {
        //TODO
        if (is_empty())
        {
            actual_ = AVLTNode<T>::create(k, nullptr, nullptr, nullptr);
            raiz_ = actual_;
        }
        else
        {
            actual_ = AVLTNode<T>::create(k, previo_, nullptr, nullptr);
            if (previo_->item() < k)
            {
                previo_->set_right(actual_);
            }
            else
                previo_->set_left(actual_);
        }
        //
#ifdef __ONLY_BSTREE__
        assert(is_a_binary_search_tree());
#else
        assert(is_a_binary_search_tree());
        make_balanced();
        assert(is_a_balanced_tree());
#endif
    }

    //check postconditions.
    assert(current_exists());
    assert(current() == k);
}

template <class T>
void AVLTree<T>::remove()
{
    //check preconditions.
    assert(current_exists());

    bool replace_with_subtree = true;
    typename AVLTNode<T>::Ref subtree;

    //TODO
    // Check which of cases 0,1,2,3 we have.
    if (!actual_->has_left() && !actual_->has_right())
        subtree = nullptr;

    else if (!actual_->has_right())
        subtree = actual_->left();

    else if (!actual_->has_left())
        subtree = actual_->right();

    else
        replace_with_subtree = false;
    //

    if (replace_with_subtree == true)
    {
        //TODO
        //Manage cases 0,1,2
        if (previo_ == nullptr)
            raiz_ = subtree;

        if (previo_->right() == actual_)
            previo_->set_right(subtree);

        else
            previo_->set_left(subtree);

        actual_ = nullptr;

        //
#ifdef _ONLY_BSTREE_
        assert(is_a_binary_search_tree());
        assert(!current_exists());
#else
        assert(is_a_binary_search_tree());
        make_balanced();
        assert(is_a_balanced_tree());
        assert(!current_exists());
#endif
    }
    else
    {
        //TODO
        //Manage case 3.
        //Segundo
        auto i = actual_;
        find_inorder_sucessor();
        i->set_item(actual_->item());
        remove();
    }
}

template <class T>
AVLTree<T>::AVLTree(typename AVLTNode<T>::Ref root_node)
{
    //TODO
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(typename AVLTNode<T>::Ref root)
{
    AVLTree<T>::Ref ret_v(new AVLTree<T>(root));
    return ret_v;
}

template <class T>
typename AVLTNode<T>::Ref const &AVLTree<T>::root() const
{
    //TODO
    return raiz_;
}

template <class T>
void AVLTree<T>::set_left(typename AVLTree<T>::Ref &subtree)
{
    assert(!is_empty());
    //TODO
    //Remenber to set parent's link of the subtree root to this.
    if (!subtree->is_empty())
    {
        raiz_->set_left(AVLTNode<T>::create(subtree->raiz_->item(), raiz_, subtree->raiz_->left(), subtree->raiz_->right()));
    }

    else
    {
        raiz_->set_left(nullptr);
    }
    //
    assert(subtree->is_empty() || left()->item() == subtree->item());
    assert(!subtree->is_empty() || left()->is_empty());
}

template <class T>
void AVLTree<T>::set_right(typename AVLTree<T>::Ref &subtree)
{
    assert(!is_empty());
    //TODO
    //Remenber to set parent's link of the subtree root to this.

    if (!subtree->is_empty())
    {
        raiz_->set_right(AVLTNode<T>::create(subtree->raiz_->item(), raiz_, subtree->raiz_->left(), subtree->raiz_->right()));
    }

    else
    {
        raiz_->set_right(nullptr);
    }
    //
    assert(subtree->is_empty() || right()->item() == subtree->item());
    assert(!subtree->is_empty() || right()->is_empty());
}

template <class T>
void AVLTree<T>::find_inorder_sucessor()
{
    assert(current_exists());
#ifndef NDEBUG
    T old_curr = current();
#endif
    //TODO
    previo_ = actual_;
    actual_ = actual_->right();

    while (actual_->has_left())
    {
        previo_ = actual_;
        actual_ = actual_->left();
    }
    //
    assert(current_exists());
#ifndef NDEBUG
    assert(current() > old_curr);
#endif
}

template <class T>
void AVLTree<T>::rotate_left(typename AVLTNode<T>::Ref node)
{
    //TODO
    //Remenber when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    auto i = node->left();

    if (!node->has_parent())
        raiz_ = i;

    else if (node->parent()->right() == node)
    {
        node->parent()->set_right(i);
    }

    else
    {
        node->parent()->set_left(i);
    }

    i->set_parent(node->parent());

    if (i->has_right())
    {
        node->set_left(i->right());
        i->right()->set_parent(node);
    }

    else
        node->remove_left();

    i->set_right(node);
    node->set_parent(i);

    node->compute_height();
    i->compute_height();
    //
}

template <class T>
void AVLTree<T>::rotate_right(typename AVLTNode<T>::Ref node)
{
    //TODO
    //Remenber when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    auto a = node->right();

    if (!node->has_parent())
        raiz_ = a;

    else if (node->parent()->right() == node)
    {
        node->parent()->set_right(a);
    }

    else
    {
        node->parent()->set_left(a);
    }

    a->set_parent(node->parent());

    if (a->has_left())
    {
        node->set_right(a->left());
        a->left()->set_parent(node);
    }

    else
        node->remove_right();

    a->set_left(node);
    node->set_parent(a);

    node->compute_height();
    a->compute_height();
    //
}

template <class T>
void AVLTree<T>::make_balanced()
{
#ifdef __ONLY_BSTREE__
    return;
#else
    //TODO
    //From current position, go up until root's node is achieved.
    //In each step, check if the current subtree is balanced and balance it
    // if not.
    while (previo_)
    {
        previo_->compute_height();
        int x = previo_->balance_factor();

        if (x >= 2)
        {
            auto c = previo_->right();
            int a = c->balance_factor();

            if (a >= 0)
            {
                rotate_right(previo_);
            }
            else
            {
                rotate_left(c);
                rotate_right(previo_);
            }
        }

        else if (x < -1)
        {
            auto c = previo_->left();
            int a = c->balance_factor();

            if (a <= 0)
            {
                rotate_left(previo_);
            }
            else
            {
                rotate_right(c);
                rotate_left(previo_);
            }
        }
        else
        {
            previo_ = previo_->parent();
        }
    }
#endif //__ONLY_BSTREE__
}
