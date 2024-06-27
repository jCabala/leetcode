SELECT class
FROM Courses C1
WHERE (
    SELECT COUNT(DISTINCT student)
    FROM Courses C2
    WHERE C1.class = C2.class
) >= 5
GROUP BY class