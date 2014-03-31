#pragma once
#include <string>
template<typename T>
class MemoryPool
{
private:
	struct MemoryListData
	{
		T* data;
		MemoryListData* next;

		MemoryListData(void)
			: next(0), data(malloc(sizeof(T)))
		{
		}

		MemoryListData(MemoryListData* nextPoint)
			: next(nextPoint)
		{
		}
	};
public:
#ifdef _DEBUG
	std::string errorStr;
#endif
	MemoryListData* memoryListPoint;

	MemoryListData* usedList;

	T* bind(void)
	{
		if(memoryListPoint != 0)
		{
			MemoryListData* p = memoryListPoint;
			memoryListPoint = memoryListPoint->next;
			p->next = usedList;
			usedList = p;
			return p->data;
		}
		else
		{
			usedList = new MemoryListData(usedList);
			return usedList->data;
		}
	}

	void release(T* data)
	{
#ifdef _DEBUG
		if(usedList == 0)
		{
			errorStr += "Release error!\r\n";
			return;
		}
#endif
		usedList->data = data;
		MemoryListData* p = usedList->next;
		usedList->next = memoryListPoint;
		memoryListPoint = usedList;
		usedList = p;
	}

	MemoryPool(void)
		: memoryListPoint(0), usedList(0)
	{
	}

	MemoryPool(int n)
	{
		if(n < 1)
			return;
		memoryListPoint = new MemoryListData();
		MemoryListData* p = memoryListPoint;
		for(int i=1;i<n;++i)
		{
			p = p->next = new MemoryListData();
		}
	}

	~MemoryPool(void)
	{
		MemoryListData* p, p2;
		p = memoryListPoint;
		while(p2 = p)
		{
			delete p->data;
			p = p->next;
			delete p2;
		}

		p = usedList;
		while(p2 = p)
		{
			delete p->data;
			p = p->next;
			delete p2;
		}
	}
};

