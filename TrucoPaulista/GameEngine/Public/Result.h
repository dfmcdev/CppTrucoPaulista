#pragma once
#include <string>

namespace GameEngine
{
	/*! \enum ResultCode
		\brief Enumeracao que representa os possiveis retornos de uma operacao que retorna um Result.
	*/
	enum ResultCode
	{
		Undefined,
		Success,
		Failed,
		GameIsFull,
		PlayerAlreadyJoined
	};

	/*! \class Result
	*	\brief Classe que representa o resultado de uma operacao que pode falhar de forma aceitavel.
	*/
	class Result
	{
	private:
		std::string m_Message;
		ResultCode m_Code;

	public:
		Result() : m_Code(ResultCode::Undefined), m_Message("") {}
		Result(ResultCode code, std::string message) : m_Code(code), m_Message(message) {}

		static Result Success() { return Result(ResultCode::Success, ""); }

		bool IsSuccess() { return m_Code == ResultCode::Success; }
		ResultCode GetCode() { return m_Code; }
		std::string GetMessage() { return m_Message; }
	};
};
