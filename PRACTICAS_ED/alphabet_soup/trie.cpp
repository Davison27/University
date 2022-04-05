#include <cassert>
#include "trie.hpp"

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

TrieNode::TrieNode(){
    //TODO
    //Hint: Do you need to do something?
};

TrieNode::Ref TrieNode::create()
{
    return std::make_shared<TrieNode>();
}

bool TrieNode::has(char k) const
{
    bool ret_v = false;
    //TODO

    auto a = children_.begin();

    while (a != children_.end())
    {
        if (a->first == k)
            return true;

        a++;
    }

    //
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const
{
    assert(has(k));
    TrieNode::Ref ret_v;
    //TODO
    auto a = children_;
    ret_v = a[k];
    //
    return ret_v;
}

std::string const &
TrieNode::value() const
{
    return value_;
}

const std::map<char, TrieNode::Ref> &TrieNode::children() const
{
    return children_;
}

void TrieNode::set_value(std::string const &new_v)
{
    value_ = new_v;
}

void TrieNode::insert(char k, Ref node)
{
    //TODO
    children_.insert(std::make_pair(k, node));
    //
}

Trie::Trie()
{
    //TODO
    //Hint: Do you need to do something?
}

Trie::Ref Trie::create()
{
    return std::make_shared<Trie>();
}

TrieNode::Ref Trie::root() const
{
    //TODO
    return root_;
    //
}

bool Trie::has(std::string const &k) const
{
    bool found = false;
    //TODO
    //Remember: The Trie can have a prefix==k but does not store the key k.
    if (root_ != nullptr)
    {
        auto a = find_node(k);
        found = (a != nullptr) && (k.size() == a->value().size());
    }
    //
    return found;
}

std::vector<std::string>
Trie::keys(std::string const &pref) const
{
    std::vector<std::string> keys;
    //TODO
    auto a = find_node(pref);
    if (a != nullptr)
    {
        preorder_traversal(a, keys);
    }
    //
    return keys;
}

void Trie::insert(std::string const &k)
{
    //TODO
    if (root_ == nullptr)
        root_ = std::make_shared<TrieNode>(TrieNode());

    TrieNode::Ref n = root_;
    for (size_t i = 0; i < k.size(); i++)
    {
        if (n->has(k[i]) == false)
        {
            auto m = std::make_shared<TrieNode>(TrieNode());
            n->insert(k[i], m);
            n = m;
        }

        else
            n = n->child(k[i]);
    }
    n->set_value(k);

    //
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const &pref) const
{
    TrieNode::Ref node;
    //TODO
    node = root_;
    size_t a = 0;
    while (a <= pref.length() && node->has(pref[a]))
    {
        node = node->child(pref[a]);
        a++;
    }
    //
    return node;
}

void Trie::preorder_traversal(TrieNode::Ref const &node,
                              std::vector<std::string> &keys) const
{
    //TODO
    if (node->value() != "")
        keys.push_back(node->value());

    auto a = node->children().begin();
    while (a != node->children().end())
    {
        preorder_traversal(a->second, keys);
        a++;
    }
    //
}
