#pragma once
#include <exception>
#include "text.hpp"
namespace tomoto
{
	namespace exception
	{
		class TrainingError : public std::runtime_error
		{
		public:
			using std::runtime_error::runtime_error;
		};
	}
}

#define THROW_ERROR_WITH_INFO(exec, msg) do {throw exec(tomoto::text::format("%s (%d): ", __FILE__, __LINE__) + msg); } while(0)