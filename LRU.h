#pragma once

#include <iostream>

//#define COUNT_HIT_MISS

#undef USE_POINTERS
//#define USE_POINTERS
#ifdef USE_POINTERS

template<typename data_type, size_t size>
class LRU
{
public:

	LRU()
	{
		buffer = new Node[size];
		hash_table = new Node*[size];

		for (unsigned i = 0; i < size; ++i)
		{
			buffer[i].list_prev = buffer + (i - 1);
			buffer[i].list_next = buffer + (i + 1);
			buffer[i].hash_parent = 0;
			buffer[i].hash_child = 0;
			hash_table[i] = 0;
		}

		list_head = buffer;
		list_head->list_prev = 0;
		list_tail = buffer + (size - 1);
		list_tail->list_next = 0;

#ifdef COUNT_HIT_MISS
		hit = 0;
		miss = 0;
#endif
	}


	~LRU()
	{
		delete[] hash_table;
		delete[] buffer;
	}


	void Print()
	{
		Node *tmp = list_head;

		int i = 0;

		while (tmp)
		{
			std::cout << tmp->id << ", ";
			tmp = tmp->list_next;

			if (++i == size)
				break;
		}

		std::cout << std::endl;

		for (unsigned i = 0; i < size; ++i)
		{
			Node *tmp = hash_table[i];

			std::cout << i << ": ";

			if (!tmp)
			{
				std::cout << "x ";
				continue;
			}

			while (tmp)
			{
				std::cout << tmp->id << " ";
				tmp = tmp->hash_child;
			}

			std::cout << "- ";
		}

		std::cout << std::endl << std::endl;

#ifdef COUNT_HIT_MISS
		std::cout << hit << " hits, and " << miss << " misses. Hit rate: " << 100.0 * hit / (hit + miss) << "%." << std::endl;
#endif
	}


	data_type Cache(const unsigned &id, data_type(*constructor)(void *param), void *param)
	{
		unsigned hash = id % size;
		Node *node = hash_table[hash];

		while (node)
		{
			if (node->id == id)
			{
				if (node != list_head)	//(node->list_prev)
				{
					if (node->list_next)
						node->list_next->list_prev = node->list_prev;
					else
						list_tail = node->list_prev;

					node->list_prev->list_next = node->list_next;

					node->list_prev = 0;
					node->list_next = list_head;
					list_head->list_prev = node;
					list_head = node;
				}

#ifdef COUNT_HIT_MISS
				++hit;
#endif

				return node->data;
			}
			else
				node = node->hash_child;
		}

		// clear old hash & fix new hash... a destructor for data could be called here if needed

		if (list_tail->hash_child)
			list_tail->hash_child->hash_parent = list_tail->hash_parent;

		if (list_tail->hash_parent)
			list_tail->hash_parent->hash_child = list_tail->hash_child;
		else
			hash_table[list_tail->id % size] = list_tail->hash_child;	// % can be removed if using pointer to pointer

		list_tail->hash_parent = 0;
		list_tail->hash_child = hash_table[hash];
		if (list_tail->hash_child)
			list_tail->hash_child->hash_parent = list_tail;
		hash_table[hash] = list_tail;

		// list stuff

		list_tail->id = id;
		list_tail->data = constructor(param);

		node = list_tail->list_prev;

		node->list_next = 0;
		list_tail->list_prev = 0;
		list_tail->list_next = list_head;
		list_head->list_prev = list_tail;

		list_head = list_tail;
		list_tail = node;

#ifdef COUNT_HIT_MISS
		++miss;
#endif

		return list_head->data;
	}


private:

	struct Node
	{
		unsigned id;
		data_type data;
		struct Node *list_prev;
		struct Node *list_next;
		struct Node *hash_parent;
		struct Node *hash_child;
	};

	Node *buffer;
	Node **hash_table;
	Node *list_head;
	Node *list_tail;

#ifdef COUNT_HIT_MISS
	unsigned hit;
	unsigned miss;
#endif
};


#else


template<typename data_type, size_t size>
class LRU
{
public:

	LRU()
	{
		buffer = new Node[size];
		hash_table = new unsigned short[size];

		for (unsigned i = 0; i < size; ++i)
		{
			buffer[i].list_prev = i - 1;
			buffer[i].list_next = i + 1;
			buffer[i].hash_parent = LIMIT;
			buffer[i].hash_child = LIMIT;
			hash_table[i] = LIMIT;
		}

		list_head = 0;
		buffer[list_head].list_prev = LIMIT;
		list_tail = size - 1;
		buffer[list_tail].list_next = LIMIT;

#ifdef COUNT_HIT_MISS
		hit = 0;
		miss = 0;
#endif
	}


	~LRU()
	{
		delete[] hash_table;
		delete[] buffer;
	}


	void Print()
	{
		unsigned short tmp = list_head;

		int i = 0;

		while (tmp != LIMIT)
		{
			std::cout << buffer[tmp].id << ", ";
			tmp = buffer[tmp].list_next;

			if (++i == size)
				break;
		}

		std::cout << std::endl;

		for (unsigned i = 0; i < size; ++i)
		{
			unsigned short tmp = hash_table[i];

			std::cout << i << ": ";

			if (tmp == LIMIT)
			{
				std::cout << "x - ";
				continue;
			}

			while (tmp != LIMIT)
			{
				std::cout << buffer[tmp].id << " ";
				tmp = buffer[tmp].hash_child;
			}

			std::cout << "- ";
		}

		std::cout << std::endl << std::endl;

#ifdef COUNT_HIT_MISS
		std::cout << hit << " hits, and " << miss << " misses. Hit rate: " << 100.0 * hit / (hit + miss) << "%." << std::endl;
#endif
	}


	data_type Cache(const unsigned &id, data_type(*constructor)(void *param), void *param)
	{
		unsigned hash = id % size;
		unsigned short node = hash_table[hash];

		while (node != LIMIT)
		{
			if (buffer[node].id == id)
			{
				if (node != list_head)
				{
					if (buffer[node].list_next != LIMIT)
						buffer[buffer[node].list_next].list_prev = buffer[node].list_prev;
					else
						list_tail = buffer[node].list_prev;

					buffer[buffer[node].list_prev].list_next = buffer[node].list_next;

					buffer[node].list_prev = LIMIT;
					buffer[node].list_next = list_head;
					buffer[list_head].list_prev = node;
					list_head = node;
				}

#ifdef COUNT_HIT_MISS
				++hit;
#endif

				return buffer[node].data;
			}
			else
				node = buffer[node].hash_child;
		}

		// clear old hash & fix new hash

		if (buffer[list_tail].hash_child != LIMIT)
			buffer[buffer[list_tail].hash_child].hash_parent = buffer[list_tail].hash_parent;

		if (buffer[list_tail].hash_parent != LIMIT)
			buffer[buffer[list_tail].hash_parent].hash_child = buffer[list_tail].hash_child;
		else
			hash_table[buffer[list_tail].id % size] = buffer[list_tail].hash_child;

		buffer[list_tail].hash_parent = LIMIT;
		buffer[list_tail].hash_child = hash_table[hash];
		if (buffer[list_tail].hash_child != LIMIT)
			buffer[buffer[list_tail].hash_child].hash_parent = list_tail;
		hash_table[hash] = list_tail;

		// list stuff

		buffer[list_tail].id = id;
		buffer[list_tail].data = constructor(param);

		node = buffer[list_tail].list_prev;

		buffer[node].list_next = LIMIT;
		buffer[list_tail].list_prev = LIMIT;
		buffer[list_tail].list_next = list_head;
		buffer[list_head].list_prev = list_tail;

		list_head = list_tail;
		list_tail = node;

#ifdef COUNT_HIT_MISS
		++miss;
#endif

		return buffer[list_head].data;
	}


private:

	struct Node
	{
		unsigned id;
		data_type data;
		unsigned short list_prev;
		unsigned short list_next;
		unsigned short hash_parent;
		unsigned short hash_child;
	};

	static const unsigned short LIMIT = 65535;

	Node *buffer;
	unsigned short *hash_table;

	unsigned short list_head;
	unsigned short list_tail;

#ifdef COUNT_HIT_MISS
	unsigned hit;
	unsigned miss;
#endif
};

#endif
