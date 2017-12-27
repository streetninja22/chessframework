#pragma once
#include <string>

class Team
{
	std::string m_teamName;

public:
	Team(std::string teamName) : m_teamName(teamName)
	{
	}

	std::string getName() const
	{
		return m_teamName;
	}

	void setName(std::string teamName)
	{
		m_teamName = teamName;
	}
};
