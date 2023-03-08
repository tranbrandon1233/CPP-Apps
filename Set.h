// Set.h

#ifndef SET_INCLUDED
#define SET_INCLUDED


template <typename T>

class Set
{

public:
    bool empty() const;  // Return true if the set is empty, otherwise false.
    int size() const;    // Return the number of items in the set.

    Set();

    bool insert(const T& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if value is not inserted (perhaps because it
    // was already in the set or because the set has a fixed capacity and
    // is full).

    bool erase(const T& value);
    // Remove the value from the set if it is present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.

    bool contains(const T& value) const;
    // Return true if the value is in the set, otherwise false.

    bool get(int i, T& value) const;
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly greater than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
    // Exchange the contents of this set with the other one.

    // Housekeeping functions
    ~Set();
    Set(const Set<T>& other);
    Set<T>& operator=(const Set<T>& rhs);

private:
    // Representation:
    //   a circular doubly-linked list with a dummy node.
    //   m_head points to the dummy node.
    //   m_head->m_prev->m_next == m_head and m_head->m_next->m_prev == m_head
    //   m_size == 0  iff  m_head->m_next == m_head->m_prev == m_head
    //   If p and p->m_next point to nodes other than the dummy node,
    //      p->m_value > p->m_next->m_value

    struct Node
    {
        T m_value;
        Node* m_next;
        Node* m_prev;
    };

    Node* m_head;
    int   m_size;

    void createEmpty();
    // Create an empty list.  (Will be called only by constructors.)

    void insertBefore(Node* p, const T& value);
    // Insert value in a new Node before Node p, incrementing m_size.

    void doErase(Node* p);
    // Remove the Node p, decrementing m_size.

    Set<T>::Node* findFirstAtLeast(const T& value) const;
    // Return pointer to first Node whose m_value >= value if present,
    // else m_head
};

// Declarations of non-member functions
template <typename T >

void unite(const  Set< T>& s1, const Set<T>& s2, Set<T>& result);
// result = { x | (x in s1) OR (x in s2) }

template <typename T >

void butNot(const Set<T>& s1, const Set<T>& s2, Set<T>& result);
// result = { x | (x in s1) AND NOT (x in s2) }

// template <typename T> implementations

template <typename T> inline
int Set<T>::size() const
{
    return m_size;
}

template <typename T> inline 
bool Set<T>::empty() const
{
    return size() == 0;
}

template <typename T> inline
bool Set<T>::contains(const T& value) const
{
    Node* p = findFirstAtLeast(value);
    return p != m_head && p->m_value == value;
}


#endif // SET_INCLUDED