#pragma once
template <typename T>
class SmartPointer
{
protected:
	T* pointer{};
public:
	SmartPointer(T* pointer = nullptr)
		: pointer{ pointer } {}

	~SmartPointer()
	{
		delete pointer;
	}

	T* operator->() const
	{
		return pointer;
	}

	T& operator*() const
	{
		return *pointer;
	}
};

template <typename T>
class ShareSmartPointer : public SmartPointer<T>
{
	static int count{};
public:
	ShareSmartPointer(T* pointer = nullptr)
		: SmartPointer(pointer)
	{
		count = 1;
	}

	ShareSmartPointer(const ShareSmartPointer& other)
	{
		pointer = other.pointer;
		count++;
	}

	~ShareSmartPointer()
	{
		if (count == 1)
			delete pointer;
		count--;
	}
};

template <typename T>
class UniqueSmartPointer : public SmartPointer<T>
{
public:
	UniqueSmartPointer(T* pointer = nullptr)
		: SmartPointer(pointer) {}

	UniqueSmartPointer(const UniqueSmartPointer& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
	}

	~UniqueSmartPointer()
	{
		if(pointer)
			delete pointer;
	}
};