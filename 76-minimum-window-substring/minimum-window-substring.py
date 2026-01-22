class Window:
    def __init__(self, target: str, word: str):
        self.counter = 0                  # how many required character *instances* we have matched
        self.targ_len = len(target)       # total required instances (with repetition)
        self.word = word

        self.window = {}
        self.target_map = {}
        self.left = 0
        self.right = 0                   # right is EXCLUSIVE

        for c in target:
            self.target_map[c] = self.target_map.get(c, 0) + 1

    def push(self):
        """Extend window by 1 on the right."""
        c = self.word[self.right]
        self.right += 1

        if c not in self.target_map:
            return

        self.window[c] = self.window.get(c, 0) + 1

        # repetition-counting: count each required instance once
        if self.window[c] <= self.target_map[c]:
            self.counter += 1

    def pop(self):
        """Shrink window by 1 on the left."""
        if self.left == self.right:
            raise Exception("Can't remove from empty window!")

        c = self.word[self.left]
        self.left += 1

        if c not in self.target_map:
            return

        # If this character was contributing to the matched-required-instances,
        # removing it will reduce counter.
        if self.window.get(c, 0) <= self.target_map[c]:
            self.counter -= 1

        self.window[c] -= 1

    def check(self) -> bool:
        return self.counter == self.targ_len

    def length(self) -> int:
        # right is exclusive
        return self.right - self.left

    def substr(self) -> str:
        return self.word[self.left:self.right]


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s or len(t) > len(s):
            return ""

        window = Window(t, s)

        best_len = float("inf")
        best_l = 0
        best_r = 0

        # Expand right, then shrink left as much as possible while still valid.
        while window.right < len(s):
            window.push()

            while window.check():
                if window.length() < best_len:
                    best_len = window.length()
                    best_l = window.left
                    best_r = window.right

                window.pop()

        return "" if best_len == float("inf") else s[best_l:best_r]
