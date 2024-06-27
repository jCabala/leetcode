# Write your MySQL query statement below
SELECT MAX(MN1.num) AS num
FROM MyNumbers MN1
WHERE (
    SELECT COUNT(MN2.num)
    FROM MyNumbers MN2
    WHERE MN1.num = MN2.num
) = 1