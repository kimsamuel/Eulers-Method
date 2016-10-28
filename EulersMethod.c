#include <stdio.h>
#include "queue.h"
#include "stack.h"

struct symbol {
	int sym;
	int prec;
	int assoc;
};

typedef enum {LEFT, RIGHT} associativity;

const struct symbol operations[] = 
	{{'*', 3, LEFT}, {'/', 3, LEFT},
	 {'+', 2, LEFT}, {'-', 2, LEFT},};

Queue inputFunction(void);
double function(double t, double y);

int main(void)
{
	/*double h, y, t = 0.4;*/
	/*int i, j;*/

	/*printf("(value of h): ");*/
	/*scanf("%lf", &h);*/

	/*j = t / h;*/
	/*y = 1;*/

	/*for (i = 1; i <= j; i++) {*/
		/*y = function(h * i, y) * h + y;*/
		/*printf("h: %.5f      y: %.5f\n", h * i, y);*/
	/*}*/
	
	Queue que;
	
	printf("Write an equation: ");
	que = inputFunction();

	while (!q_isEmpty(que)) {
		printf("%c", q_remove(que));
	}
	printf("\n");

	q_destroy(que);

	return 0;
}

Queue inputFunction(void)
{
	Stack operator = s_create();
	Queue input = q_create();
	Queue output = q_create();

	char c;

	int new_value;
	int old_value;
	int i;

	struct symbol new_sym;
	struct symbol old_sym;

	while ((c = getchar()) != '\n') {
		q_add(input, c);
	}

	while (!q_isEmpty(input)) {
		new_value = q_remove(input);
		if (new_value >= '0' && new_value <= '9') {
			q_add(output, new_value);
		} else {
			if (!s_isEmpty(operator)) {
				old_value = s_pop(operator);
				for (i = 0; i < 4; i++) {
					if (operations[i].sym == new_value) {
						new_sym = operations[i];
					}
					if (operations[i].sym == old_value) {
						old_sym = operations[i];
					}
				}
				if ((new_sym.assoc == LEFT) && (new_sym.prec <= old_sym.prec)) {
					q_add(output, new_sym.sym);
				} else if ((new_sym.assoc == RIGHT) && (new_sym.prec < old_sym.prec)) {
					q_add(output, new_sym.sym);
				} else {
					s_push(operator, old_value);
				}
			}
			s_push(operator, new_value);
		}
	}

	while (!s_isEmpty(operator)) {
		q_add(output, s_pop(operator));
	}

	s_destroy(operator);
	q_destroy(input);

	return output;
}
		

double function(double t, double y)
{
	return 3 + t - y;
}
