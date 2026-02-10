First implment a stack if in python using a class method or if done in c using the struct 

example :

```
class stack :
    def __init__(self):
        self.stack = []
        self.size = int(len(self.stack))
        self.top = -1
    def push(self,element):
        self.stack.append(element)
        self.top += 1

    def pop(self):
        if self.top == -1:
            return None

        removed_element = self.stack[self.top]
        self.stack = self.stack[:self.top]
        self.top -= 1
        return removed_element
    def peek(self):
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1
```
* **Map Closing Brackets:** Create a dictionary (map) named `endmap` that maps each closing bracket to its opening counterpart.
* **Iterate Through Expression:** Use a `for` loop to check each character `c` in the given expression.
* **Push Opening Brackets:** If `c` is an opening bracket, push it onto the stack.
* **Validate Closing Brackets:** If `c` is a closing bracket:
    * Check if the stack is empty (returns `False` if empty).
    * Pop the stack and check if the popped element matches the `endmap` value for `c`.
* **Final Mismatch Check:** Return `False` if the brackets do not match.

```
def evaluate(expression):
    string = stack()
    endmap = {")": "(", "]": "[", "}": "{"}
    for c in expression:
        if c == "(" or c == "[" or c == "{" :
            string.push(c)
        elif c == ")" or c == "]" or c == "}" :
            if string.is_empty() :
                return False
            if string.pop() != endmap[c]:
                return False
```


