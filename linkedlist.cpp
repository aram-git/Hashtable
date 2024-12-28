/* ************************************************************
 * Name: Aaron Ramirez
 * Assignment: 7 Hash Tables with Separate Chaining
 * Purpose: linkedlist.cpp - Implementation of a doubly linked list
 *************************************************************/

#include "linkedlist.h"

LinkedList::LinkedList() : head(NULL_PTR) {
    /* *************************************************
     * Constructor initializes an empty linked list.
     * The head is set to nullptr to indicate an empty list.
     *
     * @param none
     * @exception none
     * @return void
     ************************************************* */
}

LinkedList::~LinkedList() {
    /* *************************************************
     * Destructor clears the list and frees all memory.
     * Calls clearList() to delete all nodes.
     *
     * @param none
     * @exception none
     * @return void
     ************************************************* */
    clearList();
}

LinkedList::LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)) {
    /* *************************************************
     * Move Constructor
     * Transfers ownership from the other LinkedList instance.
     *
     * @param LinkedList&& other : temporary linked list to move from
     * @exception none
     * @return void
     ************************************************* */
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    /* *************************************************
     * Move Assignment Operator
     * Clears the current list and transfers ownership from the other instance.
     *
     * @param LinkedList&& other : temporary linked list to move from
     * @exception none
     * @return LinkedList& : reference to the current object
     ************************************************* */
    if (this != &other) {
        clearList();
        head = std::move(other.head);
    }
    return *this;
}

bool LinkedList::addNode(int id, const std::string& data) {
    /* *************************************************
     * Adds a node with a unique ID and non-empty string.
     * Memory is allocated for the new node and inserted
     * into the linked list in ascending order of ID.
     *
     * @param int id : unique identifier for the node
     * @param const std::string& data : data for the node
     * @exception none
     * @return bool : true if insertion succeeded, false otherwise
     ************************************************* */
    bool success = false;

    if (id > 0 && !data.empty()) {
        auto newNode = std::make_shared<Node>(Data{id, data});

        if (!head) {
            head = newNode;
            success = true;
        } else {
            auto current = head;
            std::shared_ptr<Node> previous = NULL_PTR;

            while (current && current->data.id < id) {
                previous = current;
                current = current->next;
            }

            if (!current || current->data.id != id) {
                newNode->next = current;
                newNode->prev = previous;

                if (previous) {
                    previous->next = newNode;
                } else {
                    head = newNode;
                }

                if (current) {
                    current->prev = newNode;
                }

                success = true;
            }
        }
    }
    return success;
}

bool LinkedList::deleteNode(int id) {
    /* *************************************************
     * Deletes a node by its ID.
     * Searches for the node with the specified ID and
     * deletes it from the linked list, freeing the memory.
     *
     * @param int id : unique identifier of the node to delete
     * @exception none
     * @return bool : true if deletion succeeded, false if not found
     ************************************************* */
    bool success = false;
    std::shared_ptr<Node> nodeToDelete;
    findNode(id, nodeToDelete);

    if (nodeToDelete) {
        if (auto prev = nodeToDelete->prev.lock()) {
            prev->next = nodeToDelete->next;
        } else {
            head = nodeToDelete->next;
        }

        if (nodeToDelete->next) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        success = true;
    }

    return success;
}

bool LinkedList::clearList() {
    /* *************************************************
     * Clears the entire linked list.
     * Deletes all nodes and sets the head to nullptr,
     * freeing all allocated memory.
     *
     * @param none
     * @exception none
     * @return bool : success
     ************************************************* */
    head.reset();
    return true;
}

bool LinkedList::getNode(int id, Data& data) const {
    /* *************************************************
     * Retrieves the data of a node by its ID.
     * If the node is found, its data is copied into the
     * passed Data structure.
     *
     * @param int id : ID of the node to retrieve
     * @param Data& data : reference to store the retrieved data
     * @exception none
     * @return bool : true if node found, false otherwise
     ************************************************* */
    bool found = false;
    std::shared_ptr<Node> node;
    findNode(id, node);

    if (node) {
        data = node->data;
        found = true;
    } else {
        data.id = INVALID_ID;
        data.data = "";
    }

    return found;
}

int LinkedList::getCount() const {
    /* *************************************************
     * Counts the total number of nodes in the linked list.
     * Traverses the list and returns the count.
     *
     * @param none
     * @exception none
     * @return int : number of nodes in the list
     ************************************************* */
    int count = 0;
    auto current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::printList(bool backward) const {
    /* *************************************************
     * Prints the linked list either forward or backward.
     * The order of printing is determined by the 'backward' flag.
     *
     * @param bool backward : if true, print in reverse order
     * @exception none
     * @return void
     ************************************************* */
    if (!head) {
        std::cout << "EMPTY" << std::endl;
    } else {
        if (backward) {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            while (current) {
                std::cout << current->data.id << " --> ";
                current = current->prev.lock();
            }
        } else {
            auto current = head;
            while (current) {
                std::cout << current->data.id << " --> ";
                current = current->next;
            }
        }
        std::cout << "NULL" << std::endl;
    }
}

void LinkedList::findNode(int id, std::shared_ptr<Node>& node) const {
    /* *************************************************
     * Finds a node by its ID and updates the node reference
     * if the node with the specified ID is found.
     *
     * @param int id : ID to search for
     * @param std::shared_ptr<Node>& node : reference to node pointer
     * @exception none
     * @return void
     ************************************************* */
    node = head;
    while (node) {
        if (node->data.id == id) {
            return;
        }
        node = node->next;
    }
    node = NULL_PTR;
}
