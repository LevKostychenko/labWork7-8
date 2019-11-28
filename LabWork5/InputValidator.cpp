#include "pch.h"
#include "InputValidator.h"
#include <string>

bool InputValidator::IsInputCorrect(std::istream &in, char* buffer)
{
	bool isCorrect = false;
	while (!isCorrect)
	{
		try
		{
			try
			{
				try
				{
					in.clear();
					in >> buffer;
					if (strlen(buffer) == 0 || in.fail())
					{
						rewind(stdin);
						in.clear();
						throw Exception("NULL input");
					}

					for (int i = 0; *(buffer + i) != '\0'; i++)
					{
						if (((*(buffer + i) < 'A' || *(buffer + i) > 'Z') && *(buffer + i) < 'a') || ((((*(buffer + i) < 'a') || *(buffer + i) > 'z')) && ((*(buffer + i) < 'A') && (*(buffer + i) > 'Z'))) || in.fail())
						{
							rewind(stdin);
							in.clear();
							throw InputException("Invalid symbols", "ENG");
						}
					}
				}
				catch (const InputException& ex)
				{
					std::cout << "Error has occured. Details: " << ex.Description << ". Current language: " << ex.CurrentLang << " \n";
					throw;
				}
			}
			catch (const Exception& ex)
			{
				std::cout << "Error has occured. Details: " << ex.Description << " \n";
				throw;
			}
		}
		catch (...)
		{
			std::cout << "Some Error has occured.\n";
			continue;
		}

		isCorrect = true;
	}

	rewind(stdin);
	return true;
}

bool InputValidator::IsNumberInputCorrect(std::istream &in, int min, int max, int& buff)
{
	bool isCorrect = false;
	while (!isCorrect)
	{
		try
		{
			try
			{
				try
				{
					in.clear();
					in >> buff;

					if (in.fail())
					{
						rewind(stdin);
						in.clear();
						throw InputException("Not number", "ENG");
					}

					if (in.peek() != '\n')
					{
						rewind(stdin);
						in.clear();
						throw InputException("Not number", "ENG");
					}

					if (buff < min || buff > max )
					{
						rewind(stdin);
						in.clear();
						throw InputException("Number out of border", "ENG");						
					}
				}
				catch (const InputException& ex)
				{
					std::cout << "Error has occured. Details: " << ex.Description << ". Current language: " << ex.CurrentLang << " \n";
					throw;
				}
			}
			catch (const Exception& ex)
			{
				std::cout << "Error has occured. Details: " << ex.Description << " \n";
				throw;
			}
		}
		catch (...)
		{
			std::cout << "Some Error has occured.\n";
			continue;
		}

		isCorrect = true;
	}

	return true;
}