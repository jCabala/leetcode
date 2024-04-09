# Write your MySQL query statement below
SELECT unique_id, name
FROM Employees em 
LEFT JOIN EmployeeUNI emId
ON em.id = emId.id