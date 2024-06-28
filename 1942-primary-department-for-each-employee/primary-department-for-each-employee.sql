SELECT employee_id, department_id
FROM Employee EMP
WHERE  primary_flag = 'Y'
OR (
    SELECT COUNT(employee_id) 
    FROM Employee EMP2
    WHERE EMP2.employee_id = EMP.employee_id
    ) = 1
GROUP BY employee_id