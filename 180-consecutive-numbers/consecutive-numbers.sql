SELECT num AS ConsecutiveNums
FROM Logs LG
WHERE (LG.num, LG.num) IN (
    SELECT LG2.num, LG3.num
    FROM Logs LG2, Logs LG3
    WHERE LG2.id = LG.id + 1
    AND LG3.id = LG.id + 2)
GROUP BY num