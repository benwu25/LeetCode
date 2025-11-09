#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node (int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) { }
    };

    Node *front;
    Node *back;

    unordered_map<int, Node *> key_map;

    int capacity;

    LRUCache(int capacity) : capacity(capacity), front(nullptr), back(nullptr) { }

    void move_to_front(Node *place) {
        // check new node
        if (!place->next && !place->prev) {
            // save old front
            place->next = front;

            // set old front prev if valid
            if (front)
                front->prev = place;

            // update front
            front = place;
        }

        // pre-existing node

        if (place == front)
            return;
        if (place == back) {
            // update back
            back = place->prev;

            // new back should have no next pointer
            place->prev->next = nullptr;

            // save old front
            place->next = front;

            // set old front prev
            front->prev = place;

            // front has no prev pointer
            place->prev = nullptr;

            // update front
            front = place;
        } else {
            // link prev to next
            place->prev->next = place->next;

            // link next to prev
            place->next->prev = place->prev;

            // save old front
            place->next = front;

            // set old front prev
            front->prev = place;

            // front has no prev pointer
            place->prev = nullptr;

            // update front
            front = place;
        }
    }

    int get(int key) {
        if (!key_map.contains(key))
            return -1;
        Node *place = key_map[key];
        int value = place->value;
        move_to_front(place);
        return value;
    }

    void put(int key, int value) {
        if (key_map.contains(key)) {
            Node *place = key_map[key];
            place->value = value;
            move_to_front(place);
        } else if (key_map.size() < capacity) {
            // construct new node
            Node *place = new Node(key, value);

            // move to front
            move_to_front(place);

            // update key_map
            key_map[key] = place;

            // update back if one node
            if (key_map.size() == 1)
                back = place;
        } else {
            // identify LRU
            Node *lru = back;

            // erase from key_map
            key_map.erase(lru->key);

            // update back
            back = lru->prev;

            // if back, new back should have no next pointer
            if (back)
                lru->prev->next = nullptr;

            // construct new node
            Node *place = new Node(key, value);

            // move to front
            move_to_front(place);

            // update key_map
            key_map[key] = place;

            // update back if one node
            if (key_map.size() == 1)
                back = place;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
