#include <talkheui/interpreter.hpp>

#include <utility>

namespace talkheui
{
	runtime_status::~runtime_status()
	{
		for (memory* mem : memories_)
		{
			delete mem;
		}
	}

	std::vector<const memory*> runtime_status::memories() const
	{
		return std::vector<const memory*>(memories_.begin(), memories_.end());
	}

	std::vector<memory*>& runtime_status::memories() noexcept
	{
		return memories_;
	}
	void runtime_status::memories(std::vector<memory*> new_memories) noexcept
	{
		memories_ = std::move(new_memories);
	}
}

namespace talkheui
{
	interpreter::~interpreter()
	{
		delete status_;
	}

	interpreter::interpreter(std::string name) noexcept
		: name_(std::move(name))
	{}
	interpreter::interpreter(const interpreter& interpreter)
		: name_(interpreter.name_)
	{}
	interpreter::interpreter(interpreter&& interpreter) noexcept
		: name_(std::move(interpreter.name_))
	{}

	interpreter& interpreter::operator=(const interpreter& interpreter)
	{
		name_ = interpreter.name_;
		return *this;
	}
	interpreter& interpreter::operator=(interpreter&& interpreter) noexcept
	{
		name_ = std::move(interpreter.name_);
		return *this;
	}

	std::string interpreter::name() const
	{
		return name_;
	}
	const runtime_status* interpreter::status() const noexcept
	{
		return status_;
	}
	runtime_status* interpreter::status() noexcept
	{
		return status_;
	}
	void interpreter::status(runtime_status* new_status) noexcept
	{
		delete status_;
		status_ = new_status;
	}
}