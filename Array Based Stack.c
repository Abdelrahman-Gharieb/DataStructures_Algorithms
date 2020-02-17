
#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX 5

typedef enum {
	PUSH_NOK,
	PUSH_OK
}_ret_push;

typedef enum {
	POP_NOK,
	POP_OK
}_ret_pop;

int stack_arr[STACK_MAX];
int stack_pointer = -1;

bool is_full();
bool is_empty();
int get_top(void);
_ret_push push_element(int element);
_ret_pop pop_element();
void print_full_stack(void);

int main() {
	get_top();
	print_full_stack();
	push_element(11);
	push_element(22);
	push_element(33);
	push_element(44);
	push_element(55);
	print_full_stack();
	
	pop_element();
	get_top();
	pop_element();
	print_full_stack();
	pop_element();
	print_full_stack();
	pop_element();
	print_full_stack();
	pop_element();
	print_full_stack();
	return 0;
}

bool is_full() {
	if (stack_pointer == STACK_MAX - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool is_empty() {
	if (stack_pointer == - 1) {
		return true;
	}
	else {
		return false;
	}
}

int get_top(void) {
	if (is_empty()) {
		printf("Stack is Empty \a\n");
	}
	else {
		return stack_arr[stack_pointer];
	}
}


_ret_push push_element(int element) {
	if (is_full()) {
		printf("Stack is Full\a\n");
		return PUSH_NOK;
	}
	else {
		stack_pointer += 1;
		stack_arr[stack_pointer] = element;
		return PUSH_OK;
	}
}

_ret_pop pop_element(){
	int _buffer = 0;
	if (is_empty()) {
		printf("Stack is Empty \a\n");
		return POP_NOK;
	}
	else {
		_buffer = stack_arr[stack_pointer];
		stack_pointer--;
		return _buffer;
	}
}

void print_full_stack(void) {
	int l_stack_pointer = stack_pointer;
	if (is_empty()) {
		printf("Stack is Empty \a\n");
	}
	else {
		printf("Stack Data : ");
		for (l_stack_pointer = stack_pointer; l_stack_pointer >= 0; l_stack_pointer--) {
			printf("%i\t", stack_arr[l_stack_pointer]);
		}
		printf("\n");
	}
}