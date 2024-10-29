class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        db = [[0 for i in range(len(text1))] for j in range(len(text2))]

        db[0][0] = 1 if text1[0] == text2[0] else 0 

        for j in range(1, len(text1)):
            if text1[j] == text2[0]:
                db[0][j] = 1
            else:
                db[0][j] = db[0][j-1]

        for i in range(1, len(text2)):
            if text1[0] == text2[i]:
                db[i][0] = 1
            else:
                db[i][0] = db[i-1][0]

        for j in range(1, len(text1)):
            for i in range(1, len(text2)):
                if text1[j] == text2[i]:
                    db[i][j] = 1+ db[i-1][j-1]
                else:
                    db[i][j] = max(db[i-1][j], db[i][j-1])
        return db[len(text2)-1][len(text1)-1]
        print(db)