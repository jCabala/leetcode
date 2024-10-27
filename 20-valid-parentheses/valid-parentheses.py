class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = deque()
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if not self.isClosing(top, c):
                    return False
        return not stack

    def isClosing(self, open, close):
        if open == '[':
            return close == ']'
        elif open == '(':
            return close == ')'
        else:
            return close == '}'