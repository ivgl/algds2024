#include "NumberOfRoutes.h"

int NumberOfRoutesAll(int size, int stepsize)
{
	// Проверка на допустимые значения
	if ((size <= 0) || (stepsize < 0))
	{
		return 0;
	}

	// Список, в котором будем указывать количество путей до данной точки поля
	int *fieldlist;
	fieldlist = malloc((size + 1) * sizeof(int));

	// Заполняем этот список
	fieldlist[0] = 1;
	for (int i = 1; i <= size; i++)
	{
		fieldlist[i] = 0;
	}

	// Функция, которая пробегает весь список и поэлементно добавляет все пути на ранних этапах
	int steplength;
	for (int i = 0; i <= size; i++)
	{
		for (steplength = 1; (steplength <= stepsize) && (steplength + i <= size); steplength++)
		{
			fieldlist[i + steplength] += fieldlist[i];
		}
	}

	// Результат - последние поле в этом списке, ведь мы идем именно до него
	int result;
	result = fieldlist[size];
	free(fieldlist);

	return result;
}