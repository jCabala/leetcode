# Write your MySQL query statement below
SELECT DISTINCT
    CASE
        WHEN COUNT(DISTINCT salary) = 0 THEN null
        ELSE salary
    END
AS SecondHighestSalary
FROM Employee EMP
WHERE (
    SELECT COUNT(DISTINCT salary)
    FROM Employee
    WHERE salary > EMP.salary
) = 1