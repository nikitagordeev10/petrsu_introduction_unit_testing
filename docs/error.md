Ошибка №1
Описание:		Выполнение набора тестов Viet
Тест:			11
Описание процесса:	TEST(Viet, integer_positive) {
    			discriminant(5, 6, 1, &x1, &x2, &flag);
    			viet(5, 6, 1, &vx1, &vx2, &vflag);
    			ASSERT_FLOAT_EQ(x1, vx2);
    			ASSERT_FLOAT_EQ(x2, vx2);
			}
Входные данные:	discriminant(5, 6, 1, &x1, &x2, &flag);
    			viet(5, 6, 1, &vx1, &vx2, &vflag);
Ожидаемый результат:	x1 = -1.00, x2 = -0.20, flag = 0
			vx1 = -1.00, vx2 = -0.20, flag = 0
Фактический результат:	discriminant_positive_test.h:58: 
			Failure
	      			Expected: x1
	      			Which is: -1
			To be equal to: vx1
	      			Which is: -1.000017
Возможная причина: 	Арифметические спецификаторы типов
Статус:		исправлена

