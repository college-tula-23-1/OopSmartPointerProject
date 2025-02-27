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
	static int count;
public:
	ShareSmartPointer(T* pointer = nullptr)
		: SmartPointer(pointer)
	{
		if (count == 0) count = 1;
	}

	ShareSmartPointer(const ShareSmartPointer& other)
	{
		this->pointer = other.pointer;
		count++;
	}

	ShareSmartPointer operator=(const ShareSmartPointer& other)
	{
		if (&other == this)
			return *this;

		if (this->pointer)
			delete this->pointer;

		this->pointer = other.pointer;
		count++;
	}

	~ShareSmartPointer()
	{
		if (count == 1)
			delete this->pointer;
		count--;
	}
};

template <typename T>
class UniqueSmartPointer : public SmartPointer<T>
{
public:
	UniqueSmartPointer(T* pointer = nullptr)
		: SmartPointer(pointer) {}

	UniqueSmartPointer(UniqueSmartPointer& other)
	{
		// copy semantic
		// pointer = new T();
		// *pointer = *(other.pointer);

		this->pointer = other.pointer;
		other.pointer = nullptr;
	}

	UniqueSmartPointer operator=(const UniqueSmartPointer& other)
	{
		if (&other == this)
			return *this;

		if (this->pointer)
			delete this->pointer;

		this->pointer = other.pointer;
		other.pointer = nullptr;
	}

	~UniqueSmartPointer()
	{
		if(this->pointer)
			delete this->pointer;
	}
};