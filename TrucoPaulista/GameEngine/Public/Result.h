#pragma once
#include <string>

enum ResultCode
{
	Undefined,
	Success,
	Failed,
	GameIsFull,
	PlayerAlreadyJoined
};

class Result
{
private:
	std::string m_message;
	ResultCode m_code;

public:
	Result() : m_code(ResultCode::Undefined), m_message("") {}
	Result(ResultCode code, std::string message) : m_code(code), m_message(message) {}

	static Result Success() { return Result(ResultCode::Success, ""); }

	bool IsSuccess() { return m_code == ResultCode::Success; }
	ResultCode GetCode() { return m_code; }
	std::string GetMessage() { return m_message; }
};