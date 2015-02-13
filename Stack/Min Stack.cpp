/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/


class MinStack {
	stack<int> minStack;
	stack<int> sStack;
public:
	void push(int x) {
		sStack.push(x);
		if (!minStack.empty())
		{
			if (minStack.top() >= x)
			{
				minStack.push(x);
			}
		}
		else
			minStack.push(x);
	}

	void pop() {
		if (sStack.top() <= minStack.top())
		{
			minStack.pop();
		}
		sStack.pop();
	}

	int top() {
		return  sStack.top();
	}

	int getMin() {
		return minStack.top();

	}
};