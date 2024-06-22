# Write your MySQL query statement below
SELECT query_name,
ROUND(AVG(rating / position), 2) AS quality,
ROUND((SELECT COUNT(query_name) 
       FROM Queries Q2 
       WHERE rating < 3 
       AND Q1.query_name = Q2.query_name) * 100 / COUNT(query_name) ,2)
AS poor_query_percentage
FROM Queries Q1
WHERE Q1.query_name IS NOT NULL
GROUP BY query_name